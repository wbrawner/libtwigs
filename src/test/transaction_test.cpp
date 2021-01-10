#include "transaction_test.h"
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <time.h>
#include <twigs/utils.h>

void TransactionTest::serialize() {
  const std::string json =
      R"({"amount":2108,"budgetId":"Gbhqm79yC8NereIONtq7W2Mf9MD2y1AU","categoryId":"Q4R8QLhSksL2wi7XzmrqhL06qm2aZ2S4","createdBy":"1","date":"2021-01-08T13:06:00Z","description":"Books","expense":true,"id":"2snbSS8flrSH6OrvmSEmqyvaduOi2uc2","title":"Amazon"})";

  tm date;
  date.tm_year = 2021;
  date.tm_mon = 0;
  date.tm_mday = 8;
  date.tm_hour = 13;
  date.tm_min = 6;
  date.tm_sec = 0;
  Transaction t =
      Transaction("2snbSS8flrSH6OrvmSEmqyvaduOi2uc2", "Amazon", date, "1", 2108,
                  "Books", true, "Q4R8QLhSksL2wi7XzmrqhL06qm2aZ2S4",
                  "Gbhqm79yC8NereIONtq7W2Mf9MD2y1AU");
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Transaction serialization failed", json,
                               t.serialize());
}

void TransactionTest::deserialize() {
  const std::string json =
      R"({"id":"2snbSS8flrSH6OrvmSEmqyvaduOi2uc2","title":"Amazon","description":"Books","date":"2021-01-08T13:06:00Z","amount":2108,"expense":true,"budgetId":"Gbhqm79yC8NereIONtq7W2Mf9MD2y1AU","categoryId":"Q4R8QLhSksL2wi7XzmrqhL06qm2aZ2S4","createdBy":"1"})";
  Transaction t = Transaction::deserialize(json);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Transaction id parsing failed",
                               std::string("2snbSS8flrSH6OrvmSEmqyvaduOi2uc2"),
                               t.getId());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Transaction name parsing failed",
                               std::string("Amazon"), t.getName());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Transaction description parsing failed",
                               std::string("Books"), t.getDescription());
  tm date = t.getDate();
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Transaction date year parsing failed", 2021,
                               date.tm_year);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Transaction date month parsing failed", 0,
                               date.tm_mon);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Transaction date day parsing failed", 8,
                               date.tm_mday);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Transaction date hour parsing failed", 13,
                               date.tm_hour);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Transaction date min parsing failed", 6,
                               date.tm_min);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Transaction date sec parsing failed", 0,
                               date.tm_sec);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Transaction amount parsing failed", 2108U,
                               t.getAmount());
  CPPUNIT_ASSERT_MESSAGE("Transaction expense parsing failed", t.isExpense());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Transaction budgetId parsing failed",
                               std::string("Gbhqm79yC8NereIONtq7W2Mf9MD2y1AU"),
                               t.getBudgetId());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Transaction category parsing failed",
                               std::string("Q4R8QLhSksL2wi7XzmrqhL06qm2aZ2S4"),
                               t.getCategoryId());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Transaction createdBy parsing failed",
                               std::string("1"), t.getCreatedBy());
}

void TransactionTest::defaultIdsDifferent() {
  Transaction t1;
  Transaction t2;
  CPPUNIT_ASSERT(t1.getId() != t2.getId());
}

void TransactionTest::hashTransaction() {
  tm date;
  date.tm_year = 2021;
  date.tm_mon = 0;
  date.tm_mday = 8;
  date.tm_hour = 13;
  date.tm_min = 6;
  date.tm_sec = 0;
  Transaction t =
      Transaction("2snbSS8flrSH6OrvmSEmqyvaduOi2uc2", "Amazon", date, "1", 2108,
                  "Books", true, "Q4R8QLhSksL2wi7XzmrqhL06qm2aZ2S4",
                  "Gbhqm79yC8NereIONtq7W2Mf9MD2y1AU");
      CPPUNIT_ASSERT_EQUAL_MESSAGE("Transaction hash failed",
                               std::string("94140eb2923e905360cef1e7aca3d321da39f0608ea17eb944475d81b89a64cb"), t.hash());
}
