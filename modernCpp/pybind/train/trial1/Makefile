


all:
	g++ -O3 -Wall -shared -std=c++14 -fPIC `python3 -m pybind11 --includes` example1.cpp -o example1`python3-config --extension-suffix`
	g++ -O3 -Wall -shared -std=c++14 -fPIC `python3 -m pybind11 --includes` classExample.cpp -o classExample`python3-config --extension-suffix`
	g++ -O3 -Wall -shared -std=c++14 -fPIC `python3 -m pybind11 --includes` inheritance.cpp -o inheritance`python3-config --extension-suffix`
