#include <iostream>
#include <initializer_list>
#include "library.h"
#include <vector>
using namespace std;


Library::Library() : Library(0){
	//cout << "Library()" << std::endl;
}

Library::Library(size_t originalSize) {
	array.resize(originalSize);
	size = originalSize;
	copy.resize(originalSize);
}

Library::Library(initializer_list<Book> list) : size{ list.size() } {
	array.resize(list.size());
	copy.resize(list.size());
	//cout << "Library(std::initializer_list)" << endl;
		size_t i = 0;
		for (Book v : list)
		{
			array[i] = v;
			copy[i] = 1;
			i++;
		}
}

Library::Library(const Library& original) : size{ original.size } {
	array.resize(original.size);
	copy.resize(original.size);
	//cout << "Library(const Library&)" << std::endl;
	for (std::size_t i = 0; i < size; i++)
		array[i] = original.array[i];
}

Library::Library(Library&& original) {
	//cout << "LIbrary(Library&&)" << std::endl;
	array = original.array;
	size = original.size;
	copy = original.copy;

	original.array.clear();
	original.size = 0;
	original.copy.clear();
}

size_t Library::getSize() const {
	return size;
}

Library& Library::operator=(const Library& original) {
	//cout << "operator=(const Library&)" << std::endl;
	Library tmp(original);
	swap(array, tmp.array);
	swap(size, tmp.size);
	swap(copy, tmp.copy);
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
	swap(copy, original.copy);
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
		cout << "Book number " << i + 1 << ": " << thisLibrary.array[i] << "  copies: " << thisLibrary.copy[i] << endl;
	}
	return os;
}

void Library::addBook(const Book& book) {
	size += 1;
	array.resize(size);
	copy.resize(size);
	array[size-1] = book;
	copy[size-1] = 1;
}


void Library::addBookCopy(const Book& book, const int numberOfCopies) {
	int i = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i].getID() == book.getID())
		{
			copy[i] += numberOfCopies;
			break;
		}
	}
}

Library::~Library() {
	//cout << "Library destructor" << endl;
	/*
	if (array != nullptr)
	{
		cout << "Releasing memory " << array << std::endl;
		delete[] array;
		delete[] copy;
	}
	*/
}