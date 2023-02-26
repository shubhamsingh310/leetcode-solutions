class Solution {
public:
    bool isValid(string s) {
    stack<char>st;

    for(int i=0;i< s.length();++i){

        char ch = s[i];

        //if operning bracket -> stack push()
        // if closing bracket -> stacktop check and pop
        if (ch == '{' || ch == '[' || ch == '(') {
          st.push(ch);
        }
        else{
            
            if (!st.empty()) {
              char top = st.top();
              if ((ch == '}' && top == '{') 
              || (ch == ']' && top == '[') ||
                  (ch == ')' && top == '(')) {
                st.pop();
              } 
              else {
                return false;
              }

            } 
            else {
              return false;
            }
        }
    }
    if(st.empty())
    return true;

   else
    return false;
        
    }
};



