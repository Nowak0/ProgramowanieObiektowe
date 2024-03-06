#include <initializer_list>
#include <iostream>
class Vector {
	double* array;
	std::size_t size;
public:
	//Parametr typu std::initializer_list pozwoli na uruchomienie
	//konstruktora z dowoln¹ liczb¹ wyst¹pieñ liczb typu double.
	// Bêdzie to wygl¹da³o jak inicjalizacja tablicy. Przyk³ad:
	//Vector v1({1,2,3,4,5,5.5});
	//lub
	//Vector v1{1,2,3,4,5,5.5};
	//lub
	//Vector v1 = {1,2,3,4,5,5.5};
	//Jest to cecha C++11
	Vector(std::initializer_list<double> initList)
		: size{ initList.size() }, array{ new double[initList.size()] }
	{
		std::size_t i = 0;
		for (double v : initList)
		{
			array[i] = v;
			i++;
		}
	}
	std::size_t GetSize() const {
		return size;
	}
	const double& operator[](std::size_t i) {
		return array[i];
	}
	~Vector()
	{
		if (array != nullptr)
		{
			std::cout << "Releasing memory " << array << std::endl;
			delete[] array;
		}

	}
};
std::ostream& operator<<(std::ostream& ostr, const Vector& v) {
	ostr << "Vector{";
	for (std::size_t i = 0; i < v.GetSize(); i++)
	{
		if (i > 0)
			ostr << ',';
		ostr << v[i];
	}
	ostr << '}';
	return ostr;
}
int main(int argc, char** argv) {
	Vector v1 = { 1,2,3,4,5,5.5 };
	std::cout << "v1: " << v1 << std::endl;
	Vector v2 = { 5.5,4,3,2,1 };
	std::cout << "v2: " << v2 << std::endl;
	v1 = v2; //K³opotliwe przypisanie
	std::cout << "v1: " << v1 << std::endl;
	std::cout << "v2: " << v2 << std::endl;
	v1[0] = 100.0; //Ustawienie wartoœci w obiekcie v1
	std::cout << "v1: " << v1 << std::endl;
	std::cout << "v2: " << v2 << std::endl;
	return 0;

}