/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

*/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int len = nums.size();
        
        for(int i=0; i<len; i++)
        {
            if(nums[i] > 0 && nums[i] <= len)
            {
                int pos = nums[i]-1;
                if(nums[pos]!=nums[i])
                {
                    int temp = nums[pos];
                    nums[pos] = nums[i];
                    nums[i] = temp;
                    i--;
                }
            }
        }
        
        for(int i=0; i<len; i++)
        {
            if(nums[i] != i+1)
                return i+1;
        }
        
        return len+1;
        
    }
};