#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include "op.hpp"
#include "../iterator.hpp"
#include <string>
#include <iostream>

class Mult : public Base {
   private:
        Base* _lChild = nullptr;
		Base* _rChild = nullptr;

   public:
   		Mult(Base* left, Base* right) {
		    _lChild = left;
			_rChild = right;
		}

		virtual double evaluate() { 
			return _lChild->evaluate() * _rChild->evaluate(); 
		}

		virtual std::string stringify() {
			std::stringstream out;
            out << std::setprecision(5) << _lChild->stringify() << " * " << _rChild->stringify();
            return out.str();
		}

		virtual Iterator* create_iterator(){
            Iterator* temp =  new BinaryIterator(this);
            return temp;
        }

		virtual Base* get_left(){
            return _lChild;
        }

        virtual Base* get_right(){
            return _rChild;
        }

        virtual void accept(CountVisitor* v){
            v->visit_mult();
        }
};

#endif //__MULT_HPP__
