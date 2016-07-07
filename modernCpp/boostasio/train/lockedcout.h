#ifndef __LOCKEDCOUT_H__
#define __LOCKEDCOUT_H__

#include <mutex>
#include <ostream>

class LcoutWrap ;

class Lcout {
public:
    Lcout  ( std::ostream& stream )
        : m_stream(stream),m_status(false){}

    bool isLocked() const {return m_status;}

       
    template<typename T>
    friend LcoutWrap& operator<< ( Lcout &stream, const T& tObj ){
        LcoutWrap lcoutwrap(stream);
        stream.m_stream << tObj;
        return lcoutwrap;
    }

   
    friend LcoutWrap ;
private:
    std::ostream    &m_stream;
    std::mutex  m_mutex;
    bool        m_status;
};
class LcoutWrap { //:public Lcout{
        public:
        ~LcoutWrap (){
            //m_lcoutObj.m_stream << std::end;
            std::cout << "                                      deleting lcout wrapper" << std::endl;
        }
        LcoutWrap ( Lcout &lcoutObj )
            :// Lcout(lcoutObj) ,
                m_lockedRef (lcoutObj.m_mutex)
             , m_lcoutObj(lcoutObj)
        {}
        private:
        std::lock_guard<std::mutex> m_lockedRef;
        Lcout           &m_lcoutObj;

        template<typename T>
        friend LcoutWrap& operator<< ( LcoutWrap &stream, const T& tObj ){
            stream.m_lcoutObj.m_stream << tObj;
            return stream;
        }
};
 
#endif // __LOCKEDCOUT_H__
