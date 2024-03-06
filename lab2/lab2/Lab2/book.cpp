#include <iostream>
#include "book.h"
using namespace std;


Book::Book() {
	author = "unknown";
	title = "unknown";
}

Book::Book(const string& originalAuthor, const string& originalTitle) {
	cout << "Book(l-ref)" << endl;
	author = originalAuthor;
	title = originalTitle;
}

Book::Book(string&& originalAuthor, string&& originalTitle) {
	cout << "Book(r-ref)" << endl;
	author = originalAuthor;
	title = originalTitle;
}

Book::Book(const Book& original) { // konstruktor kopiujacy
	cout << "Book(const Book& original)" << endl;
	author = original.author;
	title = original.title;
}

Book::Book(Book&& original) { // kosntruktor przenoszacy
	cout << "Book(Book&& original)" << endl;
	author = original.author;
	title = original.title;
	original.author = "";
	original.title = "";
}

string Book::getAuthor() const {
	return author;
}

string Book::getTitle() const {
	return title;
}

void Book::setAuthor(const string& givenAuthor) {
	this->author = givenAuthor;
}

void Book::setAuthor(string&& givenAuthor) {
	this->author = givenAuthor;
	//givenAuthor = "";
}

void Book::setTitle(const string& givenTitle) {
	this->title = givenTitle;
}

void Book::setTitle(string&& givenTitle) {
	this->title = givenTitle;
	//givenTitle = "";
}

Book& Book::operator=(const Book& original) { // operator kopiujacy
	std::cout << "operator=(const Vector&)" << std::endl;
	Book tmp = original;
	std::swap(author, tmp.author);
	std::swap(title, tmp.title);
	return *this;
}

Book& Book::operator=(Book&& original) { // operator przenoszacy
	std::cout << "operator=(Vector&&)" << std::endl;
	std::swap(author, original.author);
	std::swap(title, original.title);
	return *this;
}

ostream& operator<<(ostream& os, const Book& thisBook) {
	os << thisBook.author << ", " << thisBook.title << endl;
	return os;
}

Book::~Book() {
	cout << "Destruktor" << endl;
}