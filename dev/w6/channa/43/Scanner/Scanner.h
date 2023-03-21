// Generated by Flexc++ V2.11.00 on Sun, 19 Mar 2023 13:19:04 +0100

#ifndef Scanner_H_INCLUDED_
#define Scanner_H_INCLUDED_

// $insert baseclass_h
#include "Scannerbase.h"

#include <stack>


// $insert classHead
class Scanner: public ScannerBase
{
                                        // The string contents before we entered
                                        // a multi-line comment
    std::string beforeML;
                                        // Whether the multi-line comment we are
                                        // in spans multiple lines
    bool newLineInML = false;

    enum
    {
      LINE = 256
    };

    std::stack<StartCondition_> d_scStack;

    public:
        explicit Scanner(std::istream &in = std::cin, std::ostream &out = std::cout, bool keepCwd = true);

        Scanner(std::string const &infile, std::string const &outfile, bool keepCwd = true);
        
        // $insert lexFunctionDecl
        int lex();
        using ScannerBase::push;
    private:
        int lex_();
        int executeAction_(size_t ruleNr);

        void print();
        void preCode();     // re-implement this function for code that must 
                            // be exec'ed before the patternmatching starts

        void postCode(PostEnum_ type);    
                            // re-implement this function for code that must 
                            // be exec'ed after the rules's actions.

                            // Pushes the state we are in into a stack and
                            // starts next as the current state.
        void push(StartCondition_ next);
                            // Starts the state that is at the top of the state
                            // stack
        void popStartCondition();
};

// $insert scannerConstructors
inline Scanner::Scanner(std::istream &in, std::ostream &out, bool keepCwd)
:
    ScannerBase(in, out, keepCwd)
{}

inline Scanner::Scanner(std::string const &infile, std::string const &outfile, bool keepCwd)
:
    ScannerBase(infile, outfile, keepCwd)
{}

// $insert inlineLexFunction
inline int Scanner::lex()
{
    return lex_();
}

inline void Scanner::preCode() 
{
    // optionally replace by your own code
}

inline void Scanner::postCode([[maybe_unused]] PostEnum_ type) 
{
}

inline void Scanner::print() 
{
    print_();
}

#endif // Scanner_H_INCLUDED_
