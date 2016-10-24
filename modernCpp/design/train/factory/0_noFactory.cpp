#include <iostream>
// #include <ostream>
#include <cmath>

using namespace std;

class point {
public:
    // usual constructor only valid for cartesian coordinate point
    //      point ( float x, float y )      :m_x(x), m_y(y){ }
    // constructor supporting polar coordinates
    //      point ( float a, float b )      :m_x(a*cos(b)), m_y(a*sin(b)){ }
    // to distinguish between the two invocations, you can add a third parameter
    // ---- mind it this makes the interface quite messy
    enum class pointType {
        cartesian, polar
    };
    point ( float a, float b , pointType type = pointType::cartesian) {
        if ( pointType::cartesian == type ) {
            m_x = a;
            m_y = b;
        }else{
            m_x = a*cos(b);
            m_y = a*sin(b);
        }
        m_pointType = type ;
    }
private:
    float   m_x;
    float   m_y;
    pointType   m_pointType;
    friend  ostream& operator << ( ostream& stream, const point& pt) ;
};

ostream& operator << ( ostream& stream, const point& pt) {
    stream << "point type: " << ( (pt.m_pointType == point::pointType::cartesian) ? "cartesian" : "polar" )
            << " x:" << pt.m_x << " y" << pt.m_y ;
    return stream;
}

int main () {
    point pt_1( 1.0, 1.0 );
    cout << pt_1 << endl;;

    point pt_2( 1.0, 1.0 , point::pointType::polar);
    cout << pt_2 << endl;;
    return 0;
}
