%filenames parser
%namespace tn
%token-path tokens.h
%scanner ../Scanner/scanner.h

%token NUMBER

%left '+' '-'

%%

expr:
    |
        NUMBER
    |
        expr '+' expr
    |
        expr '-' expr
    ;
