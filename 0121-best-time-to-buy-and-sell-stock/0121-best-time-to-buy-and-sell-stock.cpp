class Solution {
public:
    int maxProfit(vector<int>& price) {
        
        int pro=0;
        int mine = price[0];
        
        for(int i=1;i<price.size();i++){
            
           mine =min (price[i] , mine);
            pro = max(pro,(price[i] - mine));
        }
        return pro;
    }
};