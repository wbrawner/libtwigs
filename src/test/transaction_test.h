#ifndef TRANSACTION_TEST_H_INCLUDED
#define TRANSACTION_TEST_H_INCLUDED

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <twigs/transaction.h>

class TransactionTest: public CppUnit::TestCase {
public:
    void parseDate();
    
    CPPUNIT_TEST_SUITE( TransactionTest );
    CPPUNIT_TEST( parseDate );
    CPPUNIT_TEST_SUITE_END();
};


#endif // TRANSACTION_TEST_H_INCLUDED
