#include <iostream>

template <typename Type>
concept AddSubable =
        requires(Type lhs, Type rhs)
        {
            lhs + rhs;
            lhs - rhs;
        };

template <typename Type>
concept MulDivable =
    requires(Type lhs, Type rhs)
    {
        lhs * rhs;
        lhs / rhs;
    };

template <typename Type>
concept AddMul = AddSubable<Type> or MulDivable<Type>;

template <typename Type>
concept AddOrMul =
        (AddSubable<Type> and not MulDivable<Type>) or
        (not AddSubable<Type> and MulDivable<Type>);

/*****************************************************************
/ DUMMY CLASSES / TESTS
*****************************************************************/
class AllBasicOps
{
    int d_val;
public:
    explicit AllBasicOps(int val) : d_val(val) {}
    friend AllBasicOps operator+(AllBasicOps lhs, AllBasicOps rhs);
    friend AllBasicOps operator-(AllBasicOps lhs, AllBasicOps rhs);
    friend AllBasicOps operator*(AllBasicOps lhs, AllBasicOps rhs);
    friend AllBasicOps operator/(AllBasicOps lhs, AllBasicOps rhs);
};
AllBasicOps operator+(AllBasicOps lhs, AllBasicOps rhs)
{
    return AllBasicOps{lhs.d_val + rhs.d_val};
}
AllBasicOps operator-(AllBasicOps lhs, AllBasicOps rhs)
{
    return AllBasicOps{lhs.d_val - rhs.d_val};
}
AllBasicOps operator*(AllBasicOps lhs, AllBasicOps rhs)
{
    return AllBasicOps{lhs.d_val * rhs.d_val};
}
AllBasicOps operator/(AllBasicOps lhs, AllBasicOps rhs)
{
    return AllBasicOps{lhs.d_val / rhs.d_val};
}
class AddSubOnly
{
    int d_val;
public:
    explicit AddSubOnly(int val) : d_val(val) {}
    friend AddSubOnly operator+(AddSubOnly lhs, AddSubOnly rhs);
    friend AddSubOnly operator-(AddSubOnly lhs, AddSubOnly rhs);
};
AddSubOnly operator+(AddSubOnly lhs, AddSubOnly rhs)
{
    return AddSubOnly{lhs.d_val + rhs.d_val};
}
AddSubOnly operator-(AddSubOnly lhs, AddSubOnly rhs)
{
    return AddSubOnly{lhs.d_val - rhs.d_val};
}

template <AddMul Type>
void oneOrBoth(Type lhs, Type rhs)
{
}
template <AddOrMul Type>
void exactlyOne(Type lhs, Type rhs)
{
}

int main()
{
    AllBasicOps abo1{1};
    AllBasicOps abo2{2};
    AddSubOnly aso1{1};
    AddSubOnly aso2{2};

    oneOrBoth(abo1, abo2);
    oneOrBoth(aso1, aso2);
    exactlyOne(abo1, abo2); // doesn't work
    exactlyOne(aso1, aso2);
}
