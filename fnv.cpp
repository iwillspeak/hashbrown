#include <cstdlib>
#include <string>

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

