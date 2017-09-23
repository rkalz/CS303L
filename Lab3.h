#pragma once

#include "imports.h"
#include "Lab2.h"

void mergeSort(std::vector<double>& data, std::vector<double>& temp, int start, int end);
void merge(std::vector<double>& data, std::vector<double>& temp, int start, int mid, int end);
void sort(std::vector<double> & data);
