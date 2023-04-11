// Generated by Bisonc++ V6.04.03 on Fri, 15 Apr 2022 13:49:59 +0200

#ifndef Parser_h_included
#define Parser_h_included

// $insert baseclass
#include "parserbase.h"
// $insert scanner.h
#include "../Scanner/scanner.h"

#include <vector>
#include <unordered_map>
#include <string>

class Parser: public ParserBase
{
    // $insert scannerobject
    Scanner d_scanner;

    std::vector<double> d_value;
    std::unordered_map<std::string, unsigned> d_symtab;

    bool d_display;
        
    public:
        Parser(bool run);
        int parse();

    private:
                                        // called on (syntax) errors
        void error(char const *msg = "syntax error");    
        int lex();                      // returns the next token from the
                                        // lexical scanner. 
        void print();                   // use, e.g., d_token, d_loc
        void exceptionHandler(std::exception const &exc);

    // support functions for parse():
        void executeAction_(int ruleNr);
        void errorRecovery_();
        void nextCycle_();
        void nextToken_();
        void print_();

    // added functions for the calculator:

        void display(RuleValue &expr);
        void done();
        void prompt();

        RuleValue add(RuleValue &lvalue, RuleValue &rvalue) const;
        RuleValue &assign(RuleValue &lvalue, RuleValue &rvalue);
        RuleValue div(RuleValue &lvalue, RuleValue &rvalue) const;
        RuleValue mul(RuleValue &lvalue, RuleValue &rvalue) const;
        RuleValue negate(RuleValue &expr) const;
        RuleValue sub(RuleValue &lvalue, RuleValue &rvalue) const;
        RuleValue value();
        RuleValue variable();

        double valueOf(RuleValue const &expr) const;
};


#endif
