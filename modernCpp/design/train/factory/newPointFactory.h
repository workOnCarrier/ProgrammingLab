#ifndef __NEW_POINT_FACTORY_H_
#define __NEW_POINT_FACTORY_H_

#include "newPoint.h"


class NewPointFactory {
public:
    static newPoint  newCartesian ( const float x, const float y );
    static newPoint  newPolar ( const float r, const float theta );
};
#endif // __NEW_POINT_FACTORY_H_
