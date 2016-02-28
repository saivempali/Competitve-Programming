class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        if(nums.size()==0)  
            return 0;
        
        vector<int> v;
        for(int i=0; i<nums.size();i++)
            v.push_back(1);
            
        for(int i=1; i < nums.size(); i++)
        {
            
            for(int j=0; j<i;j++)
            {
                if(nums[j] < nums[i])
                {
                    if(v[i] < v[j]+1)
                        v[i] = v[j]+1;
                }
            }
        }
        
        int len = v[0];
        for(int i=1; i<v.size();i++)
        {
            if(len < v[i])
                len = v[i];
        }
        
        return len;
    }
};