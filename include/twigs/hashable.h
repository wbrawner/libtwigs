#ifndef HASHABLE_H
#define HASHABLE_H
#include <string>

class Hashable {
    public:
        virtual std::string hash() = 0;
};
#endif
