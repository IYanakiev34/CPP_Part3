#include <iostream>

template <size_t Number, char... Characters>
struct I2CAux
{
    static constexpr char const *s_ntbs = I2CAux<
            Number / 10,
            Number % 10 + '0',
            Characters...>::s_ntbs;
};

template <char... Characters>
struct I2CAux<0, Characters...>
{
    static constexpr char const s_ntbs[] = {Characters...};
};

template <char... Characters>
constexpr char const I2CAux<0, Characters...>::s_ntbs[];

template <size_t Number>
struct I2C
{
    static constexpr char const *s_ntbs = I2CAux<
            Number, '\0'>::s_ntbs;
};

using namespace std;

int main()
{
    cout << I2C<123>::s_ntbs << '\n' <<     // shows 123
            I2C<0>::s_ntbs << '\n';         // shows 0

    string value{ I2C<15937>::s_ntbs };

    cout << value << '\n';                  // shows 15937
}
