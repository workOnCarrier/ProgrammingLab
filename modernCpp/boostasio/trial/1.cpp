


#include <iostream>
#include <vector>

using namespace std;



class channel {
    public:
        static int connection;
};
int channel::connection = 0;
class pchan : public channel{
};
class nchan : public channel {
};

template <class T> using vec = vector<T>;

int main (){
    vec <float> fltvect;

    channel ch;
    nchan   ch1;
    pchan   ch2;
    pchan&  cref = ch2;

   ch2.connection++;
   ch.connection++;
   //ch::connection++;
   nchan::connection++;
   //channel.connection++;

   cout << "connection " << ch2.connection << endl;

   for (char idx = 0; idx < 10; idx++ ){
       cout << "hellow --- " << endl;
   }

    return 0;
};
