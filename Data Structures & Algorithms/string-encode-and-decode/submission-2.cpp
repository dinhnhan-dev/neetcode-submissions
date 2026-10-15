class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(const string& s : strs) {
            res.append(to_string(s.size()));
            res.push_back('#');
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while(s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = length + i;
            res.push_back(s.substr(i, lenght));
            i = j;
        }
        return res;
    }
};
