#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include "../iterator.hpp"
#include <string>
#include <iostream>

class Rand: public Base {
	private:
		double num;

    public:
        Rand() {
			num = rand() % 100;
		}

        virtual double evaluate() {
			return num;
		}

        virtual std::string stringify() {
			return std::to_string(num);
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

#endif //__RAND_HPP__
