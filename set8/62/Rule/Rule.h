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
