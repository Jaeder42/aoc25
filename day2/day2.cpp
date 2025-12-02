#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string &str, char delimiter) {
  std::vector<std::string> tokens;
  size_t start = 0;
  size_t end = str.find(delimiter);

  while (end != std::string::npos) {
    tokens.push_back(str.substr(start, end - start));
    start = end + 1;
    end = str.find(delimiter, start);
  }

  tokens.push_back(str.substr(start));
  return tokens;
}

bool repeating(std::string input, int chunk) {
  if (input.length() % chunk != 0) {
    return false;
  }
  std::string first = input.substr(0, chunk);
  for (int j = chunk; j < input.length(); j += chunk) {

    std::string nextChunk = input.substr(j, chunk);
    if (nextChunk != first) {
      // std::cout << first << ":" << nextChunk << " -" << input << "\n";
      return false;
    }
  }
  std::cout << "found repeating: " << input << " chunksize:  " << chunk << "\n";
  return true;
}

int main() {
  std::ifstream file("./day2/input.txt");
  std::string str;
  long total = 0;
  while (std::getline(file, str)) {
    if (!str.empty()) {

      auto splittedLines = split(str, ',');
      for (const auto &line : splittedLines) {
        // std::cout << line + "\n";

        auto splittedLine = split(line, '-');
        // std::cout << line << "\n";
        for (long i = std::stol(splittedLine[0]);
             i < std::stol(splittedLine[1]) + 1; i++) {
          // std::cout << i << "\n";
          std::string toStringed = std::to_string(i);
          std::set<long> matches = {};
          for (int j = 1; j < toStringed.length(); j++) {
            // std::cout << "chunk: " << j << "\n";
            if (repeating(toStringed, j)) {
              matches.insert(i);
            }
          }
          for (long match : matches) {
            total += match;
          }
        }
      }
    }
  }
  std::cout << total;
}
