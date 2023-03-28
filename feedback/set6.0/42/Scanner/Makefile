#!/usr/bin/make

# So one can say: make help
define HELP_TEXT =

This Makefile is suitable for building small C++ projects.
It requires very little extra configuration.
It assumes a GNU C++ compiler, and GNU Make:
[Make manual](https://www.gnu.org/software/make/manual/)
It was written for Linux, but has been reported to work on Macs and under
MinGW64. It does not seem to break when make is told to run parallel jobs.

## Most basic use:

Put Makefile and sources in one directory and there issue the command:

    make

To remove all the generated files (which should seldom be necessary):

    make clean

## Default behavior:

The Makefile causes `make` to want to build programs, or if there
are no program sources, to build a convenience library. To do so, the
following steps are taken.

* Flexc++ will be called on any scanner specification files.
* Bisonc++ will be called on any parser specification files (grammars).
* C++ source files and internal headers will be preprocessed in order to
  determine their include dependencies.
  [internal headers explained](https://stackoverflow.com/questions/11063355/is-anyone-familiar-with-the-implementation-internal-header-ih)
* If included anywhere, C++ internal header files will be precompiled.
* C++ source files will be compiled into object files.
* A convenience library will be composed of all non-program object files.
* Program object files (detected by grepping the source for a `main`
  function) will be linked against the convenience library to become
  executable programs.

Because the Makefile detects which files include which others, updating a
header file will cause all source files that (indirectly) include it to be
remade. On one hand, this consumes time. On the other hand it saves time by
keeping sources and headers in sync, so `make clean` should seldom have to be
run.

## Influencing the Makefile:

The Makefile accepts the usual variables (CXX, CXXFLAGS, CPPFLAGS,
LDFLAGS etc.) as well as FLEXCXX (defaults to: $(FLEXCXX)) and BISONCXX
(defaults to: $(BISONCXX)) These can be set in the usual ways:
[How variables get their values](https://www.gnu.org/software/make/manual/html_node/Values.html#Values)

They can also be set in a file `hooks.mk`, which if it exists, will be
included. Extensions can be set there too, though it should seldom be
necessary, as they auto-adapt to files found.

    CXX_SOURCE_EXTENSION (defaults to: $(CXX_SOURCE_EXTENSION))
    CXX_HEADER_EXTENSION (defaults to: $(CXX_HEADER_EXTENSION))
    CXX_INTERNAL_HEADER_EXTENSION (defaults to: $(CXX_INTERNAL_HEADER_EXTENSION))
    FLEXCXX_SCANNERSPEC_EXTENSION (defaults to: $(FLEXCXX_SCANNERSPEC_EXTENSION))
    BISONCXX_PARSERSPEC_EXTENSION (defaults to: $(BISONCXX_PARSERSPEC_EXTENSION))

When setting extensions, do NOT include the dot in the extension!
DEPDIR (defaults to: $(DEPDIR)) can also be set but is best left alone.

Some variables change the behaviour more extensively:

    VERBOSE=yes causes commands in recipes to be echoed.
    DEP=no      causes dependency analysis to be skipped.
    PCH=no      prevents precompiled headers from being built,
                but not necessarily from being used if they exist.

Note that without analyzing dependencies, Make will not know which
source file includes which internal header, so it will not create or
update precompiled headers.

## Creating files from templates:

Some files can be created from templates integrated in this Makefile.
E.g.:

    mkdir mc
    make mc/myclass.hh
    make mc/myclass.ih
    make mc/ctor1.cc
    mkdir parser
    make parser/grammar.bc++
    make parser/tokenizer.fc++
    make myprog.cc:program

The command for creating a program source differs because it shares its
file extension with non-program sources.
To make header files, the `uuid` utility must be present.
It is convenient to create the header first, because the template for the
internal header will subsequently find and include it. The template for
source files will find the internal header in turn.


endef

# Recursive wildcard to find all files in the current directory and subdirs.
# Using a $(shell find...) would also work, but depend on the find utility.
rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

# Simply list all files we can find.
ALL_FILES := $(patsubst ./%,%,$(call rwildcard,.,*))

# We recognize files by their extensions, because file magic doesn't always
# work to distinguish C++ from C.

# Autodetection of file extensions.
first_extension_found = $(patsubst .%,%,$(or $(firstword $(foreach X,$1,$(filter %.$X,$(suffix $(ALL_FILES))))),$(firstword $1)))

CXXFLAGS += -Wall -std=c++20
#LDFLAGS += -lrt -ldl -lpthread -lm -lz -ltinfo

# The file hooks.mk will be included if it exists.
# You could put project-specific settings there.
-include hooks.mk

# Extensions can be set here, or in the environment:
# https://www.gnu.org/software/make/manual/html_node/Environment.html#Environment
CXX_SOURCE_EXTENSION ?= $(call first_extension_found, cc cpp cxx c++ C)
# Some use h
CXX_HEADER_EXTENSION ?= $(call first_extension_found, hh hpp hxx h++ H h)
CXX_INTERNAL_HEADER_EXTENSION ?= $(call first_extension_found, ihh ihpp ihxx ih++ IH ih)
CXX_PCH_EXTENSION ?= $(CXX_INTERNAL_HEADER_EXTENSION).gch
CXX_OBJECT_EXTENSION ?= $(CXX_SOURCE_EXTENSION).o
DEP_EXTENSION ?= dep

FLEXCXX_SCANNERSPEC_EXTENSION ?= $(call first_extension_found, fc++ fcpp fcxx flexc++ flexcpp flexcxx )
BISONCXX_PARSERSPEC_EXTENSION ?= $(call first_extension_found, bc++ bcpp bcxx bisonc++ bisoncpp bisoncxx )

# By default, this Makefile does not echo recipe commands. But it can.
# Try: 'make VERBOSE=1'
VERBOSE ?= false

# We use precompiled headers by default. But they can be turned off.
# Try: make PCH=no
PCH ?= true

# We analyze and heed generated dependencies by default. But they can be
# turned off. Try: make DEP=no
DEP ?= true

# The name of our convenience library.
CONVLIB = $(notdir $(CURDIR))
CONVLIB_EXTENSION = a
CONVLIB_FILE = lib$(CONVLIB).$(CONVLIB_EXTENSION)

# Directory where dependencies are stored.
DEPDIR ?= generated_deps

FLEXCXX ?= flexc++
BISONCXX ?= bisonc++

## No editing below this line unless you know what you're doing. ##

# This Makefile requires GNU Make.
DETECTED_MAKEVERSION = $(shell make --version)
ifneq ($(firstword $(filter GNU,$(DETECTED_MAKEVERSION))),GNU)
    $(error This Makefile requires GNU Make. Detected: $(DETECTED_MAKEVERSION))
endif
undefine DETECTED_MAKEVERSION

# Use any of these words to indicate true or false.
boolalpha = $(or \
   $(if $(filter $(1),t true  True  TRUE  yes Yes YES YESS! on  On  ON  one  One  ONE  1),true,),\
   $(if $(filter $(1),f false False FALSE no  No  NO  NOO!  off Off OFF zero Zero ZERO 0),false,),\
   $(if $(strip $(1)),,false),\
   $(error cannot interpret $(1) as boolean)\
)

# NEWLINE is for use with printf, which is more reliable than echo.
define NEWLINE


endef
#SP is for alignments

USE_PRECOMPILED_HEADERS := $(call boolalpha,$(PCH))
undefine PCH

USE_GENERATED_DEPENDENCIES := $(call boolalpha,$(DEP))
undefine DEP

# QUIET is a '@', unless VERBOSE is true.
QUIET := $(if $(filter true,$(call boolalpha,$(VERBOSE))),,@)
undefine VERBOSE

# Acts as 'dir', but may return the empty string instead of './'
maybe_dir=$(filter-out ./,$(dir $1))

# On e.g. foo/bar/baz returns foo/bar/ foo/
rdir=$(foreach d,$(call maybe_dir,$1),$d $(call rdir,$(patsubst %/,%,$d)))

# Reverses a word list, to list deepest directories first after sort.
reverse=$(if $(wordlist 2,2,$(1)),$(call reverse,$(wordlist 2,$(words $(1)),$(1))) $(firstword $(1)),$(1))

# Useful to remove a tree of empty dirs, recursively:
# Lists dirs recursively, deepest first, with no duplicates.
rdirs=$(call reverse,$(sort $(foreach dir,$1,$(call rdir,$(dir)))))

deps_of = $(addprefix $(DEPDIR)/,$(addsuffix .$(DEP_EXTENSION),$(1)))

# Anything with a CXX_SOURCE_EXTENSION is a C++ source file.
CXX_SOURCES := $(filter %.$(CXX_SOURCE_EXTENSION),$(ALL_FILES))

# Get object names by replacing the extension.
CXX_OBJECTS := $(CXX_SOURCES:%.$(CXX_SOURCE_EXTENSION)=%.$(CXX_OBJECT_EXTENSION))
CXX_SOURCE_DEPS := $(call deps_of,$(CXX_SOURCES))

# To detect a main() function in a source file.
# Not bulletproof, but KISS.
MAIN_REGEX := int[[:space:]]+main[[:space:]]*\(

# Anything that mentions a main function is a program source.
CXX_PROG_SOURCES := $(if $(CXX_SOURCES),$(shell grep -El '$(MAIN_REGEX)' $(CXX_SOURCES)))
CXX_PROG_OBJECTS := $(patsubst %.$(CXX_SOURCE_EXTENSION),%.$(CXX_OBJECT_EXTENSION),$(CXX_PROG_SOURCES))
CXX_PROGS := $(CXX_PROG_SOURCES:%.$(CXX_SOURCE_EXTENSION)=%)
CXX_TESTPROGS := $(filter tests/%,$(CXX_PROGS))

# Sources that aren't program sources, are non-program sources.
CXX_NONPROG_SOURCES := $(filter-out $(CXX_PROG_SOURCES),$(CXX_SOURCES))
CXX_NONPROG_OBJECTS := $(CXX_NONPROG_SOURCES:%.$(CXX_SOURCE_EXTENSION)=%.$(CXX_OBJECT_EXTENSION))

CXX_INTERNAL_HEADERS := $(filter %.$(CXX_INTERNAL_HEADER_EXTENSION),$(ALL_FILES))

# From every internal header we can build a precompiled (internal) header.
CXX_PRECOMPILED_HEADERS := $(CXX_INTERNAL_HEADERS:%=%.gch)
CXX_PCH_DEPS := $(call deps_of,$(CXX_INTERNAL_HEADERS))

FLEXCXX_SCANNERSPECS := $(filter %.$(FLEXCXX_SCANNERSPEC_EXTENSION),$(ALL_FILES))
FLEXCXX_DEPS := $(call deps_of,$(FLEXCXX_SCANNERSPECS))

BISONCXX_PARSERSPECS := $(filter %.$(BISONCXX_PARSERSPEC_EXTENSION),$(ALL_FILES))
BISONCXX_DEPS := $(call deps_of,$(BISONCXX_PARSERSPECS))

###

ALL_DEPS = $(CXX_SOURCE_DEPS) $(CXX_PCH_DEPS) $(FLEXCXX_DEPS) $(BISONCXX_DEPS)

# Could be used to suppress all built-in rules.
.SUFFIXES:

# Suppress making .o from .cc, because we only want to create .cc.o
%.o: %.$(CXX_SOURCE_EXTENSION)

###

# Default target: to make all programs, or at least the convenience library.
all: $(CXX_PROGS) $(if $(CXX_NONPROG_SOURCES),$(CONVLIB_FILE))

# Assumption: all programs need the convenience library.
$(CXX_PROGS): $(CONVLIB_FILE)

# To create an executable program is called: 'Linking'.
$(CXX_PROGS): METHOD = Link       
$(CXX_PROGS): LDFLAGS += -L. -l$(CONVLIB)

$(CXX_OBJECTS): METHOD = Compile    
$(CXX_OBJECTS): INPUTS = $(filter %.$(CXX_SOURCE_EXTENSION),$^)
$(CXX_OBJECTS): CXXFLAGS += -c

$(CONVLIB_FILE): METHOD = Collect    

$(CXX_PRECOMPILED_HEADERS): METHOD = Pre-compile
$(CXX_PRECOMPILED_HEADERS): INPUTS = $(filter %.$(CXX_INTERNAL_HEADER_EXTENSION),$^)

# When compiling a precompiled header, specify that it's a header.
$(CXX_PRECOMPILED_HEADERS): CXXFLAGS += -x c++-header

# When a source file is deleted, the object files may linger. Let Make warn then.
GENERATED_EXTENSIONS = $(CXX_OBJECT_EXTENSION) $(CONVLIB_EXTENSION) $(CXX_PCH_EXTENSION) $(DEP_EXTENSION)
#$(info generated extensions: $(GENERATED_EXTENSIONS))
KNOWN_GENERATED_FILES = $(CONVLIB_FILE) $(CXX_OBJECTS) $(CXX_PRECOMPILED_HEADERS) $(ALL_DEPS)
#$(info known generated: $(KNOWN_GENERATED_FILES))
EVER_GENERATED_FILES = $(filter $(addprefix %.,$(GENERATED_EXTENSIONS)),$(ALL_FILES))
#$(info ever generated: $(EVER_GENERATED_FILES))
UNKNOWN_GENERATED_FILES = $(filter-out $(KNOWN_GENERATED_FILES),$(EVER_GENERATED_FILES))
#$(info unknown generated: $(UNKNOWN_GENERATED_FILES))
ifneq (,$(UNKNOWN_GENERATED_FILES))
    $(warning $(NEWLINE)Warning: Make may once have generated, but cannot update any more the following files:$(NEWLINE)$(NEWLINE)  $(UNKNOWN_GENERATED_FILES)$(NEWLINE)$(NEWLINE)Perhaps their sources do not exist any more. Consider cleaning them up.)
endif

# Action tells whether we're updating or creating.
ACTION = $(if $(filter $@,$(ALL_FILES)),->,=>)
# This output usually shows instead of the actual command.
ECHO_ACTION = @echo "    [ $(METHOD)  $(or $(INPUTS),$^)\t$(ACTION)\t$(or $(TARGET),$@)\t]"

# A rule says two things:
# 1. To build any of the target, i.e. $(CONVLIB_FILE),
#    we need the prerequisites, i.e. $(CXX_NONPROG_OBJECTS)
# 2. If any of the preprequisites are newer than the target,
#    we need to rebuild the target.
$(CONVLIB_FILE): $(CXX_NONPROG_OBJECTS)
	$(ECHO_ACTION)
	$(QUIET) $(AR) rcs $@ $^
# In the recipe of the rule,
# $@ is the target, i.e. $(CONVLIB_FILE)
# $^ is the list of preprequisites, i.e. $(CXX_NONPROG_OBJECTS)

# We don't archive object files member my member, because
# 1. the member is a transient prerequisite that causes remakes,
# 2. allegedly it's slow on large projects,
# 3. the individual archiving actions clutter our output,
# 4. it won't work with parallel Make.

# If any program object file is newer than the program itself,
# we rebuild the program, by linking the object file against the convenience library.
$(CXX_PROGS): %: %.$(CXX_OBJECT_EXTENSION)
	$(ECHO_ACTION)
	$(QUIET) $(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

# If the source is newer than its object, we compile it.
$(CXX_OBJECTS): %.$(CXX_OBJECT_EXTENSION): %.$(CXX_SOURCE_EXTENSION)
	$(ECHO_ACTION)
	$(QUIET) $(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

# Clean everything except the programs.
mostlyclean:
	$(QUIET) rm -f $(CXX_PRECOMPILED_HEADERS) $(CXX_OBJECTS) $(CONVLIB_FILE)

# Remove everything Make created.
clean: mostlyclean
	$(QUIET) rm -f $(CXX_PROGS)

# Even if a file 'clean' exists, 'make clean' keeps working.
.PHONY: all clean mostlyclean test help

# Don't create unless needed:
.INTERMEDIATE: $(CXX_OBJECTS) $(CXX_PRECOMPILED_HEADERS)

# Once created, don't delete unless by make clean.
.SECONDARY: $(CXX_PRECOMPILED_HEADERS) $(CXX_OBJECTS)

# Any files created by failed recipes should be deleted.
.DELETE_ON_ERROR:

help:
	@printf '$(subst $(NEWLINE),\n,$(HELP_TEXT))'

# Give Make no way to make hooks.mk. User has to create it.
hooks.mk:

###  Below follow some templates that will create source and header files. ###

# The program source template shares its suffix with other sources.
# So we use this trick: 'make foo.cc:program' will create a program 'foo.cc'.

# Add proper extension if there was none, and remove e.g. ':program'.
ACTUAL_FILE = $(addsuffix .$(EXTENSION),$(patsubst %.$(EXTENSION),%,$*))

%\:program: TEMPLATE = $(CXX_PROGRAM_TEMPLATE)
%\:program: EXTENSION = $(CXX_SOURCE_EXTENSION)

%\:program:
	$(QUIET) if test -e "$(ACTUAL_FILE)" ; then echo "$(ACTUAL_FILE) already exists." ; false ; fi
	$(QUIET) printf '$(subst $(NEWLINE),\n,$(TEMPLATE))' >> "$(ACTUAL_FILE)" && echo "$(ACTUAL_FILE) made from template"

# Not used. Using just extensions is shorter.
#%\:cxx_class: %\:cxx_header %\:cxx_internal_header

# Only files that are explictly mentioned on the command line and that don't
#exist yet, can be created. Use like: make bar.hh

# Header template. We use a UUID to keep the header guard unique.
define CXX_HEADER_TEMPLATE
#ifndef def_$(UUID)_$(HID)_$(CXX_HEADER_EXTENSION)
#define def_$(UUID)_$(HID)_$(CXX_HEADER_EXTENSION)
#endif //def_$(UUID)_$(HID)_$(CXX_HEADER_EXTENSION)\n
endef


# To detect (internal) headers that already exist in the dir.
include-headers-in-same-dir = $(foreach HEADER,$(wildcard $(@D)/*.$(CXX_HEADER_EXTENSION)),#include "$(notdir $(HEADER))"\n)
include-internal-headers-in-same-dir = $(foreach IHEADER,$(wildcard $(@D)/*.$(CXX_INTERNAL_HEADER_EXTENSION)),#include "$(notdir $(IHEADER))"\n)

# INternal header template.
define CXX_INTERNAL_HEADER_TEMPLATE
$(include-headers-in-same-dir)

using namespace std;\n
endef

# Ordinary source template
define CXX_SOURCE_TEMPLATE
$(include-internal-headers-in-same-dir)


endef

# Program template
define CXX_PROGRAM_TEMPLATE
int main(int argc, char **argv)
try
{
}
catch (...)
{
    return 0;
}
endef

# Scanner (tokenizer) specification template.
define FLEXCXX_SCANNERSPEC_TEMPLATE

//%%baseclass-header = "filename"
//%%case-insensitive
//%%class-header = "filename"
//%%class-name = "className"
//%%debug
//%%filenames = "basename"
//%%implementation-header = "filename"
//%%input-implementation = "sourcefile"
//%%input-interface = "interface"
//%%interactive
//%%lex-function-name = "funname"
//%%lex-source = "filename"
//%%no-lines
//%%namespace = "identifer"
//%%print-tokens
//%%s start-conditions
//%%skeleton-directory = "pathname"
//%%startcondition-name = "startconditionName"
//%%target-directory = "pathname"
//%%x miniscanners

%%%%

.|\\n   return 0x100;

endef

# Parser specification (grammar) template:
define BISONCXX_PARSERSPEC_TEMPLATE
//  With multiple parsers in one project, give each one its own namespace.
// %%namespace pns

// %%baseclass-preinclude: specifying a header included by the baseclass
// %%class-name: defining the name of the parser class
// %%debug: adding debugging code to the parse() member

//  Flexc++-generated default. Adjust to needs.
%%scanner Scanner.h

// %%baseclass-header: defining the parser base class header
// %%class-header: defining the parser class header
// %%filenames: specifying a generic filename
// %%implementation-header: defining the implementation header
// %%parsefun-source: defining the parse() function sourcefile
// %%target-directory: defining the directory where files must be written
// %%token-path: defining the path of the file containing the Tokens_ enumeration

// %%polymorphic INT: int; STRING: std::string; 
//               VECT: std::vector<double>

%%token TERMINAL

%%%%

nonterminal:
TERMINAL
;

endef

# Giving Make a recipe to create any file 'foo.cc' from thin air is dangerous,
# because it would do so whenever it needs a file 'foo'. So we allow it to
# create only files that are explicitly mentioned on the command line, and
# then only if they don't exist yet.
NONEXISTENT_GOALS = $(filter-out $(ALL_FILES),$(MAKECMDGOALS))
TEMPLATES = $(filter %_TEMPLATE,$(.VARIABLES))
TEMPLATE_TYPES = $(patsubst %_TEMPLATE,%,$(TEMPLATES))
TEMPLATABLE_EXTENSIONS = $(foreach TTYPE,$(TEMPLATE_TYPES),$($(TTYPE)_EXTENSION))
TEMPLATABLE_GOALS = $(foreach EXTENSION,$(TEMPLATABLE_EXTENSIONS),$(filter %.$(EXTENSION),$(MAKECMDGOALS)))

# Templatable goals can be made from a template, and are by definition nonexistent.
ifneq (,$(TEMPLATABLE_GOALS))

    %.$(CXX_SOURCE_EXTENSION): TEMPLATE = $(CXX_SOURCE_TEMPLATE)
    %.$(CXX_INTERNAL_HEADER_EXTENSION): TEMPLATE = $(CXX_INTERNAL_HEADER_TEMPLATE)
    %.$(CXX_HEADER_EXTENSION): TEMPLATE = $(CXX_HEADER_TEMPLATE)
    %.$(CXX_HEADER_EXTENSION): UUID := $(subst -,_,$(shell uuid))
    %.$(CXX_HEADER_EXTENSION): HID = $(basename $(notdir $@))
    %.$(FLEXCXX_SCANNERSPEC_EXTENSION): TEMPLATE = $(FLEXCXX_SCANNERSPEC_TEMPLATE)
    %.$(BISONCXX_PARSERSPEC_EXTENSION): TEMPLATE = $(BISONCXX_PARSERSPEC_TEMPLATE)

    $(TEMPLATABLE_GOALS):
	printf '$(subst $(NEWLINE),\n,$(TEMPLATE))' >> $@

endif

# Generated dependencies are enabled by default. To suppress: make DEP=no
ifeq ($(USE_GENERATED_DEPENDENCIES),true)

    # Make can be told to include generated dependency files.
    # But it cannot be told to include such dependencies only for sources that
    # actually must be compiled. So we simply always include all dependencies.
    # (With C++ Modules, we'll need to anyway.)

    # Prevent dependency generation if MAKECMDGOALS is non-empty and consists
    # only of targets that don't need dependencies.
    TARGETS_THAT_DONT_NEED_DEPS := clean mostlyclean depclean help $(TEMPLATABLE_GOALS)
    MAKECMDGOALS_IS_EMPTY := $(if $(MAKECMDGOALS),,yes)
    GOALS_THAT_NEED_DEPS := $(strip $(filter-out $(TARGETS_THAT_DONT_NEED_DEPS),$(MAKECMDGOALS)))
    NEED_DEP_INCLUDES := $(or $(MAKECMDGOALS_IS_EMPTY),$(GOALS_THAT_NEED_DEPS))

    # When only e.g. cleaning, we don't need dependencies.
    ifneq (,$(NEED_DEP_INCLUDES))
        include $(ALL_DEPS)
    endif

    undefine TARGETS_THAT_DONT_NEED_DEPS
    undefine MAKECMDGOALS_IS_EMPTY
    undefine GOALS_THAT_NEED_DEPS
    undefine NEED_DEP_INCLUDES

    $(CXX_SOURCE_DEPS) $(CXX_PCH_DEPS): METHOD = Analyze    
    # These are flags for generating dependencies.
    $(CXX_SOURCE_DEPS): CPPFLAGS += -E -fdirectives-only -MQ $(patsubst %.$(CXX_SOURCE_EXTENSION),%.$(CXX_OBJECT_EXTENSION),$<) -MM -MF $@
    $(CXX_PCH_DEPS): CPPFLAGS += -E -fdirectives-only -MQ $(patsubst %.$(CXX_INTERNAL_HEADER_EXTENSION),%.$(CXX_PCH_EXTENSION),$<) -MM -MF $@
    $(CXX_PCH_DEPS): CXXFLAGS += -x c++-header

    # Meaning:
    #-MQ $@: Change target of rule.
    #-MM:    Output dependencies, not preprocessor output. Implies -E.
    #-MF Specify file to write dependencies to.

    # To create a .dep file from a source or internal header file.
    $(CXX_SOURCE_DEPS) $(CXX_PCH_DEPS): $(call deps_of,%): %
	$(QUIET) mkdir -p $(dir $@)
	$(ECHO_ACTION)
	$(QUIET) $(CXX) $(CPPFLAGS) $(CXXFLAGS) $<

    # Predicting which files flexc++ will generate from a given scanner
    # specification file is hard. So we simply keep a touchfile and rerun
    # flexc++ whenever the spec is newer.
    # We use --target-directory to put generated files in the same directory
    # as the specification file they were generated from.
    # This overrides any internal %target-directory directives.
    $(FLEXCXX_DEPS): METHOD = $(FLEXCXX)    
    $(FLEXCXX_DEPS): $(call deps_of,%): %
	$(ECHO_ACTION)
	$(QUIET) $(FLEXCXX) $(FLEXCXXFLAGS) --target-directory=$(or $(*D),.) $< 
	$(QUIET) mkdir -p $(dir $@)
	$(QUIET) touch $@

    # In contrast to flexc++, bisonc++ puts the generated files in the
    # directory of the parser specification by default. No options needed.
    $(BISONCXX_DEPS): METHOD = $(BISONCXX)   
    $(BISONCXX_DEPS): $(call deps_of,%): %
	$(ECHO_ACTION)
	$(QUIET) $(BISONCXX) $(BISONCXXFLAGS) $< 
	$(QUIET) mkdir -p $(dir $@)
	$(QUIET) touch $@
    # Note that both bisonc++ and flexc++ are run merely to update the empty
    # .dep file for inclusion. The files they generate are side effects. The
    # reason this works is because Make will update includes before handling
    # any other recipes.
    # FixMe: why does Make consistently update bisonc++ and flexc++ deps
    # before source deps?

    # Keep deps once we have them.
    .SECONDARY: $(ALL_DEPS)

    # When cleaning, we should get rid of the deps again.
    mostlyclean: depclean
    # An rm -rf is always dangerous.
    # So we remove the files first, then remove empty dirs only.
    depclean:
	$(QUIET) rm -f $(ALL_DEPS)
	$(QUIET) rm -fd $(call rdirs,$(ALL_DEPS))

    .PHONY: depclean

endif

### Some measures to help Parallel Make ( make --jobs n) ###

# Make does not canonicalize relative paths in generated dependencies. As a
# result it may want to make foo/../bar.ih.gch,
# which when simplified reads:      bar.ih.gch.
# With Parallel Make this more often turns out to be a problem. FixMe: why?
# To mitigate, we tell Make how to remove the /../ from paths:
define PATH_STRAIGHTENING_RECIPE
$(DIR)../%: $(patsubst ./%,%,$(dir $(DIR:%/=%))%)
	@echo "    [ Substituting \"$$<\" <- \"$$@\": same file by straightened path. ]"
endef

# Evaluating the path straightening recipe for all available dirs.
DIRECTORIES_FOUND = $(sort $(filter-out ./,$(dir $(ALL_FILES:./%=%))))
$(foreach DIR,$(DIRECTORIES_FOUND), $(eval $(PATH_STRAIGHTENING_RECIPE)))
#$(foreach DIR,$(DIRECTORIES_FOUND), $(info $(PATH_STRAIGHTENING_RECIPE)))

### End of Parallel Make measures. ###

# Postpone double expansion to as late as possible.
.SECONDEXPANSION:

# To work without precompiled headers:
# make PCH=no
ifeq ($(USE_PRECOMPILED_HEADERS),true)

    # Each internal header shall become a precompiled header.
    $(CXX_PRECOMPILED_HEADERS): %.$(CXX_PCH_EXTENSION): %.$(CXX_INTERNAL_HEADER_EXTENSION)
	$(ECHO_ACTION)
	$(QUIET) $(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

    # For each internal header in the prerequisites, add a precompiled header.
    # (Leaving the internal header in is simpler and doesn't hurt.)
    $(CXX_OBJECTS): $$(patsubst %.$(CXX_INTERNAL_HEADER_EXTENSION),%.$(CXX_PCH_EXTENSION),$$^)

endif
