
#include "Property.h"


Property *allocateProperty() {
    return calloc(1, sizeof(Property));
}

void freeProperty(Property **property) {
    if (*property) {
        if ((*property)->name) freeString(&(*property)->name);
        if ((*property)->description) freeString(&(*property)->description);

        free(*property);
        *property = NULL;
    }
}


Property *newProperty() {
    Property *property = allocateProperty();
    updatePropertyName(property);
    updatePropertyDescription(property);
    return property;
}

void printProperty(Property *property) {
    if (property) {
        printf("Id: %ld\n", property->id);

        if (property->name) printf("Name: `%s`\n", property->name->buffer);
        if (property->description) printf("Description: `%s`\n", property->description->buffer);
    }
}


void updatePropertyName(Property *property) {
    printf("Name: ");
    if (property->name) freeString(&(property->name));
    property->name = readStringLine(stdin);
}

void updatePropertyDescription(Property *property) {
    printf("Description: ");
    if (property->description) freeString(&(property->description));
    property->description = readStringLine(stdin);
}
