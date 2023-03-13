#include <iostream>

template<typename Ref>
concept Dereferencable =
requires(Ref ref)
{
    *ref;
};

template<Dereferencable Ref>
void fun1(Ref ref)
{
}

template<typename Ref>
requires Dereferencable<Ref>
void fun2(Ref ref)
{
}

template<Dereferencable Ref>
class Class1
{
};

template<typename Ref>
requires Dereferencable<Ref>
class Class2
{
};

int main()
{
    // Work
    int *ptr = new int{3};
    fun1(ptr);
    fun2(ptr);
    Class1<int *> class1{};
    Class2<int *> class2{};

    // Do not work
    int val = 3;
    fun1(val);
    fun2(val);
    Class1<int> class1Fail{};
    Class2<int> class2Fail{};
}
