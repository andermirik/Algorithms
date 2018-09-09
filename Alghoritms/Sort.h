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
int FindInsertionIndex(T* items, T value, size_t size) {
	for (int index = 0; index < size; index++) {
		if (value > items[index])
			return index;
	}
	return 0;
}

template<class T>
void Insert(T*items, int indexInsertingAt, int indexInsertingFrom) {
	T temp = items[indexInsertingAt];
	items[indexInsertingAt] = items[indexInsertingFrom];
	for (int current = indexInsertingFrom; current > indexInsertingAt; current--) {
		items[current] = items[current - 1];
	}
	items[indexInsertingAt + 1] = temp;
}

template<class T>
int FindIndexOfSmallestFromIndex(T* items, int sortedRangeEnd, size_t size) {
	T currentSmallest = items[sortedRangeEnd];
	int currentSmallestIndex = sortedRangeEnd;
	for (int i = sortedRangeEnd+1; i < size; i++) {
		if (currentSmallest > items[i]) {
			currentSmallest = items[i];
			currentSmallestIndex = i;
		}
	}

	return currentSmallestIndex;

}

template<class T>
void Merge(T*items, size_t size, T*left, T*right, size_t leftSize, size_t rightSize) {
	int leftIndex = 0;
	int rightIndex = 0;
	int targetIndex = 0;
	int remaining = leftSize + rightSize;

	while (remaining > 0) {
		if (leftIndex >= leftSize)
		{
			items[targetIndex] = right[rightIndex++];
		}
		else if (rightIndex >= rightSize)
		{
			items[targetIndex] = left[leftIndex++];
		}
		else if (left[leftIndex]<right[rightIndex])
		{
			items[targetIndex] = left[leftIndex++];
		}
		else
		{
			items[targetIndex] = right[rightIndex++];
		}

		targetIndex++;
		remaining--;
	}
	delete[]left;
	delete[]right;
}

template<class T>
int Sort(T* items, size_t size, sort::Methods sm) {
	size_t swaps = 0;
	
	if (sm == sort::Bubble) {
		bool swapped;
		int w = 0;
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

		int SortedRangeEndIndex = 1;

		while (SortedRangeEndIndex < size) {
			Watch(SortedRangeEndIndex, size);
			if (items[SortedRangeEndIndex] < items[SortedRangeEndIndex - 1]) {
				int InsertIndex = FindInsertionIndex(items, items[SortedRangeEndIndex], size);
				Insert(items, InsertIndex, SortedRangeEndIndex);
				++swaps;
			}
			++SortedRangeEndIndex;
		}
		return swaps;
	}
	else if (sm == sort::ByChoice) {
		
		int SortedRangeEnd = 0;
		while (SortedRangeEnd < size) {
			int nextIndex = FindIndexOfSmallestFromIndex(items, SortedRangeEnd, size);
			Watch(SortedRangeEnd, size);
			Swap(items, SortedRangeEnd, nextIndex);
			SortedRangeEnd++;
		}

		return swaps;
	}
	else if (sm == sort::Merge) {

		if (size <= 1)
			return 0;

		size_t leftSize = size / 2;
		size_t rightSize = size - leftSize;

		T*left = new T[leftSize];
		T*right = new T[rightSize];

		for (int i = 0; i < leftSize; i++)
			left[i] = items[i];
		for (int i = 0; i < rightSize; i++)
			right[i] = items[leftSize + i];

		Sort(left, leftSize, sort::Merge);		
		Sort(right, rightSize, sort::Merge);

		Merge(items, size, left, right, leftSize, rightSize);
		return swaps;
	}
	else if (sm == sort::Quick) {
		return swaps;
	}
}
