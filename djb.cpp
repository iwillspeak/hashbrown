#include <cstdlib>
#include <string>

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
