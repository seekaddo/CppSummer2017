//
// Created by Addo Dennis on 13/08/2017.
//

#include <iostream>
#include <vector>

class Llocks {
	std::size_t size;
	double *elem;

public:
	Llocks() = default;

	explicit Llocks(std::size_t s) : size(s), elem{new double[s]} {}


	~Llocks() {
		std::cout << "destructor was called" << std::endl;
		delete[] elem;
	}

	//copy constructor with const and &, higher presence as operator copy
	Llocks(const Llocks &llocks) : size(llocks.size),
	                               elem{new double[size]} {
		std::cout << "copy was called" << std::endl;
		std::copy(llocks.elem, llocks.elem + size, elem);
	}


	//copy operator with const and &
	Llocks &operator=(const Llocks &llocks) {
		std::cout << "assignment was called" << std::endl;
		double *nl = new double[llocks.size];
		std::copy(llocks.elem, llocks.elem + llocks.size, nl);
		delete[] elem;
		elem = nl;
		size = llocks.size;
		return *this;
	}

	//move constructor
	Llocks(Llocks &&l) noexcept : size(l.size), elem{l.elem} {
		std::cout << "move was called" << std::endl;

		l.elem = nullptr;
		l.size = 0;
	}


	//move operator
	Llocks& operator=(Llocks&& l)noexcept{
		std::cout << "move operate was called" << std::endl;
		delete[] elem;
		elem = l.elem;
		size = l.size;

		l.elem = nullptr;
		l.size = 0;
		return *this;
	}


	void setLock(size_t i, double val) {
		elem[i] = val;
	}

	double& operator[](size_t i) {
		return elem[i];
	}

	//small object non-ref & will be ok
	double& operator[](size_t i) const {
		return elem[i];
	}



};


Llocks tesm(size_t va){
	Llocks y(va);
	y.setLock(0,44);
	y.setLock(1,90);
	return y; //copy elision will happen here https://stackoverflow.com/questions/13099603/c11-move-constructor-not-called-default-constructor-preferred
}

int main() {

	Llocks l1(2);
	const Llocks lp(2);

	l1[0] = 3.4;
	lp[0] = 0.4;
	l1.setLock(1, 5.4);
	Llocks l2 = tesm(2); //copy elision happening here but with g++ -fno-elide-constructors will work


	std::cout << "l1 is " << l1[0] << " AND l2 is " << l2[0] <<" " <<lp[0] << std::endl;


	std::vector<Llocks> v;
	v.push_back(Llocks(25));
	v.push_back(Llocks(75));

	// Insert a new element into the second position of the vector.
	v.insert(v.begin() + 1, Llocks(50));



	return 0;
}