#include <iostream>
#include <sstream>

using namespace std;


void    display_htmlParagraph ();
void display_unorderedList () ;


int main ( int argc , char** argv ) {
    display_htmlParagraph ();
	display_unorderedList  () ;
    return 0;
}
void    display_htmlParagraph ()  {
 // <p>...</p>
	string data = "hello";

	string buffer = "<p>";
	buffer += data;
	buffer += "</p>";

	cout << buffer.c_str() << endl;

}

void display_unorderedList () {
    // <ul>
	//    <li>hello</li>
	//    <li>world</li>
    // <ul>
	string words [] = {"hello", "world" };

	ostringstream oss ;
	// oss << "<ul>" << "<li>" << words[0] << "</li>" << "<li>" << words[1] << "</li>" << "</ul>" << endl;

	oss << "<ul>"  << endl;
	for ( auto w : words ) {
	    oss << "<li>" << w << "</li>" << endl;
	}
	oss << "</ul>"  << endl;

	cout << oss.str() << endl;
}
