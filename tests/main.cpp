#include "../iterator.hpp"
#include "../visitor.hpp"
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
    Base* Dummy = new Pow(Mult1, new Rand());

    CountVisitor* v = new CountVisitor();
    Iterator* test = new PreorderIterator(Dummy);
    test->first();

    while (test->is_done() == false){
        Base* phase = test->current();
        phase->accept(v);
        test->next();
    }

    cout << v->mult_count() << v->op_count() << v->rand_count() << v->pow_count() << endl;
    //should be 1210
    return 0;
}