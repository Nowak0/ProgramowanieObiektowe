#include <iostream>
#include "library.h"
using namespace std;


int main() {
	/*
	string author = "Thomas Harris", title = "The silence of the lambs";
	Book book;
	cout << "book: " << book << endl;

	Book b1 = { author, title };
	cout << "b1: " << b1 << endl;

	Book b2 = { "Stephen King", "The green mile" };
	cout << "b2: " << b2 << endl;

	Book b3 = b1;
	cout << "b3: " << b3 << "b1: " << b1 << endl;

	book = move(b2);
	cout << "book: " << book << "b2:" << b2 << endl;
	book.setAuthor("Winston Groom");
	cout << "book: " << book << endl;
	book.setTitle("Forrest Gump");
	cout << "book: " << book << endl;
	
	
	Library e;
	cout << "e: " << e << endl;
	
	Library l1 = { {"Thomas Harris", "The Silence Of The Lambs"},
	{"Stephen King", "The Green Mile"},
	{"Winston Groom", "Forrest Gump"} };
	cout << "l1: " << l1 << endl;
	
	Library l2(2);
	cout << "l2: " << l2 << endl;
	l2[0] = { "George Orwell", "1984" };
	l2[1] = { "William Shakespeare", "Hamlet" };
	cout << "l2: " << l2 << endl;

	e = move(l2);
	cout << "e: " << e << "l2: " << l2 << endl;
	l1[0] = move(e[1]);
	cout << "l1: " << l1 << "e: " << e << endl;
	*/

	Library lib1 = { {"Thomas Harris", "The Silence Of The Lambs", 0},
	{"Stephen King", "The Green Mile",1},
	{"Winston Groom", "Forrest Gump", 2}};

	Book newBook = { "JK Rowling", "Harry Potter", 3 };
	lib1.addBook(newBook);

	cout << lib1 << endl;

	lib1.addBookCopy(newBook, 8);
	cout << endl << lib1 << endl;
	return 0;
}