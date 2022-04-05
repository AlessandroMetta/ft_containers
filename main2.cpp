#include <map>
#include <iostream>

int main()
{
    std::map<std::string, std::string> dictionary;
    dictionary.insert(std::make_pair("ciao", "saluto comune"));
    dictionary.insert(std::make_pair("ciao", "saluto"));
    std::cout  << dictionary["ciao"] << std::endl;
}