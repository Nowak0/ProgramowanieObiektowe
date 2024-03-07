#ifndef FIGURELIST_H
#define FIGURELIST_H
#include <iostream>
#include "FiguraPlaska.h"


class FigureList {
private:
	FiguraPlaska* previous;
	FiguraPlaska* current;
	FiguraPlaska* next;
	FiguraPlaska* figures[100];
	int listLength;
	int iteration;

public:
	FigureList(double a, double b, double c, double r);
	void addNewElement();
	void updateList(char operation);
	FiguraPlaska* getPrevious();
	FiguraPlaska* getCurrent();
	FiguraPlaska* getNext();
	int getListLength();
	void setPrevious(FiguraPlaska* object);
	void setCurrent(FiguraPlaska* object);
	void setNext(FiguraPlaska* object);
	void setListLength(const int length);
	~FigureList();
};

#endif