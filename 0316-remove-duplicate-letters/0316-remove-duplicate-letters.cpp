class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
        std::vector<int> count(26, 0);
        std::vector<bool> inResult(26, false);
        std::string result = "";
        
        // Count frequencies of all characters
        for (char c : s) {
            count[c - 'a']++;
        }
        
        for (char c : s) {
            // Decrement the remaining count for the current character
            count[c - 'a']--;
            
            // If the character is already in our result, skip it
            if (inResult[c - 'a']) {
                continue;
            }
            
            // Monotonic Stack condition:
            // Pop the last character from the result if:
            // 1. The result is not empty
            // 2. The last character is lexicographically greater than the current character 'c'
            // 3. The last character appears again later in the string (count > 0)
            while (!result.empty() && result.back() > c && count[result.back() - 'a'] > 0) {
                inResult[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            // Append the current character and mark it as used
            result.push_back(c);
            inResult[c - 'a'] = true;
        }
        
        return result;
    }
};
