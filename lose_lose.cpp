#include <cstdlib>
#include <string>

// An implementation of the 'lose lose' has from K&R's C book. This is
// intended as an example of a bad hash function.
uint64_t lose_lose(const std::string& str)
{
	uint64_t hash = 0;

	for (auto oct : str)
	{
		hash += oct;
	}

	return hash;
}
