#include "Lab6.h"

void main()
{
	std::vector<std::string> input;
	std::ifstream file("NovelSortInput.txt");
	std::string s;
	while (file >> s) input.emplace_back(s);

	std::unordered_map<std::string, std::vector<std::string>*> map;
	std::vector<std::string> cities;
	for (int i = 1; i < input.size(); i = i+2)
	{
		std::string city = input[i - 1];
		std::string time = input[i];
		std::vector<std::string>* v;

		auto find = map.find(city);
		if (find == map.end())
		{
			cities.emplace_back(city);
			v = new std::vector<std::string>();
			map.emplace(city, v);
		}
		else v = map[city];
		v->emplace_back(time);
	}

	novelSort(cities, 0);
	auto it = map.begin();
	while (it != map.end())
	{
		novelSort(*(it->second), 1);
		it++;
	}

	std::ofstream out;
	out.open("results.txt");

	for (std::string city : cities)
	{
		auto times = map[city];
		for (std::string time : *times) out << city << " " << time << std::endl;
		delete times;
		map.erase(city);
	}
	
	system("pause");
}

void novelSort(std::vector<std::string>& data, int timeSort)
{
	int i = 0;
	int j = data.size() - 1;

	while (i <= j)
	{
		extremes result = findMinMaxPos(data, i, j, timeSort);
		swap(data, i, result.minPos);
		if (i != result.maxPos || j != result.minPos) swap(data, j, result.maxPos);
		i++;
		j--;
	}

}

extremes findMinMaxPos(std::vector<std::string> data, int a, int b, int timeSort)
{
	extremes out;
	out.minPos = a;
	out.maxPos = b;

	for (int i = a; i <= b; i++)
	{
		if (timeSort)
		{
			if (timeToNumber(data[i]) < timeToNumber(data[out.minPos])) out.minPos = i;
			else if (timeToNumber(data[i]) > timeToNumber(data[out.maxPos])) out.maxPos = i;
		}
			
		else
		{
			if (data[i].compare(data[out.minPos]) == -1) out.minPos = i;
			else if (data[i].compare(data[out.maxPos]) == 1) out.maxPos = i;
		}		
	}

	return out;
}

void swap(std::vector<std::string>& data, int a, int b)
{
	std::string temp = data[a];
	data[a] = data[b];
	data[b] = temp;
}

