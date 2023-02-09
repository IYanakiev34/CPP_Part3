// not intended for the pdf so all style bets are off
#include "main.ih"

struct B
{
    int m = 42;
    const char* hello() const
    {
        return "Hello world, this is B!\n";
    }
};
 
struct D : B
{
    const char* hello() const
    {
        return "Hello world, this is D!\n";
    }
};

enum class E { ONE = 1, TWO, THREE };
enum EU { ONE = 1, TWO, THREE };

void test()
{
    // 1. static downcast
    D d;
    B& br = d; // upcast via implicit conversion
    std::cout << "1) " << br.hello();
    D& another_d = as<D&>(br); // downcast
    std::cout << "1) " << another_d.hello();
 
    // 2. lvalue to xvalue
    std::vector<int> v0{1,2,3};
    std::vector<int> v2 = as<std::vector<int>&&>(v0);
    std::cout << "2) after move, v0.size() = " << v0.size() << '\n';
 
    // 3. initializing conversion
    int n = as<int>(3.14);
    std::cout << "3) n = " << n << '\n';
    std::vector<int> v = as<std::vector<int>>(10);
    std::cout << "3) v.size() = " << v.size() << '\n';
 
    // 4. discarded-value expression
    as<void>(v2.size());
 
    // 5. inverse of implicit conversion
    void* nv = &n;
    int* ni = as<int*>(nv);
    std::cout << "4) *ni = " << *ni << '\n';
 
    // 6. array-to-pointer followed by upcast
    D a[10];
    [[maybe_unused]]
    B* dp = as<B*>(a);
 
    // 7. scoped enum to int
    E e = E::TWO;
    int two = as<int>(e);
    std::cout << "7) " << two << '\n';
 
    // 8. int to enum, enum to another enum
    E e2 = as<E>(two);
    [[maybe_unused]]
    EU eu = as<EU>(e2);
 
    // 9. pointer to member upcast
    int D::*pm = &D::m;
    std::cout << "9) " << br.*as<int B::*>(pm) << '\n';
 
    // 10. void* to any type
    void* voidp = &e;
    [[maybe_unused]]
    std::vector<int>* p = as<std::vector<int>*>(voidp);
}