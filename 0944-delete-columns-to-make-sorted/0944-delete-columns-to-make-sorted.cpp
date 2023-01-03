class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int delete_count=0;
        int rows = strs.size();
        int cols = strs[0].size();
        
        for(int j=0; j<cols; j++)
        {
            for(int i=0; i<rows-1; i++)
            {
                if(strs[i][j]>strs[i+1][j])
                {
                    delete_count++;
                    break;
                }
            }
        }
        return delete_count;
    }
};