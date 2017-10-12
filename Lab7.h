#pragma once
#include "imports.h"

struct Item {
	std::string key;
	std::string unit;
	std::string desc;

	Item(std::string k, std::string u, std::string d) : key(k), unit(u), desc(d) {}
};

struct TreeNode {
	unsigned long long key; // used due to size of UPC in file (maxed at 10^10, unsigned long maxed at 10^9, rest are smaller)
	std::string desc;
	TreeNode* left;
	TreeNode* right;

	TreeNode(unsigned long long k, std::string d) : key(k), desc(d), left(nullptr), right(nullptr) {}
};

void treeInsert(TreeNode* x, unsigned long long k, std::string d, std::vector<TreeNode*>& ptrs);
void inOrderTreeWalk(TreeNode* x);
TreeNode* treeSearch(TreeNode* x, unsigned long long k);
TreeNode* iterativeTreeSearch(TreeNode* x, unsigned long long k);
void deleteTree(std::vector<TreeNode*>& ptrs);
