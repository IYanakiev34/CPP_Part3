                                // Base case 2: We have found our needle
template <typename Needle, typename ...HayStack>
class Type<Needle, Needle, HayStack...>
{
  struct TypeIdx;
  public:
    enum
    {
      located = TypeIdx::location
    };
};

template <typename Needle, typename ...HayStack>
struct Type<Needle, Needle, HayStack...>::TypeIdx
{
  enum
  {
    location = 1
  };
};
