#include "../iterator.hpp"
#include "../lab04/mult.hpp"
#include "../lab04/div.hpp"
#include "../lab04/sub.hpp"
#include "../lab04/add.hpp"
#include "../lab04/op.hpp"
#include "../lab04/rand.hpp"
#include "../lab04/pow.hpp"
#include <string>
#include <typeinfo>
#include <iostream>

using namespace std;

int main(){
    Base* Op1 = new Op(1);
    Base* Op2 = new Op(2);
    Base* Mult1 = new Mult(Op1, Op2);

    Iterator* test = Mult1->create_iterator();

    while (test->is_done() == false){
        test->next();
    }

    cout << test->is_done() << endl;

    return 0;
}