class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());

        queue<int> q;                 // positions 0..n-1
        for (int i = 0; i < n; i++) q.push(i);

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int idx = q.front();      // this position gets the next smallest card
            q.pop();
            ans[idx] = deck[i];

            if (!q.empty()) {         // move next position to the back
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};