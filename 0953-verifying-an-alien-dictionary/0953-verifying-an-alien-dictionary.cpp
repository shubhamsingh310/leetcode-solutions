class Solution {
public:
    bool isAlienSorted(vector<string>& words, string ord) {
      
        int map[26];
            
        for (int i = 0; i < 26; i++)
            map[ord[i] - 'a'] = i;
            
        for (string &w : words)
            for (char &c : w)
                c = map[c - 'a'];
        return is_sorted(words.begin(), words.end());
    }
        
    
};