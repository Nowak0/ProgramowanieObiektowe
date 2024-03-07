#include <iostream>
#include <initializer_list>
#include "library.h"
using namespace std;


Library::Library() : Library(0){
	//cout << "Library()" << std::endl;
}

Library::Library(size_t originalSize) {
	array = new Book[originalSize];
	size = originalSize;
}

Library::Library(initializer_list<Book> list) : size{ list.size() }, array{ new Book[list.size()]} {
	//cout << "Library(std::initializer_list)" << endl;
		size_t i = 0;
		for (Book v : list)
		{
			array[i] = v;
			i++;
		}
}

Library::Library(const Library& original) : size{ original.size }, array{ new Book[original.size] } {
	//cout << "Library(const Library&)" << std::endl;
	for (std::size_t i = 0; i < size; i++)
		array[i] = original.array[i];
}

Library::Library(Library&& original) {
	//cout << "LIbrary(Library&&)" << std::endl;
	array = original.array;
	size = original.size;

	original.array = nullptr;
	original.size = 0;
}

size_t Library::getSize() const {
	return size;
}

Library& Library::operator=(const Library& original) {
	//cout << "operator=(const Library&)" << std::endl;
	Library tmp(original);
	swap(array, tmp.array);
	swap(size, tmp.size);
	return *this;
}

Library& Library::operator=(Library&& original) {
	//cout << "operator=(Library&&)" << std::endl;
	/*
	array = original.array;
	size = original.size;
	original.array = nullptr;
	original.size = 0;
	*/

	swap(array, original.array);
	swap(size, original.size);
	return *this;
}

Book& Library::operator[](size_t i) {
	return array[i];
}

const Book& Library::operator[](size_t i) const {
	return array[i];
}

ostream& operator<<(ostream& os, const Library& thisLibrary) {
	if (thisLibrary.size == 0)
	{
		cout << "Empty" << endl;
		return os;
	}
	for (int i = 0; i < thisLibrary.size; i++)
	{
		cout << "Book number " << i + 1 << ": " << thisLibrary.array[i] << endl;
	}
	return os;
}

Library::~Library() {
	//cout << "Library destructor" << endl;
	if (array != nullptr)
	{
		cout << "Releasing memory " << array << std::endl;
		delete[] array;
	}
}