#include <iostream>
#include "book.h"
#include <initializer_list>
#include <vector>
using namespace std;


class Library {
private:
	vector<Book> array;
	size_t size;
	vector<int> copy;

protected:
	friend ostream& operator<<(ostream& os, const Library& thisLibrary);

public:
	Library();
	Library(size_t size);
	Library(initializer_list<Book> list);
	Library(const Library& original);
	Library(Library&& original);
	Library& operator=(const Library& original);
	Library& operator=(Library&& original);
	Book& operator[](size_t i);
	const Book& operator[](size_t i) const;
	size_t getSize() const;
	void addBook(const Book& book);
	void addBookCopy(const Book& book, const int numberOfCopies);
	~Library();
};