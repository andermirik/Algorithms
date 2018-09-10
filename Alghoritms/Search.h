#pragma once
template<class T>
int Search(T*items, size_t size, T key) {
	for (int i = 0; i < size; i++) {
		if (key == items[i])
			return i;
	}
	return 0;
}
template<class T>
int BSearch(T* items, size_t l, size_t r, T key) {
	int mid = (l + r) / 2;
	if (items[mid] == key) return mid;
	if (mid == r||mid==l) return -1;

	if (items[mid]<key)
		BSearch(items, l, mid, key);
	else 
		BSearch(items, mid, r, key);
}