#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    // DP:
    /**
    * Fib: fib(n) = fib(n-1) + fib(n-2)
    * e.g.:
    *             fib(5)
    *           /        \
    *       fib(4)       [fib(3)]
    *      /      \      /     \
    *  [fib(3)] fib(2) fib(2) fib(1)
    *                ...
    *  Here "fib(3)" has the overlapping calculation in a recursive solution, and -
    *  we can solve this problem by using DP, to reuse the result of "fib(3)";
    * 
    *  How to solve DP problem:
    *  1. find the exiting rules;
    *  2. find the recursive equation;
    *  3. set a 1/2/3 dimension array to save the result;
    *  4. fill out the array in a loop;
    *  5. find the result in the meanwhile and exit the loop according to the exit rules;
    */
    const auto len = s.length();
    if (len <= 1) {
      return s;
    }

    string str;
    bool dp[len][len];
    for (auto i = 0; i < len; i++) {
      for (auto j = 0; j < len; j++) {
        dp[i][j] = false;
      }
    }

    /**
     *   i 0 1
     * j x - -
     * 0 x x -
     * 1 x x x 
     */ 
    for (auto j = 0; j < len; j++) {
      /**
      * exiting rules:
      * - P(i, i) = true;
      * - P(i, i + 1) = (s[i] == s[i + 1]);
      * - "j" must be greater or equal than "i", [i, j] indicates a substring;
      * 
      * recursive equation:
      * - P(i, j) = (P(i + 1, j - 1) and s[i] == s[j]);
      */
      for (auto i = 0; i <= j; i++) {
        if (i == j) {
          dp[i][j] = true;
        } else if (i == j - 1) {
          dp[i][j] = s.at(i) == s.at(j);
        } else {
          dp[i][j] = (dp[i + 1][j - 1] && (s.at(i) == s.at(j)));
        }
        if (dp[i][j] && (j - i + 1 > str.length())) {
          str = s.substr(i, j - i + 1);
        }
      }
    }
    return str;
  }
};
