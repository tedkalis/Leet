class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0;
        }
        int maxLength = 1; //max length to return
        int currLength = 1; //keeps track of current substring
        unordered_set<char> usedChars; //set containing used characters in substring
        int subStart = 0;
        int subEnd = 1; //range of current substring is subStart <= inside < subEnd
        usedChars.insert(s[subStart]); //insert first char into set, cant be a repeat
        while(subEnd < s.size()){ //cant expand past size
            //attempt to expand window
            if(usedChars.find(s[subEnd]) == usedChars.end()){ //can expand
                usedChars.insert(s[subEnd++]);
                if(++currLength > maxLength){
                    maxLength = currLength;
                }
            }
            else{
            //unable to expand, slide start over
                usedChars.erase(s[subStart++]);
                currLength--;
            }
        }
        return maxLength;
    }
};