#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    vector<int> seq;   
    while (true) {
      seq.push_back(x % 10);
      if (x <= 9 && x >= -9) { break; }
      x /= 10;
    }
    long y = 0, base = 1;
    for (auto i = seq.rbegin(); i != seq.rend(); i++) {  
      y += *i * base;
      base *= 10;
    }
    if (y < numeric_limits<int>::min() || y > numeric_limits<int>::max()) {
      return 0;
    } else {
      return y;
    }
  }
};
