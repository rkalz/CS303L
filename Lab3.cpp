#include "Lab2.h"

#include <random>

void mergeSort(std::vector<double>& data, std::vector<double>& temp, int start, int end);
void merge(std::vector<double>& data, std::vector<double>& temp, int start, int mid, int end);
void sort(std::vector<double> & data);

void main()
{

#if 0
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

		std::vector<double> toMerge = data;
		std::vector<double> temp = toMerge;
		auto start = std::chrono::high_resolution_clock::now();
		mergeSort(toMerge, temp, 0, data.size() - 1);
		auto end = std::chrono::high_resolution_clock::now();
		auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		
		std::cout << temp.size() << ": Merge: ";
		std::cout << diff << "mus (";
		std::cout << log10(diff) << "), Insertion: ";

		start = std::chrono::high_resolution_clock::now();
		insertionSort(data);
		end = std::chrono::high_resolution_clock::now();
		diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

		std::cout << diff << "mus (";
		std::cout << log10(diff) << ")" << std::endl;

	}
#endif

#if 1
	std::ofstream output;
	output.open("results.csv");
	output << "Size, Merge Time (microseconds), Log Merge log(mus), Insertion Time(microseconds), Log Insertion log(mus),\n";

	for (int i = 100; i <= 1000; i++)
	{
		std::vector<double> v;
		std::uniform_real_distribution<double> dist(0, i);
		std::mt19937 rng;
		rng.seed(std::random_device{}());

		for (int j = 0; j < i; j++) v.push_back(dist(rng));

		std::vector<double> toMerge = v;
		std::vector<double> temp = toMerge;
		auto start = std::chrono::high_resolution_clock::now();
		mergeSort(toMerge, temp, 0, temp.size() - 1);
		auto end = std::chrono::high_resolution_clock::now();
		auto diff1 = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

		start = std::chrono::high_resolution_clock::now();
		insertionSort(v);
		end = std::chrono::high_resolution_clock::now();
		auto diff2 = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

		if (diff2 > diff1)
		{
			std::cout << temp.size() << ": Merge: ";
			std::cout << diff1 << "mus (";
			std::cout << log10(diff1) << "), Insertion: ";
			std::cout << diff2 << "mus (";
			std::cout << log10(diff2) << ")" << std::endl;
		}

		output << temp.size() << ", " << diff1 << ", " << log10(diff1) << ", " << diff2 << ", " << log10(diff2) << ",\n";
	}

	output.close();
#endif

	system("pause");
}

void mergeSort(std::vector<double>& data, std::vector<double>& temp, int start, int end)
{
	if (start < end)
	{
		int mid = floor((start + end) / 2);
		mergeSort(data, temp, start, mid);
		mergeSort(data, temp, mid + 1, end);
		merge(data, temp, start, mid, end);
	}
}

void merge(std::vector<double>& data, std::vector<double>& temp, int start, int mid, int end)
{
	int i = start;
	int j = mid + 1;

	for (int k = start; k <= end; k++) // copy contents of data into temp
	{
		temp[k] = data[k];
	}

	// i is left half, j is right half
	for (int k = start; k <= end; k++)
	{
		if (i > mid) // left is empty, copy in from right
		{
			data[k] = temp[j];
			j++;
		}
		else if (j > end) // right is empty, copy in from left
		{
			data[k] = temp[i];
			i++;
		}
		else if (temp[j] < temp[i]) // copy in from right
		{
			data[k] = temp[j];
			j++;
		}
		else
		{
			data[k] = temp[i]; // copy in from left
			i++;
		}
	}
}

void sort(std::vector<double>& data)
{
	if (data.size() < 300) insertionSort(data);
	else {
		std::vector<double> copy = data;
		mergeSort(data, copy, 0, data.size() - 1);
	}
}