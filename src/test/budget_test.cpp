#include "budget_test.h"
#include <cppunit/extensions/HelperMacros.h>

void BudgetTest::serialize() {
  const std::string json =
      R"({"description":"Monthly expenses","id":"Gbhqm79yC8NereIONtq7W2Mf9MD2y1AU","name":"Monthly Budget"})";
  Budget b = Budget("Gbhqm79yC8NereIONtq7W2Mf9MD2y1AU", "Monthly Budget",
                    "Monthly expenses");
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Budget serialization failed", json,
                               b.serialize());
}

void BudgetTest::deserialize() {
  const std::string json =
      R"({"description":"Monthly expenses","id":"Gbhqm79yC8NereIONtq7W2Mf9MD2y1AU","name":"Monthly Budget"})";
  Budget b = Budget::deserialize(json);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Budget id parsing failed",
                               std::string("Gbhqm79yC8NereIONtq7W2Mf9MD2y1AU"),
                               b.getId());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Budget name parsing failed",
                               std::string("Monthly Budget"), b.getName());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Budget description parsing failed",
                               std::string("Monthly expenses"),
                               b.getDescription());
}

void BudgetTest::defaultIdsDifferent() {
  Budget b1;
  Budget b2;
  CPPUNIT_ASSERT(b1.getId() != b2.getId());
}

void BudgetTest::hashBudget() {
  Budget b = Budget("Gbhqm79yC8NereIONtq7W2Mf9MD2y1AU", "Monthly Budget",
                    "Monthly expenses");
  CPPUNIT_ASSERT_EQUAL_MESSAGE(
      "Budget hash failed",
      std::string(
          "12fd354740ec016a4b50e2edd1e586107784fe7b88001d8d6ab7ba9ce38aa1d6"),
      b.hash());
}
