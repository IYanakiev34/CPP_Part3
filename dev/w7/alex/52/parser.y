%scanner scanner.h
%filenames parser
%token-path tokens.h

%token NR INEQ

%left INEQ_PREC
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
    | expr INEQ expr %prec INEQ_PREC
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