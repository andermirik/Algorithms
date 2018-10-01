#include "Sort.h"
#include "Search.h"

#include "List.h"
#include "Graph.h"
#include "BinaryTree.h"
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


int main() {
	
	BinaryTree<int> tree;
	tree.Add(4, 4);
	tree.Add(2, 2);
	tree.Add(5, 5);
	tree.Add(1, 1);
	tree.Add(3, 3);
	tree.Add(7, 7);
	tree.Add(6, 6);
	tree.Add(8, 8);

	std::cout << "Preorder:" << std::endl;
	tree.Preorder([](BinaryTree<int>::Node*node) {
		std::cout << node->key << " ";
	});
	std::cout << "\nInorder:" << std::endl;
	tree.Inorder([](BinaryTree<int>::Node*node) {
		std::cout << node->key << " ";
	});
	std::cout << "\nPostorder:" << std::endl;
	tree.Postorder([](BinaryTree<int>::Node*node) {
		std::cout << node->key << " ";
	});

	system("pause>nul");
}