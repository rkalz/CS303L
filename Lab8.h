#pragma once
#include "Lab7.h"

enum COLOR {
	RED,
	BLACK,
};

template <typename T>
struct TreeNodeRB : TreeNode {
	long long key;
	TreeNodeRB<T>* left;
	TreeNodeRB<T>* right;
	TreeNodeRB<T>* p;
	T val;
	COLOR color;

	TreeNodeRB<T>(long long k, T v) :
		key(k), val(v), left(nullptr), right(nullptr), p(nullptr)
	{}
};

template <typename T>
struct Tree {
	TreeNodeRB<T>* root;
	TreeNodeRB<T>* nil;

	Tree() : nil(new TreeNodeRB<T>(-1, NULL))
	{
		root = nil;
		nil->color = BLACK;
		nil->left = nil;
		nil->right = nil;
		nil->p = nil;
	}
};

template <typename C>
void leftRotate(Tree<C> &T, TreeNodeRB<C>* x)
{
	TreeNodeRB<C>* y = x->right;
	x->right = y->left;
	if (y->left != T.nil) y->left->p = x;
	y->p = x->p;
	if (x->p == T.nil) T.root = y;
	else if (x == x->p->left) x->p->left = y;
	else x->p->right = y;
	y->left = x;
	x->p = y;
}

template <typename C>
void rightRotate(Tree<C> &T, TreeNodeRB<C>* x)
{
	TreeNodeRB<C>* y = x->left;
	x->left = y->right;
	if (y->right != T.nil) y->right->p = x;
	y->p = x->p;
	if (x->p == T.nil) T.root = y;
	else if (x == x->p->left) x->p->left = y;
	else x->p->right = y;
	y->right = x;
	x->p = y;
}

template <typename C>
void rbInsertFixup(Tree<C> &T, TreeNodeRB<C>* &z)
{
	while (z->p->color == RED)
	{
		if (z->p == z->p->p->left)
		{
			TreeNodeRB<C>* y = z->p->p->right;
			if (y->color == RED)
			{
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else if (z == z->p->right)
			{
				z = z->p;
				leftRotate(T, z);
			}
			else
			{
				z->p->color = BLACK;
				z->p->p->color = RED;
				rightRotate(T, z->p->p);
			}
		}
		else
		{
			TreeNodeRB<C>* y = z->p->p->left;
			if (y->color == RED)
			{
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else if (z == z->p->left)
			{
				z = z->p;
				rightRotate(T, z);
			}
			else
			{
				z->p->color = BLACK;
				z->p->p->color = RED;
				leftRotate(T, z->p->p);
			}
		}
	}
	T.root->color = BLACK;
}

template <typename C>
void rbInsert(Tree<C> &T, TreeNodeRB<C>* &z)
{
	z->left = T.nil;
	z->right = T.nil;
	z->p = T.nil;

	if (T.root == T.nil)
	{
		T.root = z;
	}
	else
	{
		TreeNodeRB<C>* y = T.nil;
		TreeNodeRB<C>* x = T.root;
		while (x != T.nil)
		{
			y = x;
			if (z->key < x->key) x = x->left;
			else x = x->right;
		}
		z->p = y;
		if (y == T.nil) T.root = z;
		else if (z->key < y->key) y->left = z;
		else y->right = z;
		z->color = RED;
		rbInsertFixup(T, z);
	}
}

template <typename C>
std::vector<TreeNodeRB<C>*> populateRBTree(Tree<C> &T, std::vector<Item>* items)
{
	std::cout << "Populating binary tree... ";
	std::vector<TreeNodeRB<std::string*>*> ptrs;
	auto start = std::chrono::high_resolution_clock::now();
	while (!items->empty())
	{
		Item i = items->back();
		std::string* s = new std::string(i.unit + ", " + i.desc);
		TreeNodeRB<std::string*>* node = new TreeNodeRB<std::string*>(stoll(i.key), s);
		rbInsert(T, node);
		ptrs.emplace_back(node);
		items->pop_back();
	}
	delete items;
	auto end = std::chrono::high_resolution_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Added " << ptrs.size() << " objects in " << diff << " milliseconds (" << log10(diff) << ")" << std::endl;
	return ptrs;
}

template <typename C>
TreeNodeRB<C>* treeSearch(TreeNodeRB<C>* x, long long k)
{
	if (x == nullptr || x->key == k) return x;
	if (k < x->key) return treeSearch(x->left, k);
	else return treeSearch(x->right, k);
}

template <typename C>
TreeNodeRB<C>* iterativeTreeSearch(TreeNodeRB<C>* x, long long k)
{
	while (x != nullptr && k != x->key)
	{
		if (k < x->key) x = x->left;
		else x = x->right;
	}

	return x;
}

template <typename C>
void searchQueries(Tree<C> T, std::string f)
{
	std::cout << std::endl;
	std::ifstream input(f);
	std::string s;
	while (std::getline(input, s, '\n')) // search for each item in .dat file
	{
		std::stringstream stream(s);
		std::string id;
		std::getline(stream, id, ',');
		std::string unit;
		std::getline(stream, unit, ',');
		std::string desc;
		std::getline(stream, desc, ',');

		std::cout << "Searching for " << id << ": " << unit << ", " << desc << std::endl;
		std::cout << "Recursive Search:" << std::endl;
		auto start = std::chrono::high_resolution_clock::now();
		TreeNodeRB<C>* res = treeSearch(T.root, std::stoll(id)); // Recursive search
		if (res == nullptr) std::cout << "Not found" << std::endl;
		else std::cout << "Found         " << res->key << ": " << *(res->val) << std::endl;
		auto end = std::chrono::high_resolution_clock::now();
		auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << "Took " << diff << " microseconds (" << log10(diff) << ")" << std::endl;

		std::cout << "Iterative Search:" << std::endl;
		start = std::chrono::high_resolution_clock::now();
		res = iterativeTreeSearch(T.root, std::stoll(id)); // Iterative search
		if (res == nullptr) std::cout << "Not found" << std::endl;
		else std::cout << "Found         " << res->key << ": " << *(res->val) << std::endl;
		end = std::chrono::high_resolution_clock::now();
		diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << "Took " << diff << " microseconds (" << log10(diff) << ")" << std::endl;

		std::cout << std::endl;
	}
	input.close();
}

template <typename C>
void deleteRBTree(Tree<C> &T)
{
	std::cout << "Deleting Red Black Search Tree... ";
	auto start = std::chrono::high_resolution_clock::now();
	delete T.root;
	auto end = std::chrono::high_resolution_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cout << "Took " << diff << " milliseconds (" << log10(diff) << ")" << std::endl;
}

