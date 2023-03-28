%scanner scanner.h
%filenames parser
%token-path tokens.h

%token WORD

%%

optionalList
    : WORD list
    | /* empty */
    ;

list
    : ',' cSeparated
    | unseparated
    ;

cSeparated
    : WORD ',' cSeparated
    | WORD
    ;

unseparated
    : WORD unseparated
    | WORD
    ;
