#include <iostream>
#include "library.h"
using namespace std;


int main() {
	/*
	string author = "Thomas Harris", title = "The silence of the lambs";
	Book book;
	cout << "e: " << book << endl;
	Book b1 = { author, title };
	cout << "b1: " << b1 << endl;
	Book b2 = { "Stephen King", "The green mile" };
	cout << "b2: " << b2 << endl;
	Book b3 = b1;
	cout << "b3: " << b3 << " b1: " << b1 << endl;
	book = std::move(b2);
	cout << "e: " << book << " b2:" << b2 << endl;
	book.setAuthor("Winston Groom");
	cout << "e: " << book << endl;
	book.setTitle("Forrest Gump");
	cout << "e: " << book << endl;
	*/

	Library e;
	cout << "e: " << e << endl;
	
	Library l1 = { {"Thomas Harris", "The Silence Of The Lambs"},
	{"Stephen King", "The Green Mile"},
	{"Winston Groom", "Forrest Gump"} };
	cout << "l1: " << l1 << endl;
	
	Library l2(2);
	cout << "l2: " << l2 << endl;
	l2[0] = { "<?>", "<?>" };
	l2[1] = { "<?>", "<?>" };
	cout << "l2: " << l2 << endl;
	//e = std::move(l2);
	//cout << "e: " << e << " l2: " << l2 << endl;
	//l1[0] = std::move(e[1]);
	//cout << "l1: " << l1 << " e: " << e << endl;
	

	return 0;
}