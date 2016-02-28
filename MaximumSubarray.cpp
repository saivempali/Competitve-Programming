class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
            
        if(nums.size()==1)
            return nums[0];
        int i;
        int max = nums[0];
        for(i=0; i<nums.size();i++)
        {
            if(nums[i] >= 0)
                break;
            else
            {
                if(max < nums[i])
                    max = nums[i];
            }
        }
        
        if(i != nums.size())
        {
            max = 0;
            int max_cur = 0;
            
            for(int i=0; i<nums.size(); i++)
            {
                max_cur = max_cur + nums[i];
                
                if(max_cur < 0)
                    max_cur = 0;
                    
                if(max < max_cur) 
                    max = max_cur;
            }
        }
        return max;
    }
};