#ifndef __INPUTSUPPLIER_H__
#define __INPUTSUPPLIER_H__

#include <iostream>

template <typename Source,typename SupplyLine>
class InputSupplier {
public:
	InputSupplier( SupplyLine &supplyLine ):m_supplyLine(supplyLine), m_isSupplyActive(true) {}

	void operator () (void ){
		while ( m_sourceObject.hasMoreData() ){
			m_supplyLine.push ( m_sourceObject.getNextDataItem() );
		}
		m_isSupplyActive = false;
	}
	bool	isSupplyActive () { return m_isSupplyActive; }
private:
	InputSupplier() = delete;
	InputSupplier(const InputSupplier&) = delete;
	Source				m_sourceObject;
	SupplyLine			&m_supplyLine;
	bool				m_isSupplyActive;
};
#endif // __INPUTSUPPLIER_H__
