#include <string>

class Soundex{
public:
    Soundex(){}
    std::string encode ( std::string const & input) {
        return input;
    }
};
// #include "gmock/gmock.h"
#include "gtest/gtest.h"
TEST ( SoundexEncoding, RetainSoleLetterOfOneLetterWord_1 ){
    Soundex soundex;
    std::string encoded = soundex.encode("A");
    ASSERT_EQ ( encoded, "A");
    // triangulating -- generalizing
    ASSERT_EQ ( soundex.encode("B"), "B");
}
TEST ( SoundexEncoding, RetainSoleLetterOfOneLetterWord_2 ){
    Soundex soundex;
    std::string encoded = soundex.encode("B");
    ASSERT_EQ ( encoded, "B");
}
