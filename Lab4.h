#pragma once

#include "Lab3.h"

void heapSort(std::vector<double>& data);
void buildMaxHeap(std::vector<double>& data);
void maxHeapify(std::vector<double>& data, int i, int heapSize);
