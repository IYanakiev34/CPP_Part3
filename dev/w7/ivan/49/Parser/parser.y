%scanner ../Scanner/scanner.h
%namespace tn
%filenames parser
%token-path tokens.h


%token WRITE IDENT NUMBER NEWLINE

%%
write:
    WRITE '(' args ')' NEWLINE write
    |
    ;

args:
        IDENT ',' args
    |   
        NUMBER ',' args
    |   IDENT
    |   NUMBER
    ;