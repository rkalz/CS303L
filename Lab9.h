#pragma once

#include "imports.h"

class MyHashMap {
private:
	struct HashElement {
		long long key;
		std::string val;

		HashElement(long long k, std::string &v) : key(k), val(v) {}
	};
	std::vector<HashElement*> map;
	int getHash(long long key) { return key % 200000; }

public:
	MyHashMap() { map.resize(200000, 0); }

	~MyHashMap() { for (int i = 0; i < 200000; i++) delete map[i]; }

	void put(long long k, std::string &v)
	{
		HashElement* element = new HashElement(k, v);
		int hash = getHash(k);

		if (map[hash] == nullptr) { map[hash] = element; }
		else
		{
			int newHash = hash;
#ifdef LINEAR
			// Add one to hash until we find an opening. If we get to the end, wipe over.
			while (newHash < 200000 && map[newHash] != nullptr) newHash++;
#elif QUAD
			// Same as before, except add n^2 to hash until we find opening.
			int n = 1;
			while ((hash + (int)pow(n, 2)) < 200000 && map[hash + (int)pow(n, 2)] != nullptr) n++;
			newHash = hash + (int)pow(n, 2);
#else
			// Multiply previous hash by 7 and add 1.
			while (newHash < 200000 && map[newHash] != nullptr) newHash = 7*newHash + 1;
#endif
			if (newHash < 200000) { map[newHash] = element; }
			else { map[hash] = element; }
		}
	}

	std::string get(long long key)
	{
		int hash = getHash(key);
		if (map[hash] == nullptr) return "Key not found";
		if (map[hash]->key == key) return map[hash]->val;
		else
		{
			int newHash = hash;
#ifdef LINEAR
			// Add one to hash until we find desired key or reach the end
			while (newHash < 200000 && map[newHash]->key != key) newHash++;
#elif QUAD
			// Same as linear, but add n^2 
			int n = 1;
			while ((hash + (int)pow(n, 2)) < 200000 && map[hash + (int)pow(n, 2)]->key != key) n++;
			newHash = hash + (int)pow(n, 2);
#else
			// Multiply original hash by 7 and add 1
			while (newHash < 200000 && map[newHash]->key != key) newHash = 7 * newHash + 1;
#endif
			if (newHash < 200000) return map[newHash]->val;
			else return "Key not found";
		}
	}
};