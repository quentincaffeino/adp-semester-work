
#ifndef PROPERTY_H
#define PROPERTY_H

#include <stdlib.h>
#include "../../Helpers/String/String.h"


typedef struct Property {
    size_t id;
    String *name;
    String *description;
} Property;

#endif /* PROPERTY_H */
