#include <cppunit/TextTestRunner.h>
#include "budget_test.h"
#include "transaction_test.h"
#include "utils_test.h"

CPPUNIT_TEST_SUITE_REGISTRATION (UtilsTest);
CPPUNIT_TEST_SUITE_REGISTRATION (BudgetTest);
CPPUNIT_TEST_SUITE_REGISTRATION (TransactionTest);

int main() {
    BudgetTest budgetTest;
    TransactionTest transactionTest;
    UtilsTest utilsTest;
    
    CppUnit::Test *test = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
    CppUnit::TextTestRunner runner;
    runner.addTest(test);
    runner.run();
    return 0;
}
