class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        sort(nums.begin(), nums.end());
        
        for( i=0; i<nums.size(); i++)
        {  
           if(i!=nums[i])
           break;
        }

        return i;
    }
};