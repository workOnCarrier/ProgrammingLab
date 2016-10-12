#include <sstream>
#include "htmlElement.h"

using namespace std;

htmlElement::htmlElement ( const string &name ) : m_name(name) {}
htmlElement::htmlElement ( const string &name, const string &value ) :m_name(name),m_value ( value)   { }

void htmlElement::addValue ( const string& value ) {
	m_value = value;
}
void htmlElement::addAttribute ( const string &name, const string& value ) {
}
void htmlElement::addChild ( const htmlElement& element) {
    m_children.push_back ( element );
}
string	htmlElement::str( int indent ) const {
    string indentStr ( indent * m_indent_size, ' ' );
	ostringstream	oss;
	oss << indentStr.c_str() << '<' << m_name ;

	for ( const auto att : m_attributes ) {
	    oss << " " << att.name << "=\"" << att.value << "\"";
	}
	oss << '>' ;

	if ( m_value.length() > 0 )
		oss << m_value << endl;

	for ( const auto child : m_children ) {
		oss << endl;
	    oss << child.str(indent+1);
	}
	oss << "</" << m_name << '>' << endl;
	return oss.str();
}
