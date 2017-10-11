#pragma once

#include "imports.h"

struct extremes {
	int minPos;
	int maxPos;
};

void novelSort(std::vector<std::string>& data, int times);
extremes findMinMaxPos(std::vector<std::string> data, int a, int b, int times);
void swap(std::vector<std::string>& data, int a, int b);
inline int timeToNumber(std::string time) { return std::stoi(time.substr(6, 8)) + (60 * std::stoi(time.substr(3, 5))) + (3600 * std::stoi(time.substr(0, 2)));  }