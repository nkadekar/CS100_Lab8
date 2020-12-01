#include "gtest/gtest.h"
#include "../lab04/mult.hpp"
#include "../lab04/div.hpp"
#include "../lab04/sub.hpp"
#include "../lab04/add.hpp"
#include "../lab04/op.hpp"
#include "../lab04/rand.hpp"
#include "../lab04/pow.hpp"
#include <string>
#include <sstream>


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
