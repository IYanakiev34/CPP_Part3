#ifndef ONE_CHAR_H
#define ONE_CHAR_H

template <char Value>
struct OneChar
{
    enum
    {
        value = Value
    };
};

#endif