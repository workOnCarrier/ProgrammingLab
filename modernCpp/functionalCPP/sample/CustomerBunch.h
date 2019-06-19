#ifndef __CUSTOMERBUNCH_H__
#define  __CUSTOMERBUNCH_H__

#include "Customer.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class CustomerBunch{
    vector<Customer>	m_customerBunch;

public:
	void addCustomer ( Customer& c){m_customerBunch.push_back(c);}
	vector<string>	getActiveCustomerNames();
	vector<string>	getActiveCustomerAddress();
	vector<string>	getActiveCustomerPhoneNumbers();
	vector<string>	getActiveCustomerEmails();
};

#endif //  __CUSTOMERBUNCH_H__
