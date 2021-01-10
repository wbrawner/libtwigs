#ifndef UTILS_H
#define UTILS_H
#include <string>

namespace util {
std::string randomId();
std::string hash(std::string data);
tm parseDate(std::string str);
std::string printDate(tm date);
} // namespace util

#endif
