class Solution {
public:
    int pivot(vector<int>& nums, int l, int r) {
        while(l < r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] < nums[r]) { //sorted part
                r = mid; //possibly my pivot
            } else {
                l = mid+1;
            }
        }
        
        return r;
    }
    
    int binarySearch(vector<int>& nums, int l, int r, int target) {
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int p = pivot(nums, 0, n-1);
        cout << p << endl;
        int idx = binarySearch(nums, 0, p-1, target);
        if(idx != -1)
            return idx;
        
        return binarySearch(nums, p, n-1, target);
    }
};