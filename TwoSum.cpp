class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     
     if(nums.size() == 0)
        return nums;
     vector<int> result(2);    
     
     map<int,int> m;
     for(int i = 0;i<nums.size();i++)
     {
         m[nums[i]] = i+1;
     }
     
     int remaining = 0,j=0;
     while(j<nums.size())
     {
         remaining = target - nums[j];
         result[0] = j+1;
         if(m.find(remaining)!=m.end())
         {
             if(result[0]!=m[remaining])
             {
                result[1] = m[remaining];
                break;
             }
         }
         j++;
     }
     return result;
    }
};
