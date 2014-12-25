#include <iostream>
#include <iomanip>
#include <cstdlib>

// an implementation of the FNV 1A hash function, as described at
// http://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function
uint64_t fnv(const std::string& str)
{
	static const uint64_t fnv_bias = 0xcbf29ce484222325;
	static const uint64_t fnv_prime = 0x100000001b3;

	uint64_t hash = fnv_bias;

	// mix in each character from the string
	for (auto oct : str) {
		hash ^= oct;
		hash *= fnv_prime;
	}

	return hash;
}

// an implementation of the Jenkins hash funciton, as described at
// http://en.wikipedia.org/wiki/Jenkins_hash_function
uint64_t jenkins(const std::string& str)
{
	uint64_t hash = 0;

	// mix in each character from the string
	for (auto oct : str)
	{
		hash += oct;
		hash += hash << 10;
		hash ^= hash >> 6;
	}
	
	// final shuffle
	hash += hash << 3;
	hash ^= hash >> 11;
	hash += hash << 15;
	
	return hash;
}

// Implementation of the DJB hash
uint64_t djb(const std::string& str)
{
	uint64_t hash = 5381;

	// mix in each octet
	for (auto oct : str)
	{
		hash += hash << 5;
		hash += oct;
	}

	return hash;
}

void print_res(const std::string name, uint64_t hash)
{
	std::cout << std::setw(20) << std::setfill(' ') << name;
	std::cout << " : ";
	std::cout << std::hex << std::setw(16) << std::setfill('0') << 
		hash << std::endl;
}

void print_hash(const std::string& str)
{
	std::cout << '\n' << str << std::endl;
	print_res("FNV", fnv(str));
	print_res("Jenkins", jenkins(str));
	print_res("DJB", djb(str));
}

extern "C"
int main(int argc, const char* argv[])
{
	for (int i = 1; i < argc; i++)
	{
		print_hash(argv[i]);
	}
}
