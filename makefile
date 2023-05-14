linux:
	g++ -o test test.cpp -I./include -llua
	g++ -Wall -shared -fPIC -o test_lib.so test_lib.cpp -I./include -llua