#include "LLStack.hpp"
#include "catch.hpp"
#include <iostream>

namespace {
TEST_CASE("Single push", "[llstack]") {
  LLStack<int> a;
  a.push(5);
  REQUIRE(a.top() == 5);
}

TEST_CASE("Double push", "[llstack]") {
  LLStack<int> a;
  a.push(5);
  a.push(3);
  REQUIRE(a.top() == 3);
}

TEST_CASE("Pop", "[llstack]") {
  LLStack<int> a;
  a.push(5);
  a.push(3);
  a.pop();
  REQUIRE(a.top() == 5);
}

} // namespace