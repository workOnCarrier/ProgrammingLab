#ifndef __LOCKEDCOUT_H__
#define __LOCKEDCOUT_H__

#include <mutex>
#include <ostream>


class Lcout {
public:
    Lcout  ( std::ostream& stream )
        : m_stream(stream),m_status(false){}

    bool isLocked() const {return m_status;}

       
    template<typename T>
    friend Lcout& operator<< ( Lcout &stream, const T& tObj ){
        stream.m_stream << tObj << '\n';
        return stream;
    }

   
private:
    std::ostream    &m_stream;
    std::mutex  m_mutex;
    bool        m_status;
};
 
#endif // __LOCKEDCOUT_H__
