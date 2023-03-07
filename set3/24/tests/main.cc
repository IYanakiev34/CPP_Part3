#include "main.ih"

int main()
{
  string value{ I2C<15937>::s_ntbs };
  cout << I2C<123>::s_ntbs << '\n'     // shows 123
    << I2C<15937>::s_ntbs << '\n'
    << I2C<15937>::s_ntbs << '\n'
    << I2C<15937>::s_ntbs << '\n'
    << I2C<15937>::s_ntbs << '\n'
    << I2C<0>::s_ntbs;

}