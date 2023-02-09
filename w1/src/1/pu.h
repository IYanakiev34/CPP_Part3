#ifndef POINTER_UNION_H
#define POINTER_UNION_H

union PointerUnion
{
    int (*fp)(int const &,int const &);
    void *vp;
};

#endif
