#ifndef IDENTIFIABLE_H
#define IDENTIFIABLE_H
#include <string>

class Identifiable {
    public:
        virtual std::string getId() = 0;
};
#endif
