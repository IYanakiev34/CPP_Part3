#ifndef SET4_EXPR_H
#define SET4_EXPR_H

#include "../plus/plus.h"

template <typename LHS, typename RHS, template <typename> class op>
struct Expr;


template <typename LHS, typename RHS>
auto operator+(LHS const &lhs, RHS const &rhs)
{
  return Expr<LHS, RHS, plus> { lhs, rhs };
}
#endif //SET4_EXPR_H
