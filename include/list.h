#pragma once
#include <ostream>
#ifndef LIST_H
#define LIST_H

class List {
private:
	int capacity;
	int sz;
	int* arr;

	bool Empty() const;
	int Size() const;
	int Capacity() const;
	

public:
	List();
	List(const List& clist);
	~List();

	// User available options
	void append(int value);
	void clear();
	void insert(int index, int value);
	void pop(int index);
	void remove(int value);
	int index(int value) const;
	int size() const;
	int& operator[](int index);
	bool operator==(const List& rhs) const;
	bool operator!=(const List& rhs) const;
	

	friend std::ostream& operator<<(std::ostream& ostr, const List& clist);

};

#endif // !LIST_H
