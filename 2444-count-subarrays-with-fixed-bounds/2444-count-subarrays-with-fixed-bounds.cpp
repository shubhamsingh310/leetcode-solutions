class Solution {
public:
    long long countSubarrays(vector<int>& nums, int min_value, int max_value) {
        long result = 0;
        bool min_found = false, max_found = false;
        int start_index = 0, min_start_index = 0, max_start_index = 0;
        
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if(num < min_value || num > max_value){
                min_found = false;
                max_found = false;
                start_index = i + 1;
            }
            
            if(num == min_value){
                min_found = true;
                min_start_index = i;
            }
            if(num == max_value){
                max_found = true;
                max_start_index = i;
            }
            
            if(min_found && max_found){
                result += (min(min_start_index,max_start_index) - start_index + 1);
            }
        }
        return result;
    }
};
