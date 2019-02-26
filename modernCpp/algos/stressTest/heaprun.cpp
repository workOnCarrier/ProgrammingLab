
#include <iostream>
#include <random>
#include <cmath>
#include <map>

using namespace std;

void try_randomNumbers(void){
    std::random_device r;

    // choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distibution<int>    uniform_dist(1,6);

    int mean = uniform_dist(e1);
    std::cout << "random chosen mean:" << mean << '\n';

    ba
}

int main (int , char**){
    cout << "Hello world" << endl;
    return 0;
}
