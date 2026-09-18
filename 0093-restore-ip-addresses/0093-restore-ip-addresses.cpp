class Solution {
public:
    void solve(string& s, int index, int parts, string current, vector<string>& ans) {
        if (parts == 4) {
            if (index == s.size()) {
                current.pop_back();
                ans.push_back(current);
            }
            return;
        }

        for (int i = index; i < s.size() && i < index + 3; i++) {
            if (s[index] == '0' && i > index) break;

            int num = stoi(s.substr(index, i - index + 1));

            if (num > 255) break;

            solve(s, i + 1, parts + 1, current + s.substr(index, i - index + 1) + ".", ans);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if (s.size() < 4 || s.size() > 12)
            return ans;

        solve(s, 0, 0, "", ans);
        return ans;
    }
};