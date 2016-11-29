#ifndef __NEW_POINT_H__
#define __NEW_POINT_H__

#include <ostream>


class  newPoint {
public:
private:
    newPoint ( float x, float y ) : m_x(x), m_y(y) { }

    float   m_x;
    float   m_y;
    friend std::ostream& operator << ( std::ostream& , const newPoint& obj );
    friend class NewPointFactory;
};

#endif // __NEW_POINT_H__
