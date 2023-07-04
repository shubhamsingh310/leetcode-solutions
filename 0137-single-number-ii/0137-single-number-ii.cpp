class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
       
        if (nums.size() % 3 != 0) {
            while (nums.size() % 3 != 0) {
                nums.push_back(0);
            }
        }
        
      
        for (int i = 0; i < nums.size() - 2; i = i + 3) {
            
            if (nums[i] != nums[i + 2]) {
                return nums[i];
            }
        }
        
       
        return 0;
    }
};

