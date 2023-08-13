
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    
public:
    //C++20: int longestSubarray(span<const int> input) const ...
    int longestSubarray(const vector<int>& input) const {
        int tail = 0;
        int head = 0;
        int numberOfZeros = 0;
        int longestSubarray = 0;
        int indexPreviousZero = -1;

        while (head < input.size()) {
            if (input[head] == 0) {
                tail = (++numberOfZeros == 2) ? (indexPreviousZero + 1) : tail;
                numberOfZeros = 1;
                indexPreviousZero = head;
            }
            longestSubarray = max(longestSubarray, head - tail);
            ++head;
        }

        return longestSubarray;
    }
};
