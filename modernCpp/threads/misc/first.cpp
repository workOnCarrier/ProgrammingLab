#include <iostream>
int getnum (){
	static int num = 0 ;
	return ++num;
}
void foo ( int num1, int num2 ) {
	std::cout << "first num: "<< num1  << " secoind num: "<< num2 << std::endl;
}
int main (int argc, char** argv){
	foo ( getnum(), getnum() );
	return 0;
}
