#include <iostream>
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

void print_hash(const std::string& str)
{
	std::cout << '\n' << str << std::endl;
	std::cout << "     FNV: " << std::hex << fnv(str) << std::endl;
	std::cout << " jenkins: " << std::hex << jenkins(str) << std::endl;
}

extern "C"
int main(int argc, const char* argv[])
{
	for (int i = 1; i < argc; i++)
	{
		print_hash(argv[i]);
	}
}
