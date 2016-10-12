#ifndef __HTMLBUILDER_H__
#define __HTMLBUILDER_H__

#include "htmlElement.h"

class htmlBuilder {
public:
    htmlBuilder ( string rootName );

	void addChild ( const string & name, const string & value );
	void addAttribute ( const string &name, const string& value );
	void addValue ( const string& value );
	const htmlElement& getHtmlElement ( )const ;

private:
	htmlElement		m_rootElement;
};
#endif  // __HTMLBUILDER_H__
