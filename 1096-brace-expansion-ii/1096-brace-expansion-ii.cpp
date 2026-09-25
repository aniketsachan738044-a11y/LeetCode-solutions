class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> result = parseUnion(expression, i);
        return vector<string>(result.begin(), result.end());
    }

private:
    // Parses a comma-separated list of concatenation terms, returns their union.
    set<string> parseUnion(const string &s, int &i) {
        set<string> result;
        while (true) {
            set<string> term = parseConcat(s, i);
            result.insert(term.begin(), term.end());
            if (i < (int)s.size() && s[i] == ',') {
                i++; // skip comma, parse next term
            } else {
                break;
            }
        }
        return result;
    }

    // Parses a sequence of concatenated factors (until ',' or '}' or end of string).
    set<string> parseConcat(const string &s, int &i) {
        vector<set<string>> factors;
        while (i < (int)s.size() && s[i] != ',' && s[i] != '}') {
            factors.push_back(parseFactor(s, i));
        }

        set<string> result;
        result.insert(""); // identity for concatenation

        for (auto &factor : factors) {
            set<string> newResult;
            for (const string &a : result) {
                for (const string &b : factor) {
                    newResult.insert(a + b);
                }
            }
            result = newResult;
        }
        return result;
    }

    // Parses a single factor: either a {..} group or a run of plain letters.
    set<string> parseFactor(const string &s, int &i) {
        if (s[i] == '{') {
            i++; // skip '{'
            set<string> r = parseUnion(s, i);
            i++; // skip '}'
            return r;
        } else {
            string letters;
            while (i < (int)s.size() && islower(s[i])) {
                letters += s[i];
                i++;
            }
            return {letters};
        }
    }
};