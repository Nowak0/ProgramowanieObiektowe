#include <iostream>
#include "book.h"
using namespace std;


Book::Book() {
	author = "unknown";
	title = "unknown";
}

Book::Book(const string& originalAuthor, const string& originalTitle) {
	//cout << "Book(l-ref)" << endl;
	author = originalAuthor;
	title = originalTitle;
}

Book::Book(string&& originalAuthor, string&& originalTitle) {
	//cout << "Book(r-ref)" << endl;
	author = originalAuthor;
	title = originalTitle;
}

Book::Book(const Book& original) {
	//cout << "Book(const Book& original)" << endl;
	author = original.author;
	title = original.title;
}

Book::Book(Book&& original) {
	//cout << "Book(Book&& original)" << endl;
	//swap(author, original.author);
	//swap(title, original.title);
	
	author = original.author;
	title = original.title;
	original.author = "unknown";
	original.title = "unknown";
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
}

void Book::setTitle(const string& givenTitle) {
	this->title = givenTitle;
}

void Book::setTitle(string&& givenTitle) {
	this->title = givenTitle;
}

Book& Book::operator=(const Book& original) {
	//cout << "operator=(const Book&)" << std::endl;
	Book tmp = original;
	swap(author, tmp.author);
	swap(title, tmp.title);
	return *this;
}

Book& Book::operator=(Book&& original) {
	//cout << "operator=(Book&&)" << std::endl;
	/*
	author = original.author;
	title = original.title;
	original.author = "unknown";
	original.title = "unknown";
	*/
	swap(author, original.author);
	swap(title, original.title);
	return *this;
}

ostream& operator<<(ostream& os, const Book& thisBook) {
	os << thisBook.author << ", " << thisBook.title << endl;
	return os;
}

Book::~Book() {
	//cout << "Destruktor" << endl;
}