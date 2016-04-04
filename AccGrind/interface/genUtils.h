#ifndef __ACCGRIND_GENERAL_UTILS_H__
#define __ACCGRIND_GENERAL_UTILS_H__
#include <string>

namespace AccGrind{
    // assuming following behavior from users
    // different oformats from usrs are
    // _1_: " *## *"  -- 0 or more occurences of space
    // _2_: " *##:[A-Za-z0-9]*"
    // _3_: " *## :[A-Za-z0-9]*"
    // _4_: " *##: [A-Za-z0-9]*"
    // _5_: " *## *[A-Za-z0-9]*"
    // from these formats, we need to take out the number ## 
    std::string getFirstPart ( std::string const & usrInput);

    struct UserInputSplit{
        int     m_optionNo;
        std::string  m_optionInput;
    };
    UserInputSplit getOptionFromUsrInput ( std::string const & usrInput);

}
#endif // __ACCGRIND_GENERAL_UTILS_H__
