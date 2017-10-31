#include "Lab8.h"

void main()
{
	Tree<std::string*> t;
	std::vector<Item>* items = loadFile("UPC-random.csv", false);
	std::vector<TreeNodeRB<std::string*>*> ptrs = populateRBTree(t, items);
	searchQueries(t, "input.dat");
	deleteRBTree(t);

	system("pause");
}





