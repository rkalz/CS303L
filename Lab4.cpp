#include "Lab4.h"

void main_4()
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

		std::cout << "Insertion Sort: ";
		std::vector<double> insert = data;
		auto start = std::chrono::high_resolution_clock::now();
		insertionSort(data);
		auto end = std::chrono::high_resolution_clock::now();
		auto ins = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << ins << "mus (";
		std::cout << log10(ins);
		std::cout << "), ";

		std::cout << "Merge Sort: ";
		std::vector<double> merge = data;
		std::vector<double> temp = merge;
		start = std::chrono::high_resolution_clock::now();
		mergeSort(merge, temp, 0, temp.size() - 1);
		end = std::chrono::high_resolution_clock::now();
		auto mrge = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << mrge << "mus (";
		std::cout << log10(mrge);
		std::cout << "), ";

		std::cout << "Heap Sort: ";
		start = std::chrono::high_resolution_clock::now();
		heapSort(data);
		end = std::chrono::high_resolution_clock::now();
		auto heap = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << heap << "mus (";
		std::cout << log10(heap);
		std::cout << ")";

		std::cout << std::endl;
		
	}


	system("pause");
}

void heapSort(std::vector<double>& data)
{
	int size = data.size()-1;
	buildMaxHeap(data);
	for (int i = data.size() - 1; i >= 0; i--)
	{
		double temp = data.at(0);
		data.at(0) = data.at(i);
		data.at(i) = temp;
		size--;
		maxHeapify(data, 0, size);
	}
	
}

void buildMaxHeap(std::vector<double>& data)
{
	for (int i = floor(data.size() - 1 / 2); i >= 0; i--) maxHeapify(data, i, data.size()-1);
}

void maxHeapify(std::vector<double>& data, int i, int heapSize)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left <= heapSize && data.at(left) > data.at(i)) largest = left;
	else largest = i;
	if (right <= heapSize && data.at(right) > data.at(largest)) largest = right;
	if (largest != i)
	{
		double tmp = data.at(i);
		data.at(i) = data.at(largest);
		data.at(largest) = tmp;
		maxHeapify(data, largest, heapSize);
	}
}