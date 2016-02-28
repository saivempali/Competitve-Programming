class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;
            
        map<int,int> m;
        int nlen = 0;
        for(int i=0; i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())
            {
                m.insert(pair<int,int>(nums[i],1));
                nlen++;
            }
            
        }
        
        map<int,int>::iterator it;
        vector<int> v;
        for(it = m.begin(); it != m.end(); it++)
        {
            v.push_back(it->first);
        }
        nums = v;
        return nlen;
    }
};