#ifndef USER_H
#define USER_H
#include <string>
#include "identifiable.h"

class User: public Identifiable {
    private:
        std::string name;
        std::string email;
        std::string avatar;

    public:
        std::string getName();
        void setName(std::string name);
        std::string getEmail();
        void setEmail(std::string email);
        std::string getAvatar();
        void setAvatar(std::string avatar);
};
#endif
