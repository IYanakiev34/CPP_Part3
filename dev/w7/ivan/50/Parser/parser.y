%scanner ../Scanner/scanner.h
%namespace tn
%filenames parser
%token-path tokens.h

%token NUMBER

%left '-' '+'
%left '*' '/'
%right '$'
%right UMINUS

%%

expr:
    expr '+' expr
    |
    expr '-' expr
    |
    expr '*' expr 
    |
    expr '/' expr
    |
    '$' expr 
    | 
    '(' expr ')'
    |
    '-' expr %prec UMINUS
    | NUMBER
    ;
    