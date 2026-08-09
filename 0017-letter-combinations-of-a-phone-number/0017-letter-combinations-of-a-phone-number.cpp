class Solution {
private:
    void solve(string digits, string output, int index, vector<string>& ans, string mapping[]) {
        // Base case: if the index reaches the end of the digits string
        if (index >= digits.length()) {
            ans.push_back(output);
            return;
        }
        
        // Convert the current character to an integer index
        int number = digits[index] - '0';
        string value = mapping[number];
        
        // Loop through all characters mapped to the current digit
        for (int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);
            solve(digits, output, index + 1, ans, mapping);
            output.pop_back(); // Backtrack
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        if (digits.length() == 0) {
            return ans;
        }
        
        string output = "";
        int index = 0;
        
        string mapping[10] = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};