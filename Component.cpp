#include "Component.hpp"
#include <stdlib.h>

Component::~Component() {
    free(forward);
    free(reverse);
}


