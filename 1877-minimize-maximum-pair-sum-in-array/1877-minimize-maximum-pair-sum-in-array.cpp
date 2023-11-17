class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        int ans = INT_MIN;
        int j=nums.size()-1;
        for(int i=0; i<nums.size();i++){
            temp.push_back(nums[i]+nums[j]);    
            ans = max(ans, (nums[i]+nums[j]));
            j--;
        }
        
        return ans;
       
    }
};