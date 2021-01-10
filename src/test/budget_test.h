#ifndef BUDGET_TEST_H_INCLUDED
#define BUDGET_TEST_H_INCLUDED

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <twigs/budget.h>

class BudgetTest: public CppUnit::TestCase {
public:
    void serialize();
    void deserialize();
    void defaultIdsDifferent();
    void hashBudget();

    CPPUNIT_TEST_SUITE( BudgetTest );
    CPPUNIT_TEST( serialize );
    CPPUNIT_TEST( deserialize );
    CPPUNIT_TEST( defaultIdsDifferent );
    CPPUNIT_TEST( hashBudget );
    CPPUNIT_TEST_SUITE_END();
};


#endif // BUDGET_TEST_H_INCLUDED
