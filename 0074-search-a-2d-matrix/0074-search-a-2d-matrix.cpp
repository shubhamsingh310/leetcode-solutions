class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
/*      finding row and col size      */
        int row = matrix.size(); //3
        int col = matrix[0].size(); //4
        
        
/*      init start and end      */        
        int start = 0; //0
        int end = row*col - 1; //11
        
/*      finding mid index      */         
        int mid = start + (end-start) / 2; // 6 for first example
        
        while(start<=end)
        {
            
/*      mid index we find was in linear form and we have to find where mid is in row and col      

to find mid index in row = mid / col i.e 6/4 = 1
to find mid index in col = mid % col i.e 6%4 = 2

matrix[1][2] = index 6 

*/          int matrixIndex = matrix[mid / col][mid % col];
            
            if(matrixIndex == target){ return 1; }
            
            if(matrixIndex < target)
            {
                start = mid + 1;
            }else if(matrixIndex > target)
            {
                end = mid - 1;
            }
            // update mid
            mid = start + (end-start) / 2;
        }
        return 0;
    }
};