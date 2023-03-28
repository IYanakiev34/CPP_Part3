%scanner scanner.h
%filenames parser
%token-path tokens.h

%token VAR NR

%left '+'
%left '*'
%right '-'
%left '['

%%

expr
    : NR
    | VAR
    | expr '+' expr
    | expr '*' expr
    | '-' expr
    | expr '[' expr ']'
    ;
