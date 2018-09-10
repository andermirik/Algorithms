#include "Sort.h"
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



int main() {

	//std::cout<<TestBubbeSort(100000);
	//std::cout << TestInsertionSort(100000)<<std::endl;
	//std::cout << TestByChoiceSort(100000)<<std::endl;
	//std::cout << TestShakerSort(100000)<<std::endl;
	//std::cout << TestMergeSort(1000000) << std::endl;
	
	system("pause>nul");
}