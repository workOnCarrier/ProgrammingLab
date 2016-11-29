#ifndef __POINT_H__
#define __POINT_H__

#include <ostream>


class  point {
public:
    static point newCartesian ( const float x, const float y );
    static point newPolar ( const float r, const float theta );
private:
    point ( float x, float y ) : m_x(x), m_y(y) { }

    float   m_x;
    float   m_y;
    friend std::ostream& operator << ( std::ostream& , const point& obj );
};

#endif // __POINT_H__
