#include "htmlBuilder.h"

htmlBuilder::htmlBuilder ( string rootName ) 
	: m_rootElement ( rootName ) { }
void htmlBuilder::addChild ( const string & name, const string & value ) {
    m_rootElement.addChild  ( htmlElement ( name, value ) );
}
void htmlBuilder::addAttribute ( const string &name, const string& value ) { }
void htmlBuilder::addValue ( const string& value ) {
	m_rootElement.addValue ( value );
}
const htmlElement& htmlBuilder::getHtmlElement ( )const {
    return m_rootElement;
}
