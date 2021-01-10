#ifndef UTILS_TEST_H_INCLUDED
#define UTILS_TEST_H_INCLUDED

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <twigs/utils.h>

class UtilsTest: public CppUnit::TestCase {
public:
    void parseDateTest();
    void printDateTest();
    void hashTest();
    
    CPPUNIT_TEST_SUITE( UtilsTest );
    CPPUNIT_TEST( parseDateTest );
    CPPUNIT_TEST( printDateTest );
    CPPUNIT_TEST( hashTest );
    CPPUNIT_TEST_SUITE_END();
};

#endif // UTILS_TEST_H_INCLUDED
