// JB: 1
#ifndef SET8_RULE_H
#define SET8_RULE_H

#include "../Production/Production.h"

class Rule
{
  std::string d_name;
  std::vector<Production> d_productions;

  public:
    Rule() = default;
    Rule(std::string const &name, std::vector<Production> const &productions);
    std::string print() const;
};

#endif //SET8_RULE_H

/* JB:
   For the purpose of a generative parser, this choice of data type is
   somewhat impractical.
   A generative parser needs to keep a queue of unfinished sentences and a
   list of all production rules. It does the following:
   - pop an unfinished sentence from the queue. Call it S;
   - iterate over the rules. For each rule that can be applied to S, do so.
     If the result is a finished sentence, writes it to output.
     Else, push the unfinished sentence onto the queue.

   In order to iterate over rules, your program would have to iterate over
   Rules, and withing each Rule again iterate over productions.
   It would be more practical if each Rule had one left hand side and one
   right hand side.
 */
