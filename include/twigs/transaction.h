#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "hashable.h"
#include "identifiable.h"
#include "serializable.h"
#include <stdio.h>
#include <string>
#include <time.h>

class Transaction : public Identifiable, public Hashable, public Serializable {
private:
  std::string id;
  std::string name;
  std::string description;
  tm date;
  unsigned int amount;
  bool expense;
  std::string categoryId;
  std::string budgetId;
  std::string createdBy;

public:
  Transaction();
  Transaction(std::string id, std::string name, tm date, std::string createdBy,
              unsigned int amount = 0, std::string description = "",
              bool expense = true, std::string categoryId = "",
              std::string budgetId = "");
  std::string getId() override;
  std::string getName();
  void setName(std::string name);
  std::string getDescription();
  void setDescription(std::string description);
  tm getDate();
  void setDate(tm date);
  unsigned int getAmount();
  void setAmount(unsigned int amount);
  bool isExpense();
  void setExpense(bool expense);
  bool isArchived();
  void setArchived(bool archived);
  std::string getCategoryId();
  void setCategoryId(std::string categoryId);
  std::string getBudgetId();
  void setBudgetId(std::string budgetId);
  std::string getCreatedBy();
  void setCreatedBy(std::string createdBy);
  std::string hash() override;
  std::string serialize() override;
  static Transaction deserialize(std::string data);
};
#endif
