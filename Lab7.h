#pragma once
#include "imports.h"

// Intermediate to store data after being read in from file
struct Item {
	std::string key;
	std::string unit;
	std::string desc;

	Item(std::string k, std::string u, std::string d) : key(k), unit(u), desc(d) {}
};

// Node in a binary tree
struct TreeNode {
	unsigned long long key; // used due to size of UPC in file (maxed at 10^10, unsigned long maxed at 10^9, rest are smaller)
	std::string desc;
	TreeNode* left;
	TreeNode* right;

	TreeNode(unsigned long long k, std::string d) : key(k), desc(d), left(nullptr), right(nullptr) {}
};

// Used to manipulate and go through BST
void treeInsert(TreeNode* x, unsigned long long k, std::string d, std::vector<TreeNode*> &ptrs);
void inOrderTreeWalk(TreeNode* x); // Not used
TreeNode* treeSearch(TreeNode* x, unsigned long long k);
TreeNode* iterativeTreeSearch(TreeNode* x, unsigned long long k);

// Used for the specific problem
std::vector<Item>* loadFile(std::string f);
std::vector<TreeNode*> generateBST(TreeNode* &root, std::vector<Item>* &items);
void searchQueries(TreeNode* root, std::string f);
void deleteTree(std::vector<TreeNode*> &ptrs);
