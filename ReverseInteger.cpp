class Solution {
public:
    int reverse(int x) {
        
        int neg = 0;
        
        if(x < 0)
            neg = 1;
        
        x = abs(x);
        string s = to_string(x);
        
        int last = s.length()-1;
        
        for(int i=0; i<s.length()/2; i++)
        {
            char ch = s[i];
            s[i] = s[last];
            s[last] = ch;
            last--;
        }
        
        size_t sz;
        long int r = stol(s,&sz);
        
        if(r > INT_MAX)
            return 0;
            
        int result = stoi(s,&sz);
        
        if(neg == 1)
            result *= -1;
            
        return result;
    }
};