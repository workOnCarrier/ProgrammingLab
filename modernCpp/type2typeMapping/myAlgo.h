#ifndef __MYALGO_H__
#define  __MYALGO_H__

#include <boost/optional.hpp>
#include "objectCreater.h"

template <typename T>
class myAlgo
{
public:
    myAlgo( const std::string& name);
    ~myAlgo();

	void fire();
protected:
private:
    boost::optional<T*>	m_obj;
	std::string			m_name;
};

template<typename T>
myAlgo<T>::myAlgo (const std::string& name):m_obj(),m_name(name)
{ }

template<typename T>
myAlgo<T>::~myAlgo ()
{
	if ( m_obj.is_initialized() )
	{
	    T* obj = m_obj.get();
		delete obj;
	}
}

template<typename T>
void myAlgo<T>::fire ()
{
    m_obj = create ( m_name , Type2Type<T>() );
}

#endif // __MYALGO_H__
