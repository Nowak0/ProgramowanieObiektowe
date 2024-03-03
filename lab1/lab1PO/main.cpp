#include <iostream>
#include "Trojkat.h"
#include "Prostokat.h"
#include "Kolo.h"
using namespace std;


typedef struct FigureList_t {
	FiguraPlaska* current = NULL;
	FiguraPlaska* prev = NULL;
	FiguraPlaska* next = NULL;
} FigureList;


void addNewElement(FigureList* list, FiguraPlaska* figures[], int listLength) {
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
			figures[listLength-1] = newFigure;
			break;
		case 'r':
			cout << "insert a and b: " << endl;
			cin >> a >> b;
			newFigure = new Prostokat(a, b);
			figures[listLength-1] = newFigure;
			break;
		case 't':
			cout << "insert a, b and c: " << endl;
			cin >> a >> b >> c;
			newFigure = new Trojkat(a, b, c);
			figures[listLength-1] = newFigure;
			break;
		default:
			break;
	}
}


void updateList(FigureList* list, FiguraPlaska* figures[], char operation, int* i, int* listLength) {
	if (*i >= 1 && operation == 'p') {
		*i -= 1;
		list->prev = figures[*i - 1];
	}
	else if (*i < 1) {
		list->prev = NULL;
	}
	else if (*i <= *listLength - 1 && operation == 'n') {
		list->next = figures[*i + 1];
	}
	else if (operation == 'n') {
		*listLength += 1;
		addNewElement(list, figures, *listLength);
		list->next = figures[*i + 1];
	}

	list->current = figures[*i];
}


void executeProgram(FigureList list, FiguraPlaska* figures[], char operation, int* listLength) {
	int i = 0;
	while (operation != 'e') {
		cout << "insert operation - view (v), next (n), previous (p), end (e): " << endl;
		cin >> operation;

		switch (operation) {
			case 'v':
				cout << endl << *list.current << endl;
				break;
			case 'n':
				i++;
				updateList(&list, figures, operation, &i, listLength);
				break;
			case 'p':
				updateList(&list, figures, operation, &i, listLength);
				break;
			case 'e':
				cout << "the end of the program" << endl;
				break;
			default:
				break;
			}
	}
}


void deleteObjects(FiguraPlaska* figures[], int listLength) {
	for (int j = 0; j < listLength; j++)
	{
		delete figures[j];
	}
}


int main() {
	int listLength = 3;
	double a, b, c, r;
	char operation = 'w';
	cout << "insert: a, b, c, r: ";
	cin >> a >> b >> c >> r;

	FiguraPlaska* figures[100] = { new Kolo(r), new Prostokat(a,b), new Trojkat(a,b,c) };
	FigureList list;
	list.current = figures[0];

	executeProgram(list, figures, operation, &listLength);

	deleteObjects(figures, listLength);

	return 0;
}