#ifndef __KEYINPUTSOURCE_H__
#define __KEYINPUTSOURCE_H__

#include <cctype>

class KeyInputSource{
public:
	typedef std::string		DataType;

	KeyInputSource():m_reading(true) {};

	bool hasMoreData (){ return m_reading; }
	DataType	getNextDataItem(){
		DataType dataItem;
		DataType upCasedataItem;
		char	userInput = '\0';
		for ( (userInput = (char)getchar()) ; EOF !=  userInput ; (userInput = (char)getchar()) )
		{
			while ( ' ' != userInput && '\n' != userInput ){
			    dataItem += userInput;
				upCasedataItem += std::toupper(userInput);
				(userInput = (char)getchar());
			}
			if ( upCasedataItem == "^M" )
			{
				m_reading = false;
			}
			break;
		}
		if ( userInput == (char) EOF )
		{
			m_reading = false;
		}
		return dataItem;
	}
private:
	bool		m_reading;
};
#endif // __KEYINPUTSOURCE_H__
