#include <iostream>
#include "FigureList.h"
#include "Kolo.h"
#include "Prostokat.h"
#include "Trojkat.h"
using namespace std;


FigureList::FigureList(double a, double b, double c, double r) {
	figures[0] = new Kolo(r);
	figures[1] = new Prostokat(a, b);
	figures[2] = new Trojkat(a, b, c);
	current = figures[0];
	previous = NULL;
	next = NULL;
	listLength = 3;
	iteration = 0;
}


FiguraPlaska* FigureList::getPrevious() {
	return previous;
}


FiguraPlaska* FigureList::getCurrent() {
	return current;
}


FiguraPlaska* FigureList::getNext() {
	return next;
}


int FigureList::getListLength() {
	return listLength;
}


void FigureList::setPrevious(FiguraPlaska* object) {
	this->previous = object;
}


void FigureList::setCurrent(FiguraPlaska* object) {
	this->current = object;
}


void FigureList::setNext(FiguraPlaska* object) {
	this->next = object;
}


void FigureList::setListLength(const int length) {
	this->listLength = length;
}


void FigureList::addNewElement() {
	char operation;
	double a, b, c, r;
	cout << "Which object to create: Circle (c), Rectangle (r), Triangle (t): " << endl;
	cin >> operation;
	FiguraPlaska* newFigure = NULL;

	switch (operation) {
	case 'c':
		cout << "insert radius: " << endl;
		cin >> r;
		newFigure = new Kolo(r);
		figures[listLength - 1] = newFigure;
		break;
	case 'r':
		cout << "insert a and b: " << endl;
		cin >> a >> b;
		newFigure = new Prostokat(a, b);
		figures[listLength - 1] = newFigure;
		break;
	case 't':
		cout << "insert a, b and c: " << endl;
		cin >> a >> b >> c;
		newFigure = new Trojkat(a, b, c);
		figures[listLength - 1] = newFigure;
		break;
	default:
		break;
	}
}


void FigureList::updateList(char operation) {
	if (operation == 'n') ++iteration;

	if (iteration >= 1 && operation == 'p') {
		iteration -= 1;
		previous = figures[iteration - 1];
	}
	else if (iteration < 1) {
		previous = NULL;
	}
	else if (iteration <= listLength - 1 && operation == 'n') {
		next = figures[iteration + 1];
	}
	else if (operation == 'n') {
		listLength += 1;
		addNewElement();
		next = figures[iteration + 1];
	}

	current = figures[iteration];
}

FigureList::~FigureList() {
	for (int i = 0; i < listLength; i++)
	{
		delete figures[i];
	}
}