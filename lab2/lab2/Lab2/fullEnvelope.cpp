/*
#include <initializer_list>
#include <iostream>
class Vector {
	double* array;
	std::size_t size;
public:
	//Parametr typu std::initializer_list pozwoli na uruchomieniekonstruktora
		//z dowoln¹ liczb¹ wyst¹pieñ liczb typu double. Bêdzie to wygl¹da³ojak
		//inicjalizacjia tablicy. Przyk³ad:
		//Vector v1({1,2,3,4,5,5.5});
		//lub
		//Vector v1{1,2,3,4,5,5.5};
		//lub
		//Vector v1 = {1,2,3,4,5,5.5};
		//Jest to cecha C++11
	Vector(std::initializer_list<double> initList) : size{ initList.size() }, array{ new double[initList.size()] }
	{
		std::cout << "Vector(std::initializer_list)" << std::endl;
		std::size_t i = 0;
		for (double v : initList)
		{
			array[i] = v;
			i++;
		}
	}

	Vector(const Vector& other) //Konstruktor kopiujacy
		: size{ other.size }, array{ new double[other.size] } {
		std::cout << "Vector(const Vector&)" << std::endl;
		for (std::size_t i = 0; i < size; i++)
			array[i] = other.array[i];
	}

	Vector(Vector&& other)
	{
		std::cout << "Vector(Vector&&)" << std::endl;
		array = other.array;
		size = other.size;

		other.array = nullptr;
		other.size = 0;
	}


	Vector(std::size_t size)
		: size{ size }, array{ new double[size] }
	{
		std::cout << "Vector(" << size << ")" << std::endl;
	}

	Vector()
		: Vector(0)
	{
		std::cout << "Vector()" << std::endl;
	}
	Vector(std::size_t size, double init)
		: Vector(size)
	{
		for (std::size_t i = 0; i < size; i++)
			array[i] = init;
	}

	//Implementacja operatora przypisania z wykorzystanie copy-swap
	Vector& operator=(const Vector& right) {
		std::cout << "operator=(const Vector&)" << std::endl;
		Vector tmp = right; //Tworzenie obiektu tymczasowego
		std::swap(array, tmp.array); //Zamiana wskaŸników na tablicemiejscami
		std::swap(size, tmp.size); //Zamiana informacji o wielkoœcitablicy
		return *this;
	}
	//Po wyjœciu z cia³a operatora obiekt tmp jest niszczony
	//a wraz z nim stara zawartoœæ obiektu g³ównego

	Vector& operator=(Vector&& right) {
		std::cout << "operator=(Vector&&)" << std::endl;
		std::swap(array, right.array); //Zamiana wskaŸników na tablicemiejscami
		std::swap(size, right.size); //Zamiana informacji o wielkoœciWtablicy
		return *this;
	}
	//Po wyjœciu z cia³a operatora obiekt, na który wskazuje referencjaright
		//zosta³ pozostawiony w poprawnym stanie.

	std::size_t GetSize() const {
		return size;
	}
	double& operator[](std::size_t i)
	{
		return array[i];
	}
	const double& operator[](std::size_t i) const
	{
		return array[i];
	}
	~Vector()
	{
		std::cout << "~Vector()" << std::endl;
		if (array != nullptr)
		{
			std::cout << "Releasing memory " << array << std::endl;
			delete[] array;
		}
	}
};

class Envelope
{
	Vector vector;
	friend std::ostream& operator<<(std::ostream&, const Envelope&);
public:
	Envelope(const Vector& vector) :
		vector{ vector } {
		std::cout << "Envelope(const Vector&)" << std::endl;
	}
	Envelope(Vector&& vector) :
		vector{ std::move(vector) } {
		std::cout << "Envelope(Vector&&)" << std::endl;
	}
	Envelope(const Envelope& other) :
		vector{ other.vector } {
		std::cout << "Envelope(const Envelope&)" << std::endl;
	}
	Envelope(Envelope&& other) :
		vector{ std::move(other.vector) } {
		std::cout << "Envelope(Envelope&&)" << std::endl;
	}
	Envelope& operator=(const Envelope& right) {
		std::cout << "operator=(const Envelope&)" << std::endl;
		Envelope tmp(right);
		std::cout << "operator=(const Envelope&) swap pocz¹tek" <<
			std::endl;
		std::swap(vector, tmp.vector);
		std::cout << "operator=(const Envelope&) swap koniec" <<
			std::endl;
		return *this;
	}
	Envelope& operator=(Envelope&& right) {
		std::cout << "operator=(Envelope&&)" << std::endl;
		vector = std::move(right.vector);
		return *this;
	}
	~Envelope() {
		std::cout << "~Envelope()" << std::endl;
	}
};
std::ostream& operator<<(std::ostream& ostr, const Envelope& e)
{
	//ostr << "Envelope{vector: " << e.vector << '}';
	return ostr;
}


int main() {
	std::cout << "Konstruktor z r-referencj¹" << std::endl;
	Envelope e1{ Vector{1,2,3} };
	std::cout << "e1: " << e1 << std::endl;
	std::cout << "Konstrukor przenosz¹cy" << std::endl;
	Envelope e2 = std::move(e1);
	std::cout << "e1: " << e1 << std::endl;
	std::cout << "e2: " << e2 << std::endl;
	std::cout << "Przenosz¹cy operator przypisania" << std::endl;
	e1 = std::move(e2);
	std::cout << "e1: " << e1 << std::endl;
	std::cout << "e2: " << e2 << std::endl;
	std::cout << "operator przypisania copy-swap pocz¹tek" << std::endl;
	e2 = e1;
	std::cout << "operator przypisania copy-swap koniec" << std::endl;
	std::cout << "e1: " << e1 << std::endl;
	std::cout << "e2: " << e2 << std::endl;
}
*/