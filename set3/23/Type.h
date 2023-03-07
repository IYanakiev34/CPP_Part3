#ifndef TYPE_INCLUDED_H
#define TYPE_INCLUDED_H

template <typename ...Types>
class Type
{};

template <typename Needle, typename First, typename ...HayStack>
class Type<Needle, First, HayStack...>
{
  struct TypeIdx;

  public:
    using TypeIdx::located;
};

template <typename Needle, typename First, typename ...HayStack>
struct Type<Needle, First, HayStack...>::TypeIdx
{
  enum
  {
    location = Type<Needle, HayStack...>::located,
    located = location ? location + 1 : 0
  };
};

template <typename Needle>
class Type<Needle>
{
  struct TypeIdx;
  public:
    using TypeIdx::located;
};

template <typename Needle>
struct Type<Needle>::TypeIdx
{
  enum
  {
    located = 0
  };
};

template <typename Needle, typename ...HayStack>
class Type<Needle, Needle, HayStack...>
{
  struct TypeIdx;
  public:
    using TypeIdx::located;
};

template <typename Needle, typename ...HayStack>
struct Type<Needle, Needle, HayStack...>::TypeIdx
{
  enum
  {
    located = 1
  };
};


#endif