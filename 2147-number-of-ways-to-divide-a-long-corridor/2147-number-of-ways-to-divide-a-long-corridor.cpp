class Solution {
public:
    int numberOfWays(string corridor) {
    int M = 1e9 + 7;
    int n = corridor.size();  
    vector<int>pos_seats;
        
    for(int i=0; i<n; i++){
        if(corridor[i]=='S')
            pos_seats.push_back(i);
    }
    
    if(pos_seats.size() % 2 != 0 || pos_seats.size() == 0)
        return 0;
    
        
    long long result = 1;
    
    int end_idx_prev = pos_seats[1];
        
    for(int i = 2; i < pos_seats.size(); i+=2){
        int len = pos_seats[i] - end_idx_prev;
        
        result = (result * len) % M; 
        end_idx_prev = pos_seats[i+1];
     }
        
       return result; 
    }
};