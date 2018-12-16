
#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <stdlib.h>
#include "../Property/Property.h"


typedef struct PropertyArray {
    Property **properties;
    size_t length;
} PropertyArray;

#endif /* PROPERTIES_H */
