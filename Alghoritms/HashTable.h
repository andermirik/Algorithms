#pragma once
#include "string.h"
#include <functional>
namespace HT {
	struct ChainNode {
		ChainNode(int info) {
			this->info = info;
			next = nullptr;
		}
		int info;
		ChainNode*next;
	};
	struct Node {
		ChainNode* chain_start;
	};

	namespace HF {
		int hash_SQ(int key, int size) {
			return key*key / 100 % (size);
		}
		int hash_Convol(int key, int size) {
			int s = 0;
			while (key > 0) {
				s += key % 1000;
				key /= 1000;
			}
			return s % size;
		}
		int hash_mod(int key, int size) {
			return key % size;
		}
	}

}

void destruct_list(HT::ChainNode *list)
{
	HT::ChainNode *i = list;
	HT::ChainNode *del_elem;

	while (i != NULL)
	{
		del_elem = i;
		i = i->next;

		delete del_elem;
	}
}

class HashTable {
private: HT::Node*vector;
private: int size;
private: std::function<int(int, int)> hash_function;

private: void resize(int new_size) {
	if (new_size >= size) {
		HT::Node* new_vector = new HT::Node[new_size];

		for (int i = 0; i < new_size; i++) {
			new_vector[i].chain_start = nullptr;
		}
		for (int i = 0; i < size; i++) {
			new_vector[i] = vector[i];
		}
		vector = new_vector;
		size = new_size;
	}
}
public: HashTable(int base_size,std::function<int(int, int)> hash_function) {
	vector = nullptr;
	size = 0;
	this->hash_function = hash_function;
	resize(base_size);
}

public:void AddElement(int key) {
	int hf = hash_function(key, size);
	if (!vector[hf].chain_start) {
		vector[hf].chain_start = new HT::ChainNode(key);
	}
	else {
		auto it = vector[hf].chain_start;
		while (it->next) {
			it = it->next;
		}
		it->next = new HT::ChainNode(key);
	}
}

public: HT::ChainNode* Search(int key) {
	int ht = hash_function(key, size);
	return vector[ht].chain_start;
}
public: void Delete(int key) {
	int ht = hash_function(key, size);
	auto it = vector[ht].chain_start;
	if (it) {
		auto temp = it;
		vector[ht].chain_start = it->next;
		delete temp;
	}
}
public: void print() {
	std::cout << "printed:\n";
	for (int i = 0; i < size; i++) {
		if (vector[i].chain_start) {
			std::printf("%3d:%5d\n", i, vector[i].chain_start->info);
			if (vector[i].chain_start->next) {
				auto it = vector[i].chain_start->next;
				if (it->next) {
					while (it) {
						printf("   :%5d\n", it->info);
						it = it->next;
					}
				}
			}
		}
	}
}

public: ~HashTable() {
	for (int i = 0; i < size; i++) {
		destruct_list(vector[i].chain_start);
	}
	delete vector;
}
};