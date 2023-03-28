%scanner scanner.h
%filenames parser
%token-path tokens.h

%token NR

%left INEQ
%left '+'
%left '*'
%left '^'
%right '-'

%%

expr
    : NR
    | '-' expr
    | expr '+' expr
    | expr '*' expr
    | expr '^' expr
    | expr INEQ expr
    ;

/* There's a second way:
ineq
    : expr INEQ expr
    ;
expr
    : term '+' expr
    | term
    ;
term
    : power '*' term
    | power
    ;
power
    : factor '^' power
    | factor
    ;
factor
    : NR
    | '-' factor
    ;
*/