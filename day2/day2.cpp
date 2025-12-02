#include <fstream>
#include <iostream>
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

bool isRepeating(const std::string &str, int divisions) {
  int length = str.length();

  if (length % divisions != 0) {
    return false;
  }

  int chunkSize = length / divisions;

  std::string firstChunk = str.substr(0, chunkSize);

  for (int i = 1; i < divisions; i++) {
    std::string nextChunk = str.substr(i * chunkSize, chunkSize);

    if (nextChunk != firstChunk) {
      return false;
    }
  }

  return true;
}

long sumMatchingPattern(long start, long end, int divisions) {
  long total = 0;

  for (long i = start; i < end; i++) {
    std::string toStringed = std::to_string(i);

    if (isRepeating(toStringed, divisions)) {
      total += i;
      std::cout << " Found (" << divisions << " parts): " << toStringed << "\n";
    }
  }
  return total;
}

int main() {
  std::ifstream file("./day2/test.txt");
  std::string str;
  long total = 0;
  while (std::getline(file, str)) {
    auto splittedLines = split(str, ',');
    for (const auto &line : splittedLines) {
      // std::cout << line + "\n";
      auto splittedLine = split(line, '-');
      std::cout << splittedLine[0] << "-" << splittedLine[1];
      for (int i = 2; i < line.length() / 2; i++) {
        total += sumMatchingPattern(std::stol(splittedLine[0]),
                                    std::stol(splittedLine[1]), i);
      }
    }
  }
  std::cout << total;
}
