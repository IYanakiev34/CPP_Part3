#ifndef UNIQUE3_INCLUDED_H
#define UNIQUE3_INCLUDED_H

#include "../Counter/Counter.h"
#include <memory>

template <typename T>
class Unique
{
  std::unique_ptr<T> d_data;
  Counter d_counter;

                        // Still maintain template instantiation specific count
                        // as exercise assert that we should "also" have global
                        // counts
  static std::size_t s_count;
  static std::size_t s_actual;

public:
    Unique();                                   // 1.f

    ~Unique();

    Unique(T type);                             // 2.f
    Unique(T *tPtr);                            // 3.f
    Unique(Unique &&tmp) = default;
    Unique(Unique const &other);                // 4.f

    Unique &operator=(Unique const &other);
    Unique &operator=(Unique &&tmp) noexcept = default;

    T const &get() const;                       // 1.f
    T &get();                                   // 2.f

    static size_t actual();
    static size_t count();
};

#include "ctor1.f"
#include "ctor2.f"
#include "ctor3.f"
#include "ctor4.f"

#include "dtor.f"

#include "copyAssign.f"

#include "get1.f"
#include "get2.f"

#include "staticDefs.f"

#include "actual.f"
#include "count.f"
#endif