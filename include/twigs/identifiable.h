#ifndef IDENTIFIABLE_H
#define IDENTIFIABLE_H
#include <string>

class Identifiable {
    private:
        std::string id;
    
    public:
        std::string getId() {
            return this->id;
        }
        void setId(std::string id) {
            this->id = id;
        }
};
#endif
