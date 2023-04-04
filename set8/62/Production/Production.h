#ifndef PRODUCTION_h_1680530340
#define PRODUCTION_h_1680530340

#include <string>
#include <vector>

class Production
{
  std::vector<std::string> d_tokens;
  public:
    Production() = default;
    void add(const std::string &token);
    std::string print() const;
  private:
    std::string stripQuotes(std::string const &token) const;
};

#endif
