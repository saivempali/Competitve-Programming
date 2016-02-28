class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size()==0)
            return "";
            
        if(strs.size()==1)
            return strs[0];
        
        if(strs[0].size()==0)    
            return "";
        
        int min_size = strs[0].size();
        
        for(int i=1; i<strs.size();i++)
        {
            if(strs[i].size()==0)
                return "";
                
            if(min_size > strs[i].size())
                min_size = strs[i].size();
        }
        
        cout<<min_size;
        int prefix;
        for( prefix = 0; prefix < min_size; prefix++)
        {
            char ch = strs[0].at(prefix);
            cout<<ch;
            for(int i=1; i<strs.size();i++)
            {
                cout<<"hi";
                if(strs[i].at(prefix) != ch)
                {
                    return strs[i].substr(0,prefix);
                }
            }
        }
        
        if(prefix > 0)
            return strs[0].substr(0,prefix);
        return "";
       
    }
};