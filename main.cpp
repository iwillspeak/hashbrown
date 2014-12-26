#include <iostream>
#include <iomanip>
#include <cstdlib>

uint64_t fnv(const std::string& str);
uint64_t jenkins(const std::string& str);
uint64_t djb(const std::string& str);
uint64_t lose_lose(const std::string& str);

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
	print_res("lose_lose", lose_lose(str));
}

extern "C"
int main(int argc, const char* argv[])
{
	for (int i = 1; i < argc; i++)
	{
		print_hash(argv[i]);
	}
}
