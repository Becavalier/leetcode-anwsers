#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    /**
     * 
     * Dict:
     * -----------------
     * | 0 | 1 | 2 | 3 | value(indices);
     * -----------------
     *   |   |   |   |
     * -----------------
     * | 6 | 2 | 3 | 7 | key(real-value);
     * -----------------
     *   ^
     *  (9) so, searching 3(having 6) from the rest of the values in the map;
     * 
     * Tip: go through from the left to the right with one iteration, -
     * using a map to accelerate the querying speed of the complementary number of the given target;
     * 
     */
    unordered_map<int, int> dict;
    vector<int> result;
    const int size = nums.size();
    for (int i = 0; i < size; i++) {
      dict[nums[i]] = i;
    }
    
    for (int j = 0; j < size; j++) {
      const int num = nums[j];
      auto search = dict.find(target - num);
      if (search != dict.end() && j != search->second) {
        result.assign({j, search->second});
      }
    }
    return result;
  }
};
