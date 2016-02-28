class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.length() == 0 || s.length() == 1)
            return s.length();
            
        int maxlen = 1;
        int start = 0;
        map<char,int> m;
        int curlen = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(m.find(s[i]) == m.end())
            {
                curlen++;
                if(curlen > maxlen)
                    maxlen = curlen;
                m.insert(pair<char,int>(s[i],i));
            }
            
            else
            {
                // take the example of abc and extrapolate to abca and abcabc
                // this else part checks for the index where the repeating char first occurred and 
                // calculates the curlen as the length from the repeating char+1 to the current position
                // Then it updates the maxlen and removes the unique continuous non-repeating chars from map
                // so that it can start fresh from current location
                int indexRepeat = m.find(s[i])->second;
            
                curlen = i - indexRepeat;
                
                if(curlen > maxlen)
                    maxlen = curlen;
        
               for(int j=start; j<=indexRepeat; j++)                    
                    m.erase(s[j]);
                    
                start = indexRepeat+1;
               
                 m.insert(pair<char,int>(s[i],i));
            }
        }
        
        return maxlen;
    }
};