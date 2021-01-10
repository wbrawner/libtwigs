#define TRANSACTION_REPOSITORY_H
#ifndef TRANSACTION_REPOSITORY_H
#include "transaction.h"

class TransactionRepository {
public:
  Transaction findById(std::string id);
  Transaction *findAll(std::string *budgetIds, std::string *categoryIds,
                       std::string *from, std::string *to, int count, int page);
  Transaction save(Transaction transaction);
  void remove(Transaction transaction);
};
#endif
