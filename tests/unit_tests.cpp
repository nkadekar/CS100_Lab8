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

}

TEST(IteratorTest, TreeTest2){

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
