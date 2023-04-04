#ifndef _INCLUDED_RULEVALUE_H_
#define _INCLUDED_RULEVALUE_H_

#include <unordered_map>

struct RuleValue
{
    using SingleArgFunc = double (*)(double);
    using FunctionMap = std::unordered_map<std::string, SingleArgFunc>;
    using ConstantMap = std::unordered_map<std::string, double>;

    static FunctionMap d_functionMap;
    static ConstantMap d_constantMap;

    enum Type
    {
        VALUE,
        VARIABLE,
        FUNC
    };

    Type          d_type;
    double        d_number;
    unsigned      d_idx;
    SingleArgFunc d_func;

    bool          d_argGeometric;
    bool          d_resGeometric;

    public:
        RuleValue();
        RuleValue(double value);
        RuleValue(unsigned idx);
        RuleValue(
            SingleArgFunc func,
            bool argGeometric = false, bool resGeometric = false
        );
    bool argGeometric() const;
    bool resGeometric() const;
};

inline bool RuleValue::argGeometric() const
{
  return d_argGeometric;
}

inline bool RuleValue::resGeometric() const
{
  return d_resGeometric;
}



#endif
