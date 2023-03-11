#include <iostream>
#include <vector>

template <typename Container>
concept Indexable =
        requires(Container container)
        {
            { container[0] } ->
                std::convertible_to<typename Container::value_type>;
        };

template <Indexable Container>
void testIndexable(Container container)
{
}

int main()
{
    std::vector vec{1,2,3};
    testIndexable(vec);
}
