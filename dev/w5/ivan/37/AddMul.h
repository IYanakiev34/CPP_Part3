#ifndef ADD_MUL_CONCEPT_H
#define ADD_MUL_CONCEPT_H

template <typename Type>
concept Add =
    requires(Type lhs, Type rhs) {
        lhs + rhs;
        lhs - rhs;
    };

template <typename Type>
concept Mul =
    requires(Type lhs, Type rhs) {
        lhs *rhs;
        lhs / rhs;
    };

template <typename Type>
concept AddMul = Add<Type> or Mul<Type>;

template <typename Type>
concept AddOrMul =
    (Mul<Type> and not Add < Type) or
    (Add<Type> and not Mul<Type>);

#endif
