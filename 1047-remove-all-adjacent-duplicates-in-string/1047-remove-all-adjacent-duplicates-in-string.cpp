class Solution {
public:
    string removeDuplicates(string s) {
        int i=1;
        string k;
        k.push_back(s[0]);
        while(i<s.length())
        {
            if(!k.empty()&&s.length())
            {
                if(k.back()==s[i])
                {
                    k.pop_back();
                }
                else
                {
                    k.push_back(s[i]);
                }
            }
            else
                k.push_back(s[i]);
            i++;
        }
        return k;
        
    }
};