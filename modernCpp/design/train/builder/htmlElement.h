#ifndef __HTMLELEMENT_H_
#define __HTMLELEMENT_H_

#include <vector>
#include "string"

using std::string;
using std::vector;

class htmlElement {
public:
    htmlElement ( const string &name );
    htmlElement ( const string &name, const string &value );

	void addAttribute ( const string &name, const string& value );
	void addChild ( const htmlElement& );
	void addValue ( const string& value );
	string	str( int indent ) const;

private:
    
	struct 					attribute {
		string name;
		string value;
	};
	string					m_name;
	string					m_value;
	vector<htmlElement>		m_children;
	vector<attribute>		m_attributes;

	const int				m_indent_size = 2;
};
#endif // __HTMLELEMENT_H_
