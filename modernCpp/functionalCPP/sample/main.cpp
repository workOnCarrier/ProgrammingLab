#include <iostream>

#include <algorithm>
#include "Customer.h"
#include "CustomerBunch.h"

using namespace std;

void RegisterCustomers(CustomerBunch&    custList){
    int i = 0;
	bool b = false;
	vector<string> nameList = {
	"William", "Adam", "Rowan", "Jamie",
	"Quinn", "Haiden", "Logan", "Emerson",
	"Sherlyn", "Molly"
	};

	for (auto name : nameList ){
	    Customer c;
		c.m_id = i++;
		c.m_name = name;
		c.m_address = "anywhere";
		c.m_phone = "123456";
		c.m_email  = "xyz@abc.com";
		c.m_isActive = b;
		b = !b;
		custList.addCustomer (c);
	}

}

auto main ()->int {
    cout << "[Step 01]" << endl;
	cout << "--------------" << endl;
	CustomerBunch   custBunch;
	RegisterCustomers ( custBunch ) ;

	// list of active customer names
	cout << " list of active customer names " << endl;
	auto nameList = custBunch.getActiveCustomerNames();
	for ( auto name : nameList ) {
	    cout << name << endl;
	}
	return 0;
}
