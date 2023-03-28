%scanner scanner.h
%filenames parser
%token-path tokens.h

%token NUMBER OPERATION

%left '+' '-'
%left '*' '/'
%right UMINUS

%%

Expression
    : Expression '+' Expression
    | Expression '-' Expression
    | Expression '*' Expression
    | Expression '/' Expression
    | '-' Expression %prec UMINUS
    | OPERATION Expression %prec UMINUS
    | NUMBER
    | '(' Expression ')'
    ;
