#include "../include/list.h"
#include<iostream>
int main() {
	List arr;
	arr.append(23);
	arr.append(34);
	arr.append(69);
	arr.append(420);
	arr.append(100);
	std::cout << "The array formed: " << arr;
	std::cout << std::endl;
	arr.insert(2, 54);
	std::cout << "After insertion of 54: " << arr;
	std::cout << std::endl;
	arr.append(341);
	arr.append(11);
	arr.remove(54);
	std::cout << "After removal of value 54: " << arr;
	std::cout << std::endl;
	std::cout << "The index of element with value 341: " << arr.index(341) << std::endl;
	std::cout << "The size of array: " << arr.size() << std::endl;
	std::cout << "The value of element at index 3: " << arr[3];
	return 0;
}
