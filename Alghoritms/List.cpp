#pragma once
#include "List.h"

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
public:
	List() {
		begin = nullptr;
		end = nullptr;
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
			return;
		}
		else {
			end->next = new Unit;
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
