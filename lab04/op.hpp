#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "../iterator.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Op : public Base {
    private:
		double num;

    public:
        Op(double value) : Base() {
			num = value;
		}

        virtual double evaluate() { 
			return num;
		}

        virtual std::string stringify() {
			std::stringstream out;
            out << num;
            return out.str();
		}

		virtual Iterator* create_iterator(){
            Iterator* temp =  new NullIterator(this);
            return temp;
        }

		virtual Base* get_left(){
            return nullptr;
        }

        virtual Base* get_right(){
            return nullptr;
        }		
};

#endif //__OP_HPP__
