#include <iostream>
using namespace std;


class Book {
private:
	string author, title;

protected:
	friend ostream& operator<<(std::ostream& os, const Book& thisBook);

public:
	Book();
	Book(const string& originalAuthor, const string& originalTitle);
	Book(string&& originalAuthor, string&& originalTitle);
	Book(const Book& original);
	Book(Book&& original);
	string getAuthor() const;
	string getTitle() const;
	void setAuthor(const string& givenAuthor);
	void setTitle(const string& givenTitle);
	void setAuthor(string&& givenAuthor);
	void setTitle(string&& givenTitle);
	Book& operator=(const Book& right);
	Book& operator=(Book&& right);
	~Book();
};