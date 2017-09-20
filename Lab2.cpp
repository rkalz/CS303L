#include "imports.h"

void insertionSort(std::vector<double>& data);

void lab2_main()
{
	std::vector<std::string> files;
	files.push_back("input_100.txt");
	files.push_back("input_1000.txt");
	files.push_back("input_5000.txt");
	files.push_back("input_10000.txt");
	files.push_back("input_50000.txt");
	files.push_back("input_100000.txt");
	files.push_back("input_500000.txt");

	for (std::string path : files)
	{
		std::ifstream file(path);
		std::vector<double> data;
		double v;
		while (file >> v) data.push_back(v);
		file.close();

		std::cout << data.size() << ": ";
		auto start = std::chrono::high_resolution_clock::now();
		insertionSort(data);
		auto end = std::chrono::high_resolution_clock::now();

		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "mus, ";
		std::cout << log10(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) << std::endl;
	}
	system("pause");
}

void insertionSort(std::vector<double>& data)
{
	for (int j = 1; j < data.size(); j++)
	{
		double key = data.at(j);
		int i = j - 1;
		while (i >= 0 && data.at(i) > key)
		{
			data.at(i + 1) = data.at(i);
			i--;
		}
		data.at(i + 1) = key;
	}
}

