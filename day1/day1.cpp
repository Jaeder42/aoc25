#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream file("./day1/input.txt");
  std::string str;

  int start = 50;
  int password = 0;
  while (std::getline(file, str)) {
    if (str.empty()) {
      continue;
    }
    std::string direction = str.substr(0, 1);
    std::string amountString = str.substr(1);
    int amount = stoi(amountString);
    if (direction == "L") {
      password += (amount / 100);
      amount = (amount % 100);
      start -= amount;
      if (start < 0) {
        if (abs(start) != abs(amount)) {
          password += 1;
        }
        start = 100 + start;
      }
      if (start == 0) {
        password += 1;
      }

    } else {
      if (amount >= 100) {
        password += (amount / 100);
      }
      start += amount % 100;
      if (start >= 100) {
        password += 1;
      }
    }
    start = start % 100;

    std::cout << direction + amountString + " = " + std::to_string(start) +
                     " " + std::to_string(password) + "\n";
  }
  std::cout << std::to_string(password) + "\n";
}
