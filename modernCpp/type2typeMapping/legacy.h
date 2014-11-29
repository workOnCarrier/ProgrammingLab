#ifndef __LEGACY_H__
#define  __LEGACY_H__

#include <string>

using std::string;

class legacy
{
public:
    legacy(const std::string&, int count);
	virtual ~legacy();
private:
    std::string		m_objName;
	int				m_randomCount;
};
#endif //__LEGACY_H__
