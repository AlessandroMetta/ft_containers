#include "vector.hpp"
#include <vector>
#include <iostream>
#include <iomanip>

#define NC "\033[0m"
#define RED(x) "\033[31m" x NC
#define GR "\033[32m"
#define CY "\033[36m"

template<typename T, typename T2>
void	print(T it, T ite, T2 _it, T2 _ite, std::string testName)
{
	std::cout << std::setfill(' ') << std::setw(testName.size() + 5 + 6) << CY << "FT_VECTOR: " << NC;
	for ( ; it != ite; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::setfill(' ') << std::setw(testName.size() + 5) << "/" << std::endl;
	std::cout << GR <<testName << NC << " ->" << std::endl;
	std::cout << std::setfill(' ') << std::setw(testName.size() + 5) << "\\" << std::endl;
	std::cout << std::setfill(' ') << std::setw(testName.size() + 5 + 6) << CY << "VECTOR:    " << NC;
	for ( ; _it != _ite; ++_it)
		std::cout << *_it << " ";
	std::cout << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;
}

int		main(void)
{
	ft::vector<int> prova1;
	std::vector<int> _prova1;

	prova1.assign(10, 5);
	_prova1.assign(10, 5);
	print(prova1.begin(), prova1.end(), _prova1.begin(), _prova1.end(), "ASSIGN");

	// prova1.erase(prova1.begin());
	// _prova1.erase(_prova1.begin());
	// print(prova1.begin(), prova1.end(), _prova1.begin(), _prova1.end(), "ERASE");

	prova1.insert(prova1.begin(), 10);
	_prova1.insert(_prova1.begin(), 10);
	print(prova1.begin(), prova1.end(), _prova1.begin(), _prova1.end(), "INSERT");

	prova1.pop_back();
	_prova1.pop_back();
	print(prova1.begin(), prova1.end(), _prova1.begin(), _prova1.end(), "POP_BACK");

	prova1.push_back(500);
	_prova1.push_back(500);
	print(prova1.begin(), prova1.end(), _prova1.begin(), _prova1.end(), "PUSH_BACK");

	prova1.resize(3);
	_prova1.resize(3);
	print(prova1.begin(), prova1.end(), _prova1.begin(), _prova1.end(), "RESIZE");

	ft::vector<int> prova2;
	std::vector<int> _prova2;
	ft::vector<int> prova2_d;
	std::vector<int> _prova2_d;
	for(int i = 0; i < 10; ++i) {
		prova2.push_back(i + 1);
		prova2_d.push_back(i + 1 * 1000);
		_prova2.push_back(i + 1);
		_prova2_d.push_back(i + 1 * 1000);

	}
	prova2.swap(prova2_d);
	_prova2.swap(_prova2_d);
	print(prova2.begin(), prova2.end(), _prova2.begin(), _prova2.end(), "SWAP");
}
