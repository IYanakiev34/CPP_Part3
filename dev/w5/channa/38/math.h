#ifndef SET5_MATH_H
#define SET5_MATH_H

                                  // math applies Operation between the first
                                  // argument and each of the subsequent
                                  // arguments. So for arguments:
                                  // 1) arg1, arg2
                                  // 2) arg1, arg3
                                  //    ...
                                  // N) arg1, argN
template <template <typename, typename> class Operation, typename ...Args>
void math(Args &&...args);

                                  // Base case: If we only have 1 argument, do
                                  // nothing
template <template <typename, typename> class Operation, typename Last>
void math(Last last)
{};

                                  // General case: Apply operation to First and
                                  // Second, then call math on First and Rest.
template <
  template <typename, typename> class Operation,
  typename First, typename Second, typename ...Rest
>
void math(First first, Second second, Rest &&...rest)
{
  Operation<First, Second>::operation(first, second);
  math<Operation>(first, rest...);
}

#endif //SET5_MATH_H
