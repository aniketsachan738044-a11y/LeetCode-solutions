class Solution {
public:
    std::string smallestSubsequence(std::string s) {
        std::vector<int> count(26, 0);
        std::vector<bool> visited(26, false);
        std::string result = ""; // Using string directly as our stack

        // Step 1: Count occurrences of each character
        for (char c : s) {
            count[c - 'a']++;
        }

        // Step 2: Iterate through the string to build the result
        for (char c : s) {
            // Decrement the remaining count for the current character
            count[c - 'a']--;

            // If the character is already in our result, skip it
            if (visited[c - 'a']) {
                continue;
            }

            // Maintain the monotonic property of the stack
            // Pop the last character if it is larger than current character
            // AND it appears again later in the string
            while (!result.empty() && result.back() > c && count[result.back() - 'a'] > 0) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }

            // Push current character to stack and mark as visited
            result.push_back(c);
            visited[c - 'a'] = true;
        }

        return result;
    }
};
