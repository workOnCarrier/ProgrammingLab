#include <iostream>

#include "htmlBuilder.h"

using namespace std;

void    display_htmlParagraph ();
void display_unorderedList () ;

int main ( int argc, char** argv ) {
    display_htmlParagraph ();
	display_unorderedList ();
	return 0;
}

void    display_htmlParagraph () {
	htmlBuilder		builder ( "p" );
	builder.addValue (  "world" );

	cout << builder.getHtmlElement().str(0) << endl;
}
void display_unorderedList ()  {
    htmlBuilder builder ( "ul" );
	builder.addChild ( "li", "hello" );
	builder.addChild ( "li", "world" );
	cout << builder.getHtmlElement().str(0) << endl;
}
