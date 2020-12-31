#ifndef PERMISSION_H
#define PERMISSION_H
#include "budget.h"
#include "identifiable.h"
#include "user.h"
#include <string>

enum Permission {
    READ,
    WRITE,
    OWNER
};

class UserPermission: public Identifiable {
    private:
        std::string userId;
        std::string budgetId;
        Permission permission;

    public:
        UserPermission(std::string userId, std::string budgetId) {
            this->userId = userId;
            this->budgetId = budgetId;
        }
        
        std::string getUserId() {
            return this->userId;
        }
        
        std::string getBudgetId() {
            return this->budgetId;
        }
        
        Permission getPermission() {
            return this->permission;
        }
        
        void setPermission(Permission permission) {
            this->permission = permission;
        }
};
#endif
