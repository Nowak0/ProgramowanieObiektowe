#include <iostream>
#include "FigureList.h"
#include "input&output.h"
using namespace std;


void executeProgram(InputOutput* io, FigureList* list) {
	char operation = ' ';

	while (operation != 'e') {
		operation = io->insertOperation(operation);

		switch (operation) {
		case 'v':
			cout << endl << *list->getCurrent() << endl;
			break;
		case 'n':
			list->updateList(operation);
			break;
		case 'p':
			list->updateList(operation);
			break;
		case 'e':
			io->infoProgramEnd();
			break;
		default:
			break;
		}
	}
}


void deleteObjects(InputOutput* io, FigureList* list) {
	delete list;
	delete io;
}


int main() {
	InputOutput* io = new InputOutput();
	double* tmpArray = io->insertStartingVariables();

	FigureList* list = new FigureList(tmpArray[0], tmpArray[1], tmpArray[2], tmpArray[3]);
	executeProgram(io, list);

	deleteObjects(io, list);
	return 0;
}