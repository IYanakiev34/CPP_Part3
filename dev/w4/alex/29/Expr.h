#ifndef EXPR_H
#define EXPR_H

#include <vector>
#include "Plus.h"

template<typename LHS, typename RHS,
        template<typename> class Operation>
class Expr
{
    template<typename Class>
    struct Trait
    {
        using VType = typename Class::VType;
    };
    template<typename Type>
    struct Trait<std::vector<Type>>
    {
        using VType = std::vector<Type>;
    };

    LHS const &d_lhs;
    LHS const &d_rhs;

public:
    using VType = typename Trait<RHS>::VType;
    using value_type = typename VType::value_type;

    Expr(LHS const &lhs, RHS const &rhs);

    operator VType() const;

    auto operator[](size_t idx) const;

    [[nodiscard]] size_t size() const;
};

template<typename LHS, typename RHS,
        template<typename> class Operation>
Expr<LHS, RHS, Operation>::Expr(const LHS &lhs, const RHS &rhs)
        : d_lhs(lhs), d_rhs(rhs)
{
}

template<typename LHS, typename RHS,
        template<typename> class Operation>
Expr<LHS, RHS, Operation>::operator VType() const
{
    VType ret;
    for (size_t idx = 0; idx != d_rhs.size(); ++idx)
        ret.push_back(Operation<value_type>{}(d_lhs[idx], d_rhs[idx]));
    return ret;
}

template<typename LHS, typename RHS,
        template<typename> class Operation>
auto Expr<LHS, RHS, Operation>::operator[](size_t idx) const
{
    return Operation<value_type>{}(d_lhs[idx], d_rhs[idx]);
}

template<typename LHS, typename RHS,
        template<typename> class Operation>
inline size_t Expr<LHS, RHS, Operation>::size() const
{
    return d_rhs.size();
}

template <typename LHS, typename RHS>
auto operator+(LHS const &lhs, RHS const &rhs)
{
    return Expr<LHS, RHS, Plus>{ lhs, rhs };
}

#endif