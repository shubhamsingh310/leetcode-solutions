class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int size = s.size();
        
        
        for(int i=0; i<size; i++)
        {
            if(s[i] == 'I')
            {
                sum +=1;
            }
            else if(s[i] == 'V')
            {
                if(i>0 && s[i-1] == 'I')
                {
                    sum = sum +5 -2;
                }
                else
                {
                    sum = sum+5;
                }
            }
            else if(s[i] == 'X')
            {
                if(i>0 && s[i-1] == 'I')
                {
                    sum = sum +10 -2;
                }
                else
                {
                    sum = sum+10;
                }
            }
            else if(s[i] == 'L')
            {
                if(i>0 && s[i-1] == 'X')
                {
                    sum = sum +50-20;
                }
                else
                {
                    sum = sum+50;
                }
            }
            else if(s[i] == 'C')
            {
                if(i>0 && s[i-1] == 'X')
                {
                    sum = sum +100-20;
                }
                else
                {
                    sum = sum+100;
                }
            }
            else if(s[i] == 'D')
            {
                if(i>0 && s[i-1] == 'C')
                {
                    sum = sum +500-200;
                }
                else
                {
                    sum = sum+500;
                }
            }
            else if(s[i] == 'M')
            {
                if(i>0 && s[i-1] == 'C')
                {
                    sum = sum +1000-200;
                }
                else
                {
                    sum = sum+1000;
                }
            }
            
        }
       
        return sum;
    }
};