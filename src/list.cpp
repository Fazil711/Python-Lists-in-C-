#include "../include/list.h"
#include <iostream>

List::List() : capacity(5), sz(0), arr(new int[capacity]) {
	/* Null */
}

List::List(const List& clist) : capacity(clist.capacity), sz(clist.sz), arr(new int[capacity]) {
	for (int i = 0; i < clist.Size(); i++) {
		arr[i] = clist.arr[i];
	}
}

List::~List() {
	delete[] arr;
}

void List::append(int value) {
	if (sz < capacity) {
		arr[sz] = value;
		++sz;
	}
	else {
		capacity *= 2;
		int* temp = new int[capacity];
		for (int i = 0; i < sz; ++i) {
			temp[i] = arr[i];
		}
		temp[sz] = value;
		++sz;
		delete[] arr;
		arr = temp;
	}
}

void List::clear() {
	delete[] arr;
	capacity = 5;
	int* temp = new int[capacity];
	sz = 0;
	arr = temp;
}

void List::insert(int index, int value) {
	if (index < 0 || index >= sz) {
		std::cout << "Invalid index" << std::endl;

	}
	if (sz != capacity) {
		for (int i = sz; i > index; i--) {
			arr[i] = arr[i - 1];
		}
		arr[index] = value;
		++sz;
	}
	else {
		capacity *= 2;
		int* temp = new int[capacity];
		for (int i = 0; i < sz; ++i) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		insert(index, value);
	}
}

void List::pop(int index) {
	if (sz <= index || index < 0) {
		std::cout << "Index out of range" << std::endl;
	}
	else {
		for (int i = index; i < sz - 1; i++) {
			arr[i] = arr[i + 1];
		}
		--sz;
	}
}

void List::remove(int value) {
	for (int i = 0; i < sz; i++) {
		if (arr[i] == value) {
			for (int j = i; j < sz - 1; j++) {
				arr[j] = arr[j + 1];
			}
			break;
		}
	}
	--sz;
}

int List::size() const{
	return sz;
}


bool List::Empty() const{
	return sz == 0;
}

int List::Size() const {
	return sz;
}

int List::Capacity() const {
	return capacity;
}

int List::index(int Value) const {
	int ide = 0;
	for (int i = 0; i < sz; i++) {
		if (arr[i] == Value) {
			ide = i;
			break;
		}
	}
	return ide;
}


bool List::operator==(const List& rhs) const{
	if (Size() != rhs.Size()) {
		return false;
	}
	else {
		for (int i = 0; i < Size(); i++) {
			if (arr[i] != rhs.arr[i]) {
				return false;
			}
		}
	}
	return true;
}

bool List::operator!=(const List& rhs) const {
	return !(*this == rhs);
}

int& List::operator[](int index) {
	return arr[index];
}

std::ostream& operator<<(std::ostream& ostr, const List& clist) {
	for (int i = 0; i < clist.sz; i++) {
		ostr << clist.arr[i] << " ";
	}
	ostr << std::endl;
	return ostr;
}
