#pragma once

#include "Lab4.h"

void quickSort(std::vector<double>& a, int p, int r);
int partition(std::vector<double>& a, int p, int r);

void quickSortMedian(std::vector<double>& a, int p, int r);
int medianOfThree(std::vector<double> a, int i, int j, int k);