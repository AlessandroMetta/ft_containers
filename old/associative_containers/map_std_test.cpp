#include <iostream>
#include <map>

int main()
{
	typedef int									key_type;
	typedef int									mapped_type;
	typedef std::map < key_type, mapped_type >	map_type;
	typedef std::pair< key_type, mapped_type >	pair_type;

    map_type alice;
	alice.insert(pair_type(1, 'a'));
	alice.insert(pair_type(2, 'b'));
	alice.insert(pair_type(3, 'c'));

    map_type bob;
	bob.insert(pair_type(7, 'Z'));
	bob.insert(pair_type(8, 'Y'));
	bob.insert(pair_type(9, 'X'));
	bob.insert(pair_type(10, 'W'));
	
    map_type eve;
	eve.insert(pair_type(1, 'a'));
	eve.insert(pair_type(2, 'b'));
	eve.insert(pair_type(3, 'c'));

 
    std::cout << std::boolalpha;
 
    // Compare non equal containers
    std::cout << "alice == bob returns " << (alice == bob) << '\n';
    std::cout << "alice != bob returns " << (alice != bob) << '\n';
    std::cout << "alice <  bob returns " << (alice < bob) << '\n';
    std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
    std::cout << "alice >  bob returns " << (alice > bob) << '\n';
    std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
 
    std::cout << '\n';
 
    // Compare equal containers
    std::cout << "alice == eve returns " << (alice == eve) << '\n';
    std::cout << "alice != eve returns " << (alice != eve) << '\n';
    std::cout << "alice <  eve returns " << (alice < eve) << '\n';
    std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
    std::cout << "alice >  eve returns " << (alice > eve) << '\n';
    std::cout << "alice >= eve returns " << (alice >= eve) << '\n';

	return 0;
}