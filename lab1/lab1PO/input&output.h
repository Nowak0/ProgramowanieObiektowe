#include <iostream>
using namespace std;


class InputOutput {
private:
	double* array;
public:
	InputOutput();
	virtual double* insertStartingVariables();
	virtual char insertOperation(char operation);
	virtual void infoProgramEnd();
	virtual ~InputOutput();
};