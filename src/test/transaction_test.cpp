#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "transaction_test.h"

void TransactionTest::parseDate() {
    Transaction transaction;
    transaction.setDate("2020-01-31T23:59:59Z");
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Transaction date parsing failed", std::string("2020-01-31T23:59:59Z"), transaction.getDate());
}
