class Solution {
public:
    string convert(string s, int rows) {

    if(rows==1)
        return s;
    
    int y=0;
    bool flag= true;
    string sArray[rows];
    for(int i=0;i<rows;i++)
        sArray[i]="";
    
    for(int i=0;i<s.length();i++){
        
        sArray[y]+=s[i];
        
        if(y==0){
            flag=true;
        }
        if(y==rows-1){
            flag=false;
        }
        
        if(flag==true){
            y++;
        }else{
            y--;
        }
        
    }

    string ret="";
    
    for(int i=0;i<rows;i++){
        ret+=sArray[i];
    }
    
      return ret;
   }
};