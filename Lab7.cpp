#include "Lab7.h"

void main()
{
	// Read from UPC.csv, group into Item structs, add to vector, and randomize order
	std::ifstream upc("UPC.csv");
	std::vector<Item>* items  = new std::vector<Item>();
	std::string s;
	std::cout << "Reading data from file... ";
	auto start = std::chrono::high_resolution_clock::now();
	while (std::getline(upc, s,'\r')) // get items from csv file and put them in Item vector
	{
		std::istringstream stream(s);
		std::string id;
		std::getline(stream, id, ',');
		std::string unit; 
		std::getline(stream, unit, ',');
		std::string desc;
		std::getline(stream, desc, ',');

		items->emplace_back(Item(id, unit, desc));
	}
	//std::random_shuffle(items->begin(), items->end()); // since file ids ordered, shuffle to prevent linked list behavior
	upc.close();
	auto end = std::chrono::high_resolution_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cout << "Read " << items->size() << " objects in " << diff << " milliseconds (" << log10(diff) << ")" << std::endl;
	
	// Build BST from contents of item array
	TreeNode* root = nullptr;
	std::vector<TreeNode*> ptrs; // = new std::vector<TreeNode*>();  // store the pointers here for quick deletion at the end
	std::cout << "Generating Binary Search Tree... ";
	start = std::chrono::high_resolution_clock::now();
	while (!items->empty()) // place array items into binary search tree
	{
		Item i = items->back();
		if (root == nullptr)
		{
			root = new TreeNode(std::stoull(i.key), i.unit + "," + i.desc);
			ptrs.emplace_back(root);
		}
		else treeInsert(root, std::stoull(i.key), i.unit + "," + i.desc, ptrs);
		items->pop_back();
	}
	delete items;
	end = std::chrono::high_resolution_clock::now();
	diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cout << "Added " << ptrs.size() << " objects in " << diff << " milliseconds (" << log10(diff) << ")" << std::endl;
	
	// Search for queries read in from input.dat using both search methods
	std::cout << std::endl;
	std::ifstream input("input.dat");
	while (std::getline(input, s, '\n')) // search for each item in .dat file
	{
		std::stringstream stream(s);
		std::string id;
		std::getline(stream, id, ',');
		std::string unit;
		std::getline(stream, unit, ',');
		std::string desc;
		std::getline(stream, desc, ',');

		std::cout << "Searching for " << id << ": " << unit << "," << desc << std::endl;
		std::cout << "Recursive Search:" << std::endl; // Recursive search
		start = std::chrono::high_resolution_clock::now();
		TreeNode* res = treeSearch(root, std::stoull(id));
		if (res == nullptr) std::cout << "Not found" << std::endl;
		else std::cout << "Found         " << res->key << ": " << res->desc << std::endl;
		end = std::chrono::high_resolution_clock::now();
		diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << "Took " << diff << " microseconds (" << log10(diff) << ")" << std::endl;

		std::cout << "Iterative Search:" << std::endl; // Iterative search
		start = std::chrono::high_resolution_clock::now(); 
		res = iterativeTreeSearch(root, std::stoull(id));
		if (res == nullptr) std::cout << "Not found" << std::endl;
		else std::cout << "Found         " << res->key << ": " << res->desc << std::endl;
		end = std::chrono::high_resolution_clock::now();
		diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << "Took " << diff << " microseconds (" << log10(diff) << ")" << std::endl;

		std::cout << std::endl;
	}
	input.close();

	// Delete each node because they were dynamically allocated
	std::cout << "Deleting Binary Search Tree... ";
	start = std::chrono::high_resolution_clock::now();
	deleteTree(ptrs);
	end = std::chrono::high_resolution_clock::now();
	diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cout << "Took " << diff << " milliseconds (" << log10(diff) << ")" << std::endl;
	system("pause");
}

// Inserts new node into the tree with root x
void treeInsert(TreeNode* x, unsigned long long k, std::string d, std::vector<TreeNode*>& ptrs)
{
	TreeNode* z = new TreeNode(k,d);
	TreeNode* y = nullptr;
	while (x != nullptr)
	{
		y = x;
		if (z->key < x->key) x = x->left;
		else x = x->right;
	}

	if (y == nullptr) x = z;
	else if (z->key < y->key) y->left = z;
	else y->right = z;

	ptrs.push_back(z); // Added for tracking to delete when done
}

// Traverses the tree in order. For BST, this should be in sorted order
void inOrderTreeWalk(TreeNode* x)
{
	if (x != nullptr)
	{
		inOrderTreeWalk(x->left);
		std::cout << x->key << " ";
		inOrderTreeWalk(x->right);
	}
}

// Recursively searches a tree from node x, log(n), where n = number of nodes
TreeNode* treeSearch(TreeNode* x, unsigned long long k)
{
	if (x == nullptr || x->key == k) return x;
	if (k < x->key) return treeSearch(x->left, k);
	else return treeSearch(x->right, k);
}

// Iteratively searches a tree from root x, log(n), where n = number of nodes
TreeNode* iterativeTreeSearch(TreeNode* x, unsigned long long k)
{
	while (x != nullptr && k != x->key)
	{
		if (k < x->key) x = x->left;
		else x = x->right;
	}

	return x;
}

// deletes all nodes stored in the passed vector (post traversal deletion causes stack overflow)
void deleteTree(std::vector<TreeNode*>& ptrs)
{
	while (!ptrs.empty())
	{
		delete ptrs.back();
		ptrs.pop_back();
	}
}


