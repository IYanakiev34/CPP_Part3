#ifndef MATH_CONCEPT_INCLUDED_H
#define MATH_CONCEPT_INCLUDED_H

template <typename Lhs, typename Rhs>
concept BasicMath =
    requires(Lhs lhs, Rhs rhs) {
        lhs + rhs;
        rhs + lhs;
        lhs - rhs;
        rhs - lhs;
        lhs *rhs;
        rhs *lhs;
        lhs / rhs;
        rhs / lhs;
        -lhs;
        -rhs;
    };

#endif
