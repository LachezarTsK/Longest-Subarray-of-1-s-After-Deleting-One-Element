
using System;

public class Solution
{
    public int LongestSubarray(int[] nums)
    {
        int tail = 0;
        int head = 0;
        int numberOfZeros = 0;
        int longestSubarray = 0;
        int indexPreviousZero = -1;

        while (head < nums.Length)
        {
            if (nums[head] == 0)
            {
                tail = (++numberOfZeros == 2) ? (indexPreviousZero + 1) : tail;
                numberOfZeros = 1;
                indexPreviousZero = head;
            }

            longestSubarray = Math.Max(longestSubarray, head - tail);
            ++head;
        }

        return longestSubarray;
    }
}
