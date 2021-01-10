#include <twigs/category.h>
#include <twigs/utils.h>

Category::Category() : Category(util::randomId(), "", "") {}

Category::Category(std::string id, std::string name, std::string budgetId,
                   std::string description, unsigned int amount, bool expense,
                   bool archived)
    : id(id), name(name), budgetId(budgetId), description(description),
      amount(amount), expense(expense), archived(archived) {}

std::string Category::getId() { return this->id; }

std::string Category::getName() { return this->name; }

void Category::setName(std::string name) { this->name = name; }

std::string Category::getDescription() { return this->description; }

void Category::setDescription(std::string description) {
  this->description = description;
}

long Category::getAmount() { return this->amount; }

void Category::setAmount(long amount) { this->amount = amount; }

bool Category::isExpense() { return this->expense; }

void Category::setExpense(bool expense) { this->expense = expense; }

bool Category::isArchived() { return this->archived; }

void Category::setArchived(bool archived) { this->archived = archived; }

std::string Category::getBudgetId() { return this->budgetId; }

void Category::setBudgetId(std::string budgetId) { this->budgetId = budgetId; }

std::string Category::serialize() {
  Json::Value category;
  category["id"] = this->getId();
  category["name"] = this->getName();
  category["description"] = this->getDescription();
  category["amount"] = this->getAmount();
  category["expense"] = this->isExpense();
  category["archived"] = this->isArchived();
  category["budgetId"] = this->getBudgetId();
  Json::StreamWriterBuilder builder;
  builder["indentation"] = "";
  return Json::writeString(builder, transaction);
}

Category Category::deserialize(std::string data) {
  Json::CharReaderBuilder builder;
  Json::Value root;
  if (!builder.newCharReader()->parse(&data[0], &data[0] + data.size(), &root,
                                      NULL)) {
    // TODO: Log errors
    //         std::cout << "Failed to create transaction from JSON" << "\n";
    throw 5;
  }
  std::string id = root.get("id", "").asString();
  if (id == "") {
    throw 5;
  }
  std::string name = root.get("name", "").asString();
  std::string description = root.get("description", "").asString();
  long amount = root.get("amount", 0).asUInt();
  bool expense = root.get("expense", true).asBool();
  bool archived = root.get("archived", true).asBool();
  std::string budgetId = root.get("budgetId", "").asString();
  return Category(id, name, description);
}

string Category::hash() { return util::hash(serialize()); }
