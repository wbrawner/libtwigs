#include <string>
#include <twigs/budget.h>
#include <twigs/utils.h>
#include <jsoncpp/json/json.h>

Budget::Budget() : Budget(util::randomId(), "", "") {}

Budget::Budget(std::string id, std::string name, std::string description)
    : id(id), name(name), description(description) {}

std::string Budget::getId() { return this->id; }

string Budget::getName() { return this->name; }

void Budget::setName(string name) { this->name = name; }

string Budget::getDescription() { return this->description; }

void Budget::setDescription(string description) {
  this->description = description;
}

std::string Budget::serialize() {
  Json::Value budget;
  budget["id"] = this->getId();
  budget["name"] = this->getName();
  budget["description"] = this->getDescription();
  Json::StreamWriterBuilder builder;
  builder["indentation"] = "";
  return Json::writeString(builder, budget);
}

Budget Budget::deserialize(std::string data) {
  Json::CharReaderBuilder builder;
  Json::Value root;
  if (!builder.newCharReader()->parse(&data[0], &data[0] + data.size(), &root,
                                      NULL)) {
    // TODO: Log errors
    //         std::cout << "Failed to create budget from JSON" << "\n";
    throw 5;
  }
  std::string id = root.get("id", "").asString();
  if (id == "") {
    throw 5;
  }
  std::string name = root.get("name", "").asString();
  std::string description = root.get("description", "").asString();
  return Budget(id, name, description);
}

string Budget::hash() { return util::hash(serialize()); }
