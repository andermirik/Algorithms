#pragma once
#include <iostream>
namespace sort {
	enum Methods {
		Bubble,
		Insertion,
		ByChoice,
		Merge,
		Quick
	};
}
void Watch(int i, size_t size);
template<class T>
void print(T* items, size_t size) {
	for (int i = 0; i < size; i++) {
		std::cout << items[i] << " ";
	}
	std::cout << std::endl;
}

template<class T>
bool Swap(T* items, size_t left, size_t right) {
	if (left != right) {
		T temp = items[left];
		items[left] = items[right];
		items[right] = temp;
		return true;
	}
	else return false;
}

template<class T>
int Sort(T* items, size_t size, sort::Methods sm) {
	size_t swaps = 0;
	int w=0;
	bool swapped;
	if (sm == sort::Bubble) {
		do {
			swapped = false;
			for (int i = 1; i < size; i++) {

				if (items[i - 1] > items[i]) {
					Swap(items, i - 1, i);
					swaps++;
					swapped = true;
				}
			}
			w++;
			Watch(w, size);
		} while (swapped != false);

		return swaps;
	}
	else if (sm == sort::Insertion) {

		return swaps;
	}
	else if (sm == sort::ByChoice) {
		return swaps;
	}
	else if (sm == sort::Merge) {
		return swaps;
	}
	else if (sm == sort::Quick) {
		return swaps;
	}
}
