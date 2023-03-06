#include <iostream>

template<typename Type>
struct TypeTraits
{
    using BasicType = Type;
    enum
    {
        variant = 1
    };
};

template<typename Type>
struct TypeTraits<Type *>
{
    using BasicType = Type;
    enum
    {
        variant = 2
    };
};

template<typename Type>
struct TypeTraits<Type &>
{
    using BasicType = Type;
    enum
    {
        variant = 3
    };
};

template<typename Type>
struct TypeTraits<Type &&>
{
    using BasicType = Type;
    enum
    {
        variant = 4
    };
};

template<typename Type>
typename TypeTraits<Type>::BasicType const *makeConstPtr(Type arg) {
    if constexpr (TypeTraits<Type>::variant == 2)
        return arg;
    else if constexpr (TypeTraits<Type>::variant == 3)
        return &arg;
    else 
        return new typename TypeTraits<Type>::BasicType{arg};
}

using namespace std;

int main()
{
    int temp = 3;

    int plain = 1;
    int *ptr = new int{2};
    int &ref = temp;
    int &&rref = 4;

    cout <<
         "Expected " << plain <<
         " Got " << TypeTraits<decltype(plain)>::variant << '\n' <<
         "Expected " << *ptr <<
         " Got " << TypeTraits<decltype(ptr)>::variant << '\n' <<
         "Expected " << ref <<
         " Got " << TypeTraits<decltype(ref)>::variant << '\n' <<
         "Expected " << rref <<
         " Got " << TypeTraits<decltype(rref)>::variant << '\n';

    // Not entirely sure what the want here
    auto testPtr = makeConstPtr(plain);
    cout << *testPtr << '\n';
}
