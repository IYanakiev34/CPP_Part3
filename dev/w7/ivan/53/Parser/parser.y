%filenames parser
%scanner ../Scanner/scanner.h
%token-path tokens.h
%namespace tn
%print-tokens

%token IDENT NUMBER
%left '+'
%left '*'
%right '-'

%%

expr:
        NUMBER
    |
        IDENT index
    |
        '-' expr
    |
        expr '+' expr '\n'
    |
        expr '*' expr
    ;

index:
        index '[' NUMBER ']'
    |
    ;
    