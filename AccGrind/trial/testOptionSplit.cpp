#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

struct UserInputSplit{
    int     m_optionNo;
    string  m_optionInput;
};
ostream& operator << ( ostream& stream, const UserInputSplit& usrInputSplit ){
    stream << "Int part:" << usrInputSplit.m_optionNo << std::endl;
    stream << "input part:" << usrInputSplit.m_optionInput << std::endl; 
    return stream;
}
 UserInputSplit getOptionFromUsrInput ( std::string const & usrInput){
        UserInputSplit optionSplit ;
        std::size_t conversionCount = 0;
        try{
            optionSplit.m_optionNo = std::stoi ( usrInput, &conversionCount  );
            std::string optionInput = usrInput.substr ( conversionCount, usrInput.length()-conversionCount );
            while ( optionInput.length() > 0 &&
                        ( optionInput[0] == ' ' || optionInput[0] == ':'
                          || optionInput[0] == ';' || optionInput[0] == ',' )
                   ) {
                optionInput = optionInput.substr( 1, optionInput.length()-1);
            }
            optionSplit.m_optionInput = optionInput ;
        }catch (std::invalid_argument &e){
        }catch ( std::out_of_range &e){
        }catch (...){
        }
        return optionSplit ;
    }
int main (){
    std::string     testStr = "1:: this is fun";
    std::cout << testStr << endl;
    auto output = getOptionFromUsrInput  ( testStr );
    std::cout << output << endl;
    return 0;
}
