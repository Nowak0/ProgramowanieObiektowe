#include <iostream>
#include "book.h"
using namespace std;


Book::Book() {
	author = "unknown";
	title = "unknown";
	uid = -1;
}

Book::Book(const string& originalAuthor, const string& originalTitle, const int& originalID) {
	//cout << "Book(l-ref)" << endl;
	author = originalAuthor;
	title = originalTitle;
	uid = originalID;
}

Book::Book(string&& originalAuthor, string&& originalTitle, int&& originalID) {
	//cout << "Book(r-ref)" << endl;
	author = originalAuthor;
	title = originalTitle;
	uid = originalID;
}

Book::Book(const Book& original) {
	//cout << "Book(const Book& original)" << endl;
	author = original.author;
	title = original.title;
	uid = original.uid;
}

Book::Book(Book&& original) {
	//cout << "Book(Book&& original)" << endl;
	//swap(author, original.author);
	//swap(title, original.title);
	
	author = original.author;
	title = original.title;
	uid = original.uid;
	original.author = "unknown";
	original.title = "unknown";
	original.uid = -1;
}

string Book::getAuthor() const {
	return author;
}

string Book::getTitle() const {
	return title;
}

int Book::getID() const {
	return uid;
}

void Book::setAuthor(const string& givenAuthor) {
	this->author = givenAuthor;
}

void Book::setAuthor(string&& givenAuthor) {
	this->author = givenAuthor;
}

void Book::setID(const int& givenID) {
	this->uid = givenID;
}

void Book::setID(int&& givenID) {
	this->uid = givenID;
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
	swap(uid, tmp.uid);
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
	swap(uid, original.uid);
	return *this;
}

ostream& operator<<(ostream& os, const Book& thisBook) {
	os << thisBook.author << ", " << thisBook.title << ", " << thisBook.uid << endl;
	return os;
}

Book::~Book() {
	//cout << "Destruktor" << endl;
}