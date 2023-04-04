#ifndef RULES_h_1680530334
#define RULES_h_1680530334

#include "../Rule/Rule.h"

class Rules
{
  std::vector<Rule> d_rules;
  public:
    Rules() = default;
    void add(const Rule &rule);
    std::string print() const;
};

#endif
