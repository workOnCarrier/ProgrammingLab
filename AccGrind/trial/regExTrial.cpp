#include <string>
#include <regex>
#include <iostream>
#include <algorithm>

        // _1_: " *## *"  -- 0 or more occurences of space
        // _2_: " *##:[A-Za-z0-9]*"
        // _3_: " *## :[A-Za-z0-9]*"
        // _4_: " *##: [A-Za-z0-9]*"
        // _5_: " *## *[A-Za-z0-9]*"
        //
// http://gcc.gnu.org/onlinedocs/libstdc++/manual/status.html#status.iso.200x 
// Regex not implamented till 4.9... need to try once I upgrade to either clang or gcc 4.9 
// for now-- I will not use the regex library
void testgetFirstPart ();
std::string getFirstPart ( std::string &usrInput);

int main (){
    testgetFirstPart ();
    return 0;
}

void testgetFirstPart (){
    std::string data0 = "0";
    std::string data1 = " 1 ";
    std::string data2 = "  2:test2 ";
    std::string data3 = "   3 :test3";
    std::string data4 = "    41: test4 ";
    std::string data5 = "     5 test5";

    std::cout << "Testing 0:" << data0 << "->" <<getFirstPart ( data0 ) << "<-" << std::endl;
    std::cout << "Testing 1:" << data1 << "->" <<getFirstPart ( data1 ) << "<-" << std::endl;
    std::cout << "Testing 2:" << data2 << "->" <<getFirstPart ( data2 ) << "<-" << std::endl;
    std::cout << "Testing 3:" << data3 << "->" <<getFirstPart ( data3 ) << "<-" << std::endl;
    std::cout << "Testing 4:" << data4 << "->" <<getFirstPart ( data4 ) << "<-" << std::endl;
    std::cout << "Testing 5:" << data5 << "->" <<getFirstPart ( data5 ) << "<-" << std::endl;
    return ;
}

const std::string   delimiters ("|: ");

std::string getFirstPart ( std::string &usrInput){
    std::string  firstPart ;
    int pos = 0;

    // skip leading spaces
    while ( ' ' == usrInput[pos] ){++pos; }

    std::string trimedInput = usrInput.substr(pos);
    int minFound = 0; 
    for ( int delpos = 0; delpos < delimiters.length(); delpos++ ){
        int newPos = 0;
        newPos = ( trimedInput.find(delimiters[delpos]) == std::string::npos ) ? -1 : (trimedInput.find(delimiters[delpos]));
        if ( newPos != -1 && (newPos < minFound || minFound==0) ) {
            minFound = newPos;
        }
    }
    if ( 0 !=  minFound ){
        firstPart  = usrInput.substr ( pos, minFound );
    }else{
        firstPart  = usrInput.substr ( pos );
    }

    return firstPart ;
}

//std::string getFirstPart ( std::string &usrInput){
//    std::string  firstPart ;
//    int pos = 0;
//    bool    end = false;
//    while ( false == end ){
//        char start = usrInput[pos]; 
//        // skip leading spaces
//        while ( ' ' == usrInput[pos] ){++pos; }
//
//        // checking for ' ', '|' , ':'
//        std::regex   reg ( "[ |:]" ); 
//        std::string trimString = usrInput.substr(pos);
//        std::sregex_token_iterator location ( trimString.cbegin(), trimString.end()
//                ,reg, {0,1} );
//        firstPart = location->str();
//    }
//    return firstPart ;
//}
