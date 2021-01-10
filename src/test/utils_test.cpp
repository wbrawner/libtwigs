#include "utils_test.h"
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

void UtilsTest::parseDateTest() {}

void UtilsTest::printDateTest() {
  tm date;
  date.tm_year = 2020;
  date.tm_mon = 0;
  date.tm_mday = 31;
  date.tm_hour = 23;
  date.tm_min = 59;
  date.tm_sec = 59;
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Date printing failed",
                               std::string("2020-01-31T23:59:59Z"),
                               util::printDate(date));
}

void UtilsTest::hashTest() { 
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Hashing failed",
                               std::string("9f86d081884c7d659a2feaa0c55ad015a3bf4f1b2b0b822cd15d6c15b0f00a08"),
                               util::hash("test"));
}
