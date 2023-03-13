#ifndef DEREF_INCLUDED_H
#define DEREF_INCLUDED_H

template <typename Type>
concept Deref =
    requires(Type type) {
        *type;
    };

#endif
