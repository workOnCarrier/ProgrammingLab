#include <string>

class Soundex{
public:
    Soundex(){}
    std::string encode ( std::string const & input) {
        return zeroPadding ( input );
    }
private:
    std::string zeroPadding ( std::string const &input ) {
        return input + "000" ;
    }
};
// #include "gmock/gmock.h"
#include "gtest/gtest.h"
// converting to fixtures
class SoundexEncoding : public testing::Test {
    Soundex soundex;
} 

TEST ( SoundexEncoding, RetainSoleLetterOfOneLetterWord_1 ){
    Soundex soundex;
    std::string encoded = soundex.encode("A");
    ASSERT_EQ ( encoded, "A000");
    // triangulating -- generalizing
    ASSERT_EQ ( soundex.encode("B"), "B000");
}

TEST ( SoundexEncoding, PadWithZerosToEnxureThreeDigits ){
    Soundex soundex;
    std::string encoded = soundex.encode("I");
    ASSERT_EQ ( encoded, "I000" );
}
