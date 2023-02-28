#ifndef DERIVED_STATIC_H
#define DERIVED_STATIC_H

#include "base.h"

class Derived : public Base<Derived>
{
public:
    int nc_impl(double d) const { return static_cast<int>(d); }
};

#endif