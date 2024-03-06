/*class Envelope
{
	Vector vector;
	friend std::ostream& operator<<(std::ostream&, const Envelope&);
public:
	Envelope(const Vector& vector) : vector( vector ) {
		std::cout << "Envelope(const Vector&)" << std::endl;
	}
	Envelope(Vector&& vector) :
		vector{ std::move(vector) } {
		std::cout << "Envelope(Vector&&)" << std::endl;
	}
	Envelope(const Envelope& other) : vector{ other.vector } {
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
	ostr << "Envelope{vector: " << e.vector << '}';
	return ostr;
}

/*
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
*/