#include "Sort.h"
void Watch(int i, size_t size) {
	static int c = 0;
	if (size >= 100)
		if (!(i % (size / 100))) {
			c++;
			if (c < 10)
				std::cout << "\b\b" << c << "%";
			else if (c == 10) {
				std::cout << "\b\b\b";
				std::cout << c << "%";
			}
			else if (c < 100) {
				std::cout << "\b\b\b\b" << c << "%";
				if (c == 99) {
					std::cout << "\b\b\b\b\bDone\n";
					c = 0;
				}
			}
		}
}