#ifndef SET1_POINTERUNION_H
#define SET1_POINTERUNION_H

union PointerUnion
{
                                  // Used to assign template function to this
                                  // union
  int (*fp)(int);
                                  // Used to access the address of the fp
  void *vp;
};

#endif //SET1_POINTERUNION_H
