#include <cmath>
#include "newPointFactory.h"

using namespace std;

newPoint  NewPointFactory::newCartesian ( const float x, const float y ) {
    return {x,y};
}
newPoint  NewPointFactory::newPolar ( const float r, const float theta ) {
    return { r*cos(theta),r*sin(theta)};
}
