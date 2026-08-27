class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";

        for (string s : strs) {
            ans += to_string(s.size()) + "#" + s;
        }

        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            // Find '#'
            while (s[j] != '#') j++;

            int len = stoi(s.substr(i, j - i));
            j++; // move past '#'

            ans.push_back(s.substr(j, len));

            i = j + len;
        }

        return ans;
    }
};
