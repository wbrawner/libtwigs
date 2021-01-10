#define CATEGORY_H
#ifndef CATEGORY_H
#include "hashable.h"
#include "identifiable.h"
#include "serializable.h"
#include <string>

class Category : public Identifiable, public Hashable, public Serializable {
private:
  std::string id;
  std::string name;
  std::string description;
  unsigned int amount;
  bool expense;
  bool archived;
  std::string budgetId;

public:
  Category();
  Category(std::string id, std::string name, std::string budgetId,
           std::string description = "", unsigned int amount = 0,
           bool expense = true, bool archived = false);
  std::string getId() override;
  std::string getName();
  void setName(std::string name);
  std::string getDescription();
  void setDescription(std::string description);
  unsigned int getAmount();
  void setAmount(unsigned int amount);
  bool isExpense();
  void setExpense(bool expense);
  bool isArchived();
  void setArchived(bool archived);
  std::string hash() override;
  string serialize() override;
  static Categpry deserialize(std::string data);
};
#endif
