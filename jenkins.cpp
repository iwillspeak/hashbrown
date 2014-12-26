#include <cstdlib>
#include <string>

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
