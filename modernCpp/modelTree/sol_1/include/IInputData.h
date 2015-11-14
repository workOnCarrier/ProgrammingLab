#ifndef __IINPUTDATA_H__
#define __IINPUTDATA_H__

#include <memory>

class IInputData{
public:
	IInputData(){};
	virtual ~IInputData(){};

	typedef std::shared_ptr<IInputData>	IInputDataPtr;
	///
	// Other functions to follow
	///
};
#endif  //__IINPUTDATA_H__
