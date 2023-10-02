class Solution {
public:
    bool winnerOfGame(string colors) {
        int cA=0, cB=0;

        for(int i=1; i<colors.size()-1; i++){
            if(colors[i-1]==colors[i] && colors[i]==colors[i+1] && colors[i]=='A')
            cA++;
            else if(colors[i-1]==colors[i] && colors[i]==colors[i+1] && colors[i]=='B')
            cB++;
        }

        if(cA>cB)
        return true;

        return false;
    }
};