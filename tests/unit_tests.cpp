#include "gtest/gtest.h"
#include "../iterator.hpp"
#include "../lab04/mult.hpp"
#include "../lab04/div.hpp"
#include "../lab04/sub.hpp"
#include "../lab04/add.hpp"
#include "../lab04/op.hpp"
#include "../lab04/rand.hpp"
#include "../lab04/pow.hpp"
#include "../lab04/rand.hpp"
#include <string>


TEST(IteratorTest, OpTest){
	Base* Op1 = new Op(1);
	Iterator* test = Op1->create_iterator();
    while (test->is_done() == false){
        test->next();
    }

	EXPECT_EQ(test->is_done(), true);
}

TEST(IteratorTest, RandTest){
	Base* Rand1 = new Rand;
	Iterator* test = Rand1->create_iterator();
    while (test->is_done() == false){
        test->next();
    }

	EXPECT_EQ(test->is_done(), true);
}

TEST(IteratorTest, AddTest){
	Base* Op1 = new Op(1);
    Base* Op2 = new Op(2);
    Base* Add1 = new Add(Op1, Op2);

    Iterator* test = Add1->create_iterator();

    while (test->is_done() == false){
        test->next();
    }

	EXPECT_EQ(test->is_done(), true);
}

TEST(IteratorTest, SubTest){
	Base* Op1 = new Op(1);
    Base* Op2 = new Op(2);
    Base* Sub1 = new Sub(Op1, Op2);

    Iterator* test = Sub1->create_iterator();

    while (test->is_done() == false){
        test->next();
    }

	EXPECT_EQ(test->is_done(), true);
}

TEST(IteratorTest, MultTest){
	Base* Op1 = new Op(1);
    Base* Op2 = new Op(2);
    Base* Mult1 = new Mult(Op1, Op2);

    Iterator* test = Mult1->create_iterator();

    while (test->is_done() == false){
        test->next();
    }

	EXPECT_EQ(test->is_done(), true);
}

TEST(IteratorTest, DivTest){
	Base* Op1 = new Op(1);
    Base* Op2 = new Op(2);
    Base* Div1 = new Div(Op1, Op2);

    Iterator* test = Div1->create_iterator();

    while (test->is_done() == false){
        test->next();
    }

	EXPECT_EQ(test->is_done(), true);
}

TEST(IteratorTest, PowTest){
	Base* Op1 = new Op(1);
    Base* Op2 = new Op(2);
    Base* Pow1 = new Pow(Op1, Op2);

    Iterator* test = Pow1->create_iterator();

    while (test->is_done() == false){
        test->next();
    }

	EXPECT_EQ(test->is_done(), true);
}

TEST(IteratorTest, TreeTest1){
    Base* Op1 = new Op(1);
    Base* Op2 = new Op(2);
	Base* Op3 = new Op(3);
    Base* Pow1 = new Pow(Op1, Op2);
	Base* Mult1 = new Mult(Pow1, Op3);
	Base* Div1 = new Div(Op1, Op3);
	Base* Add1 = new Add(Mult1, Div1);

    Iterator* test = Add1->create_iterator();

    while (test->is_done() == false){
        test->next();
    }

    EXPECT_EQ(test->is_done(), true);
}

TEST(IteratorTest, TreeTest2){
    Base* Op1 = new Op(1);
    Base* Op2 = new Op(2);
    Base* Op3 = new Op(3);
    Base* Op4 = new Op(4);
    Base* Op5 = new Op(5);
    Base* Op6 = new Op(6);

    Base* Pow1 = new Pow(Op1, Op2);
    Base* Mult1 = new Mult(Pow1, Op3);
    Base* Div1 = new Div(Op1, Op3);
    Base* Add1 = new Add(Mult1, Div1);	
    Base* Pow2 = new Pow(Op4, Add1);
    Base* Mult2 = new Mult(Pow2, Op5);
    Base* Div2 = new Div(Op5, Op2);
    Base* Sub1 = new Add(Div2, Mult2);

    Iterator* test = Sub1->create_iterator();

    while (test->is_done() == false){
        test->next();
    }

    EXPECT_EQ(test->is_done(), true);
}

TEST(CountVisitorTest, SizeThreeTree){
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

    EXPECT_EQ(v->mult_count(), 1);
    EXPECT_EQ(v->op_count(), 2);
    EXPECT_EQ(v->rand_count(), 1);
    EXPECT_EQ(v->pow_count(), 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
