#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include <string>

using std::string;

class Customer{
    public:
	int 	m_id;
	string	m_name;
	string	m_address;
	string 	m_phone;
	string 	m_email;
	bool	m_isActive;
};
#endif // __CUSTOMER_H__
