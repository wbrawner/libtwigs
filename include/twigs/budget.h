#ifndef BUDGET_H
#define BUDGET_H
#include <string>
#include "hashable.h"
#include "identifiable.h"

using namespace std;

class Budget: public Identifiable, public Hashable {
    private:
        string name;
        string description;

    public:
        string getName() {
            return this->name;
        }
        
        void setName(string name) {
            this->name = name;
        }
        
        string getDescription() {
            return this->description;
        }
        
        void setDescription(string description) {
            this->description = description;
        }
        
        string hash() override;
};
#endif
