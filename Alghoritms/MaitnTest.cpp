#include "Sort.h"
#include "windows.h"

int TestBubbeSort(size_t count, int*arr=0) {
	int start_sorting = GetTickCount();
	//358 сек 1кк элементов
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

int main() {

	std::cout<<TestBubbeSort(100000);

	system("pause>nul");
}