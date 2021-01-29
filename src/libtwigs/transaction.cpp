#include <jsoncpp/json/json.h>
#include <twigs/serializable.h>
#include <twigs/transaction.h>
#include <twigs/utils.h>

using namespace std;

tm *now() {
  time_t now = time(NULL);
  return gmtime(&now);
}

Transaction::Transaction() : Transaction(util::randomId(), "", *now(), "") {}

Transaction::Transaction(std::string id, std::string name, tm date,
                         std::string createdBy, unsigned int amount,
                         std::string description, bool expense,
                         std::string categoryId, std::string budgetId)
    : id(id), name(name), description(description), date(date), amount(amount),
      expense(expense), categoryId(categoryId), budgetId(budgetId),
      createdBy(createdBy) {}

string Transaction::getId() { return this->id; }

string Transaction::getName() { return this->name; }

void Transaction::setName(std::string name) { this->name = name; }

string Transaction::getDescription() { return this->description; }

void Transaction::setDescription(string description) {
  this->description = description;
}

tm Transaction::getDate() { return this->date; }

void Transaction::setDate(tm date) { this->date = date; }

unsigned int Transaction::getAmount() { return this->amount; }

void Transaction::setAmount(unsigned int amount) { this->amount = amount; }

bool Transaction::isExpense() { return this->expense; }

void Transaction::setExpense(bool expense) { this->expense = expense; }

string Transaction::getCategoryId() { return this->categoryId; }

void Transaction::setCategoryId(string categoryId) {
  this->categoryId = categoryId;
}

string Transaction::getBudgetId() { return this->budgetId; }

void Transaction::setBudgetId(string budgetId) { this->budgetId = budgetId; }

string Transaction::getCreatedBy() { return this->createdBy; }

void Transaction::setCreatedBy(string createdBy) {
  this->createdBy = createdBy;
}

std::string Transaction::serialize() {
  Json::Value transaction;
  transaction["id"] = this->getId();
  transaction["title"] = this->getName();
  transaction["description"] = this->getDescription();
  transaction["date"] = util::printDate(this->getDate());
  transaction["amount"] = this->getAmount();
  transaction["expense"] = this->isExpense();
  transaction["budgetId"] = this->getBudgetId();
  transaction["categoryId"] = this->getCategoryId();
  transaction["createdBy"] = this->getCreatedBy();
  Json::StreamWriterBuilder builder;
  builder["indentation"] = "";
  return Json::writeString(builder, transaction);
}

Transaction Transaction::deserialize(std::string data) {
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
  std::string name = root.get("title", "").asString();
  std::string description = root.get("description", "").asString();
  std::string dateStr = root.get("date", "").asString();
  tm date = util::parseDate(dateStr);
  long amount = root.get("amount", 0).asUInt();
  bool expense = root.get("expense", true).asBool();
  std::string budgetId = root.get("budgetId", "").asString();
  std::string categoryId = root.get("categoryId", "").asString();
  std::string createdBy = root.get("createdBy", "").asString();
  return Transaction(id, name, date, createdBy, amount, description, expense,
                     categoryId, budgetId);
}

string Transaction::hash() { return util::hash(serialize()); }
