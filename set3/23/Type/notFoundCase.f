                                    // Base case 1: We could not find our
                                    // needle
template <typename Needle>
class Type<Needle>
{
  struct TypeIdx;
  public:
    enum
    {
      located = TypeIdx::location
    };
};

template <typename Needle>
struct Type<Needle>::TypeIdx
{
  enum
  {
    location = 0
  };
};
