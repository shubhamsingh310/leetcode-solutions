class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int c=0,f=0;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]!=' ')
        {
         c++;
         f=1;
        }
        else if(f==1)
        break;

    }
        return c;
    }
};