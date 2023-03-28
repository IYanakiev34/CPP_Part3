%scanner scanner.h
%filenames parser
%token-path tokens.h

%token WRITE NUMBER IDENTIFIER

%%

Writes
    : Write Writes
    | /* empty */
    ;

Write
    : WRITE '(' OptionalParams ')'
    ;

OptionalParams
    : Params
    | /* empty */
    ;

Params
    : Param ',' Params
    | Param
    ;

Param
    : IDENTIFIER
    | NUMBER
    ;
