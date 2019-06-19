
#include "CustomerBunch.h"

vector<string>	CustomerBunch::getActiveCustomerNames(){
	vector<string>  retVal;
    for ( auto customer : m_customerBunch ){
	    if ( customer.m_isActive){
		    retVal.push_back(customer.m_name);
		}
	}
	return retVal;
}
vector<string>	CustomerBunch::getActiveCustomerAddress(){
	vector<string>  retVal;
    for ( auto customer : m_customerBunch ){
	    if ( customer.m_isActive){
		    retVal.push_back(customer.m_address);
		}
	}
	return retVal;
}

vector<string>	CustomerBunch::getActiveCustomerPhoneNumbers(){
	vector<string>  retVal;
    for ( auto customer : m_customerBunch ){
	    if ( customer.m_isActive){
		    retVal.push_back(customer.m_phone);
		}
	}
	return retVal;
}

vector<string>	CustomerBunch::getActiveCustomerEmails(){
	vector<string>  retVal;
    for ( auto customer : m_customerBunch ){
	    if ( customer.m_isActive){
		    retVal.push_back(customer.m_email);
		}
	}
	return retVal;
}

