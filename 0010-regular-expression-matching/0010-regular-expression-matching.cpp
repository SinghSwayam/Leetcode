class Solution {
public:
    bool solve(string &s, string &p, int i, int j) {
        if (j == p.size())
            return i == s.size();

        bool firstMatch = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.size() && p[j + 1] == '*') {
            return solve(s, p, i, j + 2) || (firstMatch && solve(s, p, i + 1, j));
        }

        return firstMatch && solve(s, p, i + 1, j + 1);
    }

    bool isMatch(string s, string p) {
        return solve(s, p, 0, 0);
    }
};