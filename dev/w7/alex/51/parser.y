%scanner scanner.h
%filenames parser
%token-path tokens.h

%token NUMBER

%left '+' '-'

%%

expr
    : NUMBER
    | expr '+' expr
    | expr '-' expr
    ;
