#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include "op.hpp"
#include <string>
#include <cmath>

using namespace std;

class Pow: public Base {
   private:
	   Base* leftChild = nullptr;
   	   Base* rightChild = nullptr;
    public:
	   	Pow(Base* leftChild, Base* rightChild) {
	   		this->leftChild = leftChild;
			this->rightChild = rightChild;
	   	}
	   	virtual double evaluate() { 
			return pow(leftChild->evaluate(), rightChild->evaluate()); 
		}

	   	virtual std::string stringify() {
			std::ostringstream inSS;
			inSS << std::setprecision(5) << leftChild->stringify() << " - " << rightChild->stringify();
			return inSS.str();
		}
};

#endif //__POW_HPP__
