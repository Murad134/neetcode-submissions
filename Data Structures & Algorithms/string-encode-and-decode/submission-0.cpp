class Solution {
public:
    string encode(vector<string>& strs) {
        string sol;
        for (const string& s : strs) {
            sol.append(to_string(s.size()));
            sol.push_back('#');
            sol.append(s);
        }
        return sol;
    }

    vector<string> decode(string s) {
        vector<string> sol;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            sol.push_back(s.substr(i, length));
            i = j;
        }
        return sol;
    }
};