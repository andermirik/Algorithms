#pragma once
#include "List.h"
template<typename Type>
struct Unit {
	Type key;
	Unit*next;
	Unit*prev;
};

template<typename Type>
class List {
private:
	Unit<Type>* begin;
	Unit<Type>* end;
public:
	List() {
		begin = nullptr;
		end = nullptr;
	}

	Unit<Type>* Begin() {
		return begin;
	}
	Unit<Type>* End() {
		return end;
	}
	void AddElement(Type key) {
		if (!begin) {
			begin = new Unit<Type>;
			begin->key = key;
			begin->next = nullptr;
			begin->prev = nullptr;
			end = begin;
			return;
		}
		else {
			end->next = new Unit<Type>;
			end->next->prev = end;
			end->next->next = nullptr;
			end = end->next;
			end->key = key;
			return;
		}
	}
	~List() {
		Unit* temp = nullptr;
		while (begin->next) {
			temp = begin;
			begin = begin->next;
			delete temp;
		}
		delete begin;
	}
};
