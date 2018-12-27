
#ifndef PROPERTY_H
#define PROPERTY_H

#include <stdlib.h>
#include "../../Helpers/String/String.h"


typedef struct Property {
    size_t id;
    String *name;
    String *description;
} Property;


Property *allocateProperty();

void freeProperty(Property **property);


Property *newProperty();

void printProperty(Property *property);


void updatePropertyName(Property *property);

void updatePropertyDescription(Property *property);

#endif /* PROPERTY_H */
