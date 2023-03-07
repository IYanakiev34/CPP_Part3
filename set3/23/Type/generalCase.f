                              // General case, our needle is not found at the
                              // top of the haystack
template <typename Needle, typename First, typename ...HayStack>
class Type<Needle, First, HayStack...>
{
  struct TypeIdx;

  public:
    enum
    {
      located = TypeIdx::location
    };
};

template <typename Needle, typename First, typename ...HayStack>
struct Type<Needle, First, HayStack...>::TypeIdx
{
  enum
  {
    index = Type<Needle, HayStack...>::located,
    location = index ? index + 1 : 0
  };
};
