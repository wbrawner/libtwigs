#include <random>
#include <twigs/utils.h>
#include <openssl/sha.h>

namespace util {
std::string randomId() {
  const std::string CHARACTERS =
      "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  const int ID_LEN = 32;

  std::random_device rd;
  std::mt19937 engine(rd());
  std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

  std::string random_string;

  for (std::size_t i = 0; i < ID_LEN; ++i) {
    random_string += CHARACTERS[distribution(engine)];
  }

  return random_string;
}

tm parseDate(std::string str) {
  static tm date;
  // TODO: Handle exceptions
  int year = stoi(str.substr(0, 4));
  int mon = stoi(str.substr(5, 2));
  int day = stoi(str.substr(8, 2));
  int hours = stoi(str.substr(11, 2));
  int min = stoi(str.substr(14, 2));
  int sec = stoi(str.substr(17, 2));
  date.tm_year = year;
  date.tm_mon = mon - 1;
  date.tm_mday = day;
  date.tm_hour = hours;
  date.tm_min = min;
  date.tm_sec = sec;
  return date;
}

std::string printDate(tm date) {
  static char str[25];
  snprintf(str, 21, "%04d-%02d-%02dT%02d:%02d:%02dZ", date.tm_year,
           date.tm_mon + 1, date.tm_mday, date.tm_hour, date.tm_min,
           date.tm_sec);
  return str;
}

std::string hash(std::string data) {
    unsigned char bytes[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *) &data[0], data.size(), bytes);
    char hash[(SHA256_DIGEST_LENGTH * 2) + 1];
    int i;
    for(i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hash + (i * 2), "%02x", bytes[i]);
    }
    hash[SHA256_DIGEST_LENGTH * 2] = '\0';
    return std::string(hash, SHA256_DIGEST_LENGTH * 2);
}
} // namespace util
