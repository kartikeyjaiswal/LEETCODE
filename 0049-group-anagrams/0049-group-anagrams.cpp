class Solution {
public:
    string generateString(string currentWord) {
        string ans = "";
        vector<int> freq(26, 0);
        int n = currentWord.size();
        for (int i = 0; i < n; i++) {
            freq[currentWord[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                ans += string(freq[i], i + 'a');
            }
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        map<string, vector<string>> mp;
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            string temp = generateString(strs[i]);
            mp[temp].push_back(strs[i]);
        }
        for (auto& it : mp) {
            answer.push_back(it.second);
        }
        return answer;
    }
};