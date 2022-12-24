class Solution {
public:
    
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if (digits[n-1]<9){
            digits[n-1]++;
            return digits;
        }
        
        digits[n-1]=0;
        int carry =1;
        for (int i= n-2; i>=0; i--){
            digits[i]+= carry;
            if (digits[i]<10)return digits;
            else {
                digits[i]= digits[i]%10;
            }
        }
        
        vector<int> ans;
        ans.push_back(1);
        for (auto val: digits)ans.push_back(val);
        return ans;
    }
};