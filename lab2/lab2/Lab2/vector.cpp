#include <initializer_list>
#include <iostream>
#include <algorithm>
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