#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include <stdio.h>
#include <time.h>
#include "hashable.h"
#include "identifiable.h"

using namespace std;

class Transaction: public Identifiable, public Hashable {
    private:
        string name;
        string description;
        tm date;
        long amount;
        bool expense;
        bool archived;
        string categoryId;
        string budgetId;

    public:
        Transaction() {
            this->name = "";
            this->description = "";
            time_t now = time(0);
            this->date = *gmtime(&now);
            this->amount = 0;
            this->expense = true;
            this->archived = false;
        }
        
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
        
        /**
         * Returns the date as a string formatted as YYYY-MM-ddTHH:mm:ssZ
         */
        string getDate() {
            char date[25];
            snprintf(
                date,
                21,
                "%04d-%02d-%02dT%02d:%02d:%02dZ",
                this->date.tm_year,
                this->date.tm_mon + 1,
                this->date.tm_mday,
                this->date.tm_hour,
                this->date.tm_min,
                this->date.tm_sec
            );
            return date;
        }
        
        /**
         * Sets the date using YYYY-MM-ddTHH:mm:ssZ format
         */
        void setDate(string date) {
            //TODO: Handle exceptions
            int year = stoi(date.substr(0,4));
            int mon = stoi(date.substr(5, 2));
            int day = stoi(date.substr(8, 2));
            int hours = stoi(date.substr(11, 2));
            int min = stoi(date.substr(14, 2));
            int sec = stoi(date.substr(17, 2));
            this->date.tm_year = year;
            this->date.tm_mon = mon - 1;
            this->date.tm_mday = day;
            this->date.tm_hour = hours;
            this->date.tm_min = min;
            this->date.tm_sec = sec;
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
        
        string hash() override;
};
#endif
