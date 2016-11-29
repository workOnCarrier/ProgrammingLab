#include <ostream>
#include "newPoint.h"
std::ostream& operator << ( std::ostream& stream, const newPoint& obj ) {
    stream << "x:" << obj.m_x;
    stream << "\ty:" << obj.m_y;
    return stream;
}

