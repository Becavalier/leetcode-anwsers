#include <string>
#include <cmath>

using namespace std;

/**
 * Just find the regular pattern, -
 * and solve this problem by math equation;
 */
class Solution {
public:
  #define INSPECT(s, pos) \
    if (pos < s.length()) { \
        result.append(1, s.at(pos)); \
    }
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    } else {
      string result;
      const int blockNum = floor(s.length() / 1.0 * (2 * (numRows - 1)));
      for (auto i = 1; i <= numRows; i++) {
        for (auto j = 1; j <= blockNum; j++) {
          const int offset = (2 * (numRows - 1)) * (j - 1);
          if (i == 1) {
            INSPECT(s, offset)
          } else if (i != numRows) {
            INSPECT(s, offset + (i - 1))
            INSPECT(s, offset + (i - 1) + (2 + (numRows - i - 1) * 2))
          } else {
            INSPECT(s, offset + (numRows - 1))
          }                
        }
      }
      return result;
    }
  }
};
