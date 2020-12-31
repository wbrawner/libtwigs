#ifndef CATEGORY_H
#define CATEGORY_H
#include <string>
#include "hashable.h"
#include "identifiable.h"

class Category: public Identifiable, public Hashable {
    private:
        std::string id;
        std::string name;
        std::string description;
        long amount;
        bool expense;
        bool archived;
        std::string budgetId;

    public:
        std::string getId() {
            return this->id;
        }
        
        std::string getName() {
            return this->name;
        }
        
        void setName(std::string name) {
            this->name = name;
        }
        
        std::string getDescription() {
            return this->description;
        }
        
        void setDescription(std::string description) {
            this->description = description;
        }
        
        long getAmount() {
            return this->amount;
        }
        
        void setAmount(long amount) {
            this->amount = amount;
        }
        
        bool isExpense() {
            return this->expense;
        }
        
        void setExpense(bool expense) {
            this->expense = expense;
        }
        
        bool isArchived() {
            return this->archived;
        }
        
        void setArchived(bool archived) {
            this->archived = archived;
        }
        
        std::string hash() override;
};
#endif
