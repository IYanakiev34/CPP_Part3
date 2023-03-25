%filenames parser
%scanner ../Scanner/scanner.h
%token-path tokens.h
%namespace tn

%token NUMBER

%left NOTEQ
%left '+'
%left '*'
%right '^'
%right UMINUS

%%

expr:
        NUMBER
    |
        '-' expr %prec UMINUS
    |
        expr '+' expr
    |
        expr '*' expr
    |
        expr '^' expr
    |
        expr NOTEQ expr
    ;