#include <algorithm>
#include <vector>
#include <map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> _map;
        for (const string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            _map[key].emplace_back(str);
        }
        vector<vector<string>> res;
        for (auto& item : _map) {
            res.emplace_back(item.second);
        }
        return res;
    }
};