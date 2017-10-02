#include "Lab5.h"

void main()
{
	std::vector<std::string> paths;
	for (int i = 4; i <= 13; i++) paths.push_back("input_" + std::to_string((int)(pow(2, i))) + ".txt");

	for (std::string path : paths)
	{
		std::ifstream file(path);
		double v = 0;
		std::vector<double> quick;
		while (file >> v) quick.push_back(v);
		file.close();

		std::vector<double> insert = quick;
		std::vector<double> merge = quick;
		std::vector<double> heap = quick;

		std::cout << quick.size() << std::endl;
		
		std::cout << "\tInsertion Sort: ";
		auto start = std::chrono::high_resolution_clock::now();
		insertionSort(insert);
		auto end = std::chrono::high_resolution_clock::now();
		auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << diff << "mus (" << log10(diff) << ")" << std::endl;

		std::cout << "\tMerge Sort: ";
		std::vector<double> temp = merge;
		start = std::chrono::high_resolution_clock::now();
		mergeSort(merge, temp, 0, merge.size() - 1);
		end = std::chrono::high_resolution_clock::now();
		diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << diff << "mus (" << log10(diff) << ")" << std::endl;

		std::cout << "\tHeap Sort: ";
		start = std::chrono::high_resolution_clock::now();
		heapSort(heap);
		end = std::chrono::high_resolution_clock::now();
		diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << diff << "mus (" << log10(diff) << ")" << std::endl;

		std::cout << "\tQuick Sort: ";
		start = std::chrono::high_resolution_clock::now();
		quickSort(quick, 0, heap.size() - 1);
		end = std::chrono::high_resolution_clock::now();
		diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << diff << "mus (" << log10(diff) << ")" << std::endl;

		std::cout << std::endl;

	}
	system("pause");
}

void quickSort(std::vector<double>& a, int p, int r)
{
	if (p < r)
	{
		int q = partition(a, p, r);
		quickSort(a, p, q - 1);
		quickSort(a, q + 1, r);
	}
}

int partition(std::vector<double>& a, int p, int r)
{
	double x = a.at(r);
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (a.at(j) <= x)
		{
			i++;
			double tmp = a.at(i);
			a.at(i) = a.at(j);
			a.at(j) = tmp;
		}
	}
	double tmp = a.at(i + 1);
	a.at(i + 1) = a.at(r);
	a.at(r) = tmp;
	return i + 1;
}

void quickSortMedian(std::vector<double>& a, int p, int r)
{
	if (p < r)
	{
		int n = r - p + 1;
		int m = medianOfThree(a, p, p + (n / 2), r);

		double tmp = a.at(m);
		a.at(m) = a.at(r);
		a.at(r) = tmp;

		int q = partition(a, p, r);
		quickSortMedian(a, p, q - 1);
		quickSortMedian(a, q + 1, r);
	}
}

int medianOfThree(std::vector<double> a, int i, int j, int k)
{
	int mid = a.size() / 2;
	if (i == mid) return i;
	if (k == mid) return k;
	return j;
}