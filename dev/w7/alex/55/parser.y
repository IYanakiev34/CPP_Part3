%scanner scanner.h
%filenames parser
%token-path tokens.h

%token DOUBLE INTEGRAL NEWLINE

%%

start: prompt commands;

commands
    : commands command
    | command
    ;

prompt: { std::cout << "? "; };

command
    : NEWLINE { ACCEPT(); }
    | 'm' DOUBLE NEWLINE prompt
    | 's' DOUBLE NEWLINE prompt
    | score NEWLINE prompt
    ;

score
    : DOUBLE
    | DOUBLE INTEGRAL
    ;


