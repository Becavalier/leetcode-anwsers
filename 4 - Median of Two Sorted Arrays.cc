
#include <vector>
#include <limits>

using namespace std;

class Solution {
 private:
  int max(const int x, const int y) { return x >= y ? x : y; }
  int min(const int x, const int y) { return x <= y ? x : y; }
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // time complexity: O(log(min(nums1, nums2)))
    int x = nums1.size();
    int y = nums2.size();
    if (x > y) {
      // here we assume nums1 is the shorter one, to reduce the TC;;
      return findMedianSortedArrays(nums2, nums1);
    }
    
    // "partitionX + partitionY = (x + y + 1) / 2";
    int start = 0, end = x;
    while (start <= end) {
      // find the center of the sequence, perform binary-seach -
      // partition[X/Y] means how many elements will be partitioned;
      int partitionX = (start + end) / 2; 
      int partitionY = (x + y + 1) / 2 - partitionX;
      
      // pay attention to the edge cases -
      // (one special case: the sizes of two vectors are all the same, --
      // and X has been partitioned completely, and Y has not any elements are included at all);
      int maxLeftX = partitionX == 0 ? numeric_limits<int>::min() : nums1[partitionX - 1];
      int minRightX = partitionX == x ? numeric_limits<int>::max() : nums1[partitionX];
      int maxLeftY = partitionY == 0 ? numeric_limits<int>::min() : nums2[partitionY - 1];
      int minRightY = partitionY == y ? numeric_limits<int>::max() : nums2[partitionY];
      
      if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
        if ((x + y) % 2 == 0) {
          // even;
          return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
        } else {
          // odd;
          return static_cast<double>(max(maxLeftX, maxLeftY));
        }
      } else if (maxLeftX > minRightY) {
        // next iteration (moving towards left);
        end = partitionX - 1;
      } else {
        // next iteration (moving towards right);
        start = partitionX + 1;
      }
    }
    return 0;
  }
};

