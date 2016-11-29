#include <ostream>
#include "point.h"
#include <cmath>

using namespace std;
ostream& operator << ( ostream& stream, const point& obj ){
    stream << "x:" << obj.m_x;
    stream << "\ty:" << obj.m_y;
    return stream;
}
point point::newCartesian ( const float x, const float y ) {
    return {x,y};
}
point point::newPolar ( const float r, const float theta ) {
    return {r*cos(theta), r*sin(theta)};
}
