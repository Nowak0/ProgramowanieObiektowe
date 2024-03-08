#include <iostream>
using namespace std;


class Book {
private:
	string author, title;
	int uid;

protected:
	friend ostream& operator<<(std::ostream& os, const Book& thisBook);

public:
	Book();
	Book(const string& originalAuthor, const string& originalTitle, const int& uid);
	Book(string&& originalAuthor, string&& originalTitle, int&& uid);
	Book(const Book& original);
	Book(Book&& original);
	string getAuthor() const;
	string getTitle() const;
	int getID() const;
	void setAuthor(const string& givenAuthor);
	void setTitle(const string& givenTitle);
	void setID(const int& givenID);
	void setAuthor(string&& givenAuthor);
	void setTitle(string&& givenTitle);
	void setID(int&& givenID);
	Book& operator=(const Book& right);
	Book& operator=(Book&& right);
	~Book();
};