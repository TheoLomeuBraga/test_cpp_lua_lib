#include <iostream>
#include <sstream>
#include <string>

template <typename X>
std::string ponteiro_string(X *p)
{
	std::stringstream ss;
	ss << p;
	return ss.str();
}

template <typename X>
X *string_ponteiro(std::string s)
{
	std::stringstream ss(s);
	void *ret = NULL;
	ss >> ret;
	return (X *)ret;
}

class animal{
public:
    animal(){}
    void barulho(){std::cout << "miau\n";}
};