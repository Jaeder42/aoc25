#include <fstream>
#include <iostream>
#include <map>
#include <string>

void findNext(std::map<int, std::string> &found, std::string &total) {
  int largest = 0;
  int indexLargest = 0;
  for (int i = total.length() - 1; i >= 0; i++) {
    int num = total[i] - '0';
    if (largest <= num) {
      if (!found.empty()) {

        // std::cout << found[0];
      }
      largest = num;
      indexLargest = i;
    }
  }
  // total[indexLargest] = '0';
  found[indexLargest] = std::to_string(largest);
  // std::cout << total << " -> ";
}

int main() {
  std::ifstream file("./day3/test.txt");
  std::string str;
  long total = 0;
  while (std::getline(file, str)) {
    if (str.empty()) {
      std::cout << "failed";
      continue;
    }

    std::map<int, std::string> found;
    int x = 0;
    std::cout << str << ": ";
    while (found.size() < 12) {
      findNext(found, str);
    }
    std::string combined;
    for (int i = 0; i < found.size(); i++) {
      std::string val = found[i];
      combined += val;
    }

    std::cout << combined << "\n";
    total += std::stol(combined);
    // int largestFirst = 0;
    // int largestFirstIndex = 0;
    // for (int i = 0; i < str.length(); i++) {
    //   int num = str[i] - '0';
    //   if (largestFirst < num) {
    //
    //     largestFirst = num;
    //     largestFirstIndex = i;
    //   }
    // }
    // int largestSecond = 0;
    // int start = largestFirstIndex + 1;
    // int end = str.length();
    // bool flipped = false;
    // if (start >= end) {
    //   start = 0;
    //   end = largestFirstIndex;
    //   flipped = true;
    // }
    // for (int i = start; i < end; i++) {
    //   int num = str[i] - '0';
    //   if (largestSecond < num) {
    //     largestSecond = num;
    //   }
    // }
    // std::string final =
    //     std::to_string(largestFirst) + std::to_string(largestSecond);
    // if (flipped) {
    //   final = std::to_string(largestSecond) + std::to_string(largestFirst);
    // }
    // std::cout << "found: " << final << "\n";
    // total += std::stol(final); // part1
  }
  std::cout << "Total: " << total << "\n";
}
