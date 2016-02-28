/*

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

*/


class Solution {
public:
    void reverseWords(string &s) {
        string out = NULL ;
        
        stack<string> mystack;
        
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
            {
                if(i == 0){}
                
                else if(s[i-1]==' '){}
                
                else{
                    mystack.push(out);
                    out = "";
                }
            }
            
            else if(s[i] == '\0')
            {
                if(s[i-1] == ' '){}
                
                else
                {
                    mystack.push(out);
                    out = "";
                }
            }
            
            else
            {
                out = out + s[i];
            }
        }
        
        out = "";
        while(!mystack.empty())
        {
            out = out+mystack.top()+" ";
            mystack.pop();
        }
        
        cout<<out;
    }
};