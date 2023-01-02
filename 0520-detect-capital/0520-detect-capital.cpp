class Solution {
public:
bool detectCapitalUse(string word) {

    int cntSmall=0, cntCap=0;
    for(int i=0; i<word.size(); i++){
       if(isupper(word[i])){
           cntCap++;
       }
       else{
           cntSmall++;
       }
    }

    if(cntCap==0 or cntSmall==0) return true;
    if(cntCap==1){
        if(isupper(word[0])){
            return true;
        }
        
    }
    return false;
  }
};