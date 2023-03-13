#ifndef BASIC_MATH_CONCEPT_INCLUDED_H
#define BASIC_MATH_CONCEPT_INCLUDED_H

template <typename Lhs, typename Rhs>
concept BasicMath =
    requires(Lhs lhs, Rhs rhs) {
        lhs + rhs;
        lhs - rhs;
        lhs *rhs;
        lhs / rhs;
        -lhs;
        -rhs;
    };

#endif