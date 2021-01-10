#ifndef BUDGET_H
#define BUDGET_H
#include "hashable.h"
#include "identifiable.h"
#include "serializable.h"
#include <string>

using namespace std;

class Budget : public Identifiable, public Hashable, public Serializable {
private:
  string id;
  string name;
  string description;

public:
  Budget();
  Budget(std::string id, std::string name, std::string description);
  string getId() override;
  string getName();
  void setName(string name);
  string getDescription();
  void setDescription(string description);
  string hash() override;
  string serialize() override;
  static Budget deserialize(std::string data);
};
#endif
