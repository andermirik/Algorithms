#pragma once

template<typename Type>
class List {
private:
	struct Unit {
		Type key;
		Unit*next;
		Unit*prev;
	};
	Unit* begin;
	Unit* end;
	size_t size;
public:
	List() {
		begin = nullptr;
		end = nullptr;
	}
	Unit* operator[](Type key) {
		static bool wasRequest=false;
		static Type lastRequest;
		static Unit*lastReturn;
		
		if (!lastReturn)
			wasRequest = false;

		if (!wasRequest) {
			wasRequest = true;
			lastRequest = key;
			int j = 0;
			for (auto i = begin; i != end->next; i = i->next, j++) {
				if (j == key) {
					lastReturn = i;
					return lastReturn;
				}
			}
		}
		else {
			int shift = lastRequest - key;
			lastRequest = key;
			if (shift < 0) {
				for (int i = 0; i <= abs(shift); i++, lastReturn = lastReturn->next) {
					if (i + shift + key == key) {
						return lastReturn;
					}
				}
			}
			else {
				for (int i = 0; i <= shift; i++, lastReturn = lastReturn->prev) {
					if (shift + key - i == key) {
						return lastReturn;
					}
				}

			}
		}
		return 0;
	}
	void print() {
		if (!begin)
			return;
		std::cout << "{\n";
		for (auto temp = begin; temp != end->next; temp = temp->next) {
			std::cout << "  " << temp->key << ":";
			if (temp->next != end->next)
				std::cout << ",\n";
			else std::cout << "\n";
		}
		std::cout << "}\n";
	}
	Unit* Begin() {
		return begin;
	}
	Unit* End() {
		return end;
	}
	void AddElement(Type key) {
		if (!begin) {
			begin = new Unit;
			begin->key = key;
			begin->next = nullptr;
			begin->prev = nullptr;
			end = begin;
			size++;
			return;
		}
		else {
			end->next = new Unit;
			end->next->prev = end;
			end->next->next = nullptr;
			end = end->next;
			end->key = key;
			size++;
			return;
		}
	}

	bool DeleteItem(Type key) {
		if (!begin)
			return false;
		if (begin->key == key) {
			auto temp = begin;
			begin = begin->next;
			begin->prev = nullptr;
			delete temp;
			return true;
		}
		if (end->key == key) {
			auto temp = end;
			end = end->prev;
			end->next = nullptr;
			delete temp;
			return true;
		}
		for (auto it = begin; it != nullptr; it = it->next) {
			if (it->key == key) {
				
				auto temp = it;
				it->prev->next = it->next;
				it->next->prev = it->prev;
				delete temp;
				return true;
			}
		}
			return false;
	}
	//I can make function DeleteNode(Unit*node), but its boooring((
	bool DeleteSortedItemsAtInterval(size_t left, size_t right) {
		bool result = false;
		//1 2 3 4 5
		if (right > size)
			right = size;
		int i = 1;
		for (auto it = begin; it != end->next&&i <= right; i++) {
			if (i >= left) {
				if (it == begin) {
					auto ToDelete = begin;
					begin = begin->next;
					if (begin)
						begin->prev = nullptr;
					delete ToDelete;
					it = begin;
					continue;
				}
				if (it == end) {
					auto temp = end;
					end = end->prev;
					end->next = nullptr;
					delete temp;
					continue;
				}

				auto ToDelete = it;
				it->prev->next = it->next;
				it->next->prev = it->prev;
				it = it->next;
				delete ToDelete;
				it = it->prev;
			}
			it = it->next;
		}

		return result;
	}

	size_t length() {
		return size;
	}
	~List() {
		if (!begin)
			return;
		Unit* temp = nullptr;
		while (begin->next) {
			temp = begin;
			begin = begin->next;
			delete temp;
		}
		delete begin;
	}
};
