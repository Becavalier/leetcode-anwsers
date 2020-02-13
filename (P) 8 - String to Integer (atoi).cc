
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

/**
 * This solution has not survived all the test cases;
 */ 
class Solution {
public:
  int myAtoi(string str) {
    unordered_map<char, int> validDigits = {
      {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, 
      {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}};
    vector<char> result;
    int prefix = 0;
    for (auto i = 0; i < str.length(); i++) {
      char c = str.at(i);
      // "  0000000000012345678";
      if (c == ' ') {
        // "   +0 123";
        continue;
      } else if (c == '0' && result.size() == 0) {
        continue;
      } else if (validDigits.find(c) != validDigits.end()) {
        // valid nums;
        result.push_back(c);
      } else {
        // "+-2";
        if (c == '-' && prefix == 0) {
          prefix = -1;
        } else if (c == '+' && prefix == 0) {
          prefix = 1;
        } else {
          break;
        }
      }
    }
    
    // get the digits sequence of the maxmium number for comparison;
    int max = numeric_limits<int>::max();
    vector<int> seq;
    while(true) {
      seq.push_back(max % 10);
      if (max <= 9 && max >= -9) { break; }
      max /= 10;
    } 
    
    // transform to number;
    int num = 0;
    const int size = result.size();
    for (auto x = 0; x < size; x++) {
      const int c = result[x];
      if (validDigits.find(c) != validDigits.end()) {
        if (size > seq.size()) {
          return (prefix > 0 && prefix == 1) ? numeric_limits<int>::max() : numeric_limits<int>::min();
        } else if (size == seq.size()) {
          // MSB -> LSB;
          if (validDigits[c] > seq[size - x - 1]) {
            return (prefix > 0 && prefix == 1) ? numeric_limits<int>::max() : numeric_limits<int>::min();
          }
          num += validDigits[c] * pow(10, (size - x - 1));
        } else {
          // safe number;
          num += validDigits[c] * pow(10, (size - x - 1));
        }
      }
    }
    return prefix == 0 ? num : num * prefix;
  }
};
