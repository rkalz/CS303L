#include "Lab9.h"

void lab9_main()
{
	std::cout << "Generating map... ";
	auto start = std::chrono::high_resolution_clock::now();
	MyHashMap map;
	std::ifstream upc("UPC-random.csv");
	std::string s;
	while (std::getline(upc, s, '\n')) // get items from csv file and put them in Item vector
	{
		std::istringstream stream(s);
		std::string id;
		std::getline(stream, id, ',');
		std::string unit;
		std::getline(stream, unit, ',');
		std::string desc;
		std::getline(stream, desc, ',');

		map.put(std::stoll(id), unit + ", " + desc);
	}
	upc.close();
	auto end = std::chrono::high_resolution_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Done in " << diff << " microseconds (" << log10(diff) << ")" << std::endl;

	std::ifstream search("input.dat");
	while (std::getline(search, s, '\n')) // search for each item in .dat file
	{
		std::stringstream stream(s);
		std::string id;
		std::getline(stream, id, ',');
		std::string unit;
		std::getline(stream, unit, ',');
		std::string desc;
		std::getline(stream, desc, ',');

		std::cout << unit << ", " << desc << std::endl;
		start = std::chrono::high_resolution_clock::now();
		std::cout << map.get(std::stoll(id)) << std::endl;
		end = std::chrono::high_resolution_clock::now();
		diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << "Done in " << diff << " microseconds (" << log10(diff) << ")" << std::endl;
		std::cout << std::endl;
	}
	search.close();

	system("pause");
}