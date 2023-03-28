#include "main.ih"

void handleExceptions()
{
  try
  {
    rethrow_exception(current_exception());
  }
  catch (string &error)
  {
    cout << error << '\n';
  }
}
