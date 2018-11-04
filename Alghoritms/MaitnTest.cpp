#include "Sort.h"
#include "Search.h"

#include "List.h"
#include "Graph.h"
#include "BinaryTree.h"
#include "HashTable.h"

#include "windows.h"
int TestBubbeSort(size_t count, int*arr=0) {
	int start_sorting = GetTickCount();
	//358 sec: 100k elements
	if (!arr) {
		int*test_arr = new int[count];
		for (int i = count; i >= 0; i--) {
			test_arr[count - i] = i;
		}
		Sort<int>(test_arr, count, sort::Bubble);
	}
	else {
		Sort<int>(arr, count, sort::Bubble);
	}

	return GetTickCount() - start_sorting;
}
int TestInsertionSort(size_t count, int*arr = 0) {
	int start_sorting = GetTickCount();
	//100k elements: 8.6 sec
	if (!arr) {
		int*test_arr = new int[count];
		for (int i = count; i >= 0; i--) {
			test_arr[count - i] = i;
		}
		Sort<int>(test_arr, count, sort::Insertion);
	}
	else {
		Sort<int>(arr, count, sort::Insertion);
	}

	return GetTickCount() - start_sorting;
}
int TestByChoiceSort(size_t count, int*arr = 0) {
	int start_sorting = GetTickCount();

	if (!arr) {
		int*test_arr = new int[count];
		for (int i = count; i >= 0; i--) {
			test_arr[count - i] = i;
		}
		Sort<int>(test_arr, count, sort::ByChoice);
	}
	else {	
		Sort<int>(arr, count, sort::ByChoice);
	}

	return GetTickCount() - start_sorting;
}
int TestShakerSort(size_t count, int*arr = 0) {
	int start_sorting = GetTickCount();
	//100k elements: 289 sec
	if (!arr) {
		int*test_arr = new int[count];
		for (int i = count; i >= 0; i--) {
			test_arr[count - i] = i;
		}
		Sort<int>(test_arr, count, sort::Shaker);
	}
	else {
		Sort<int>(arr, count, sort::Shaker);
	}

	return GetTickCount() - start_sorting;
}
int TestMergeSort(size_t count, int*arr = 0) {
	int start_sorting = GetTickCount();
	//1kk elements: 1400ms 
	if (!arr) {
		int*test_arr = new int[count];
		for (int i = count; i >= 0; i--) {
			test_arr[count - i] = i;
		}
		Sort<int>(test_arr, count, sort::Merge);

	}
	else {
		Sort<int>(arr, count, sort::Merge);
	}

	return GetTickCount() - start_sorting;
}
int TestQSort(size_t count, int*arr = 0) {
	int start_sorting = GetTickCount();
	//100kk elements: 3500ms 
	if (!arr) {
		int*test_arr = new int[count];
		for (int i = count; i >= 0; i--) {
			test_arr[count - i] = i;
		}
		Sort<int>(test_arr, count, sort::Quick);
		//print<int>(test_arr, count);
	}
	else {
		Sort<int>(arr, count, sort::Quick);
	}

	return GetTickCount() - start_sorting;
}

void TestBT() {
	BinaryTree<const char*> tree;
	tree.Add(4, "hello");
	tree.Add(2, "hi");
	tree.Add(5, "tututu");
	tree.Add(1, "rofl");
	tree.Add(3, "easy");
	tree.Add(7, "const char*");
	tree.Add(6, "fuck");
	tree.Add(8, "Oh no!");

	std::cout << "Preorder:" << std::endl;
	int summ = 0;
	tree.Preorder([&summ](BinaryTree<const char*>::Node*node) {
		summ += node->key;
		std::cout << node->key << ";" << node->item << "\n";
	});

	std::cout << "\nInorder:" << std::endl;
	tree.Inorder([](BinaryTree<const char*>::Node*node) {
		std::cout << node->key << ";" << node->item << "\n";
	});
	std::cout << "\nPostorder:" << std::endl;
	tree.Postorder([](BinaryTree<const char*>::Node*node) {
		std::cout << node->key << ";" << node->item << "\n";
	});
	tree.Clear();
}

int main() {
	HashTable ht(100, HT::HF::hash_SQ);
	//HashTable ht(100, HT::HF::hash_Convol);
	//HashTable ht(100, HT::HF::hash_mod);
	for (int i = 0; i < 200; i++) {
		ht.AddElement(rand()%1000);
	}
	ht.print();


	system("pause>nul");
}