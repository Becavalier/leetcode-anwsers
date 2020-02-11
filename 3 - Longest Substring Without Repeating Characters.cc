#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    // implemented by sliding window;
    /**
     * | a | b | c | a | b | c | b | b |
     * { i    ...    j } (unordered_map); 
     */ 
    int i = 0, j = 0, maxLen = 0;
    unordered_map<char, bool> dict;
    const auto n = s.length();
    while (i < n && j < n) {
      // get the current character;
      const auto c = s.at(j);
      if (dict.find(c) == dict.end()) {
        // add this character into the dict;
        dict[c] = true;
        auto currentLen = dict.size();
        if (currentLen > maxLen) { maxLen = currentLen; }
        j++;
      } else {
        // remove this element to match the window -
        // keep testing the next case starting from the current length;
        dict.erase(s.at(i++));
      }
    }
    return maxLen;
  }
};
