#include<ranges>
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> res(numberOfUsers);
        vector<int> online_t(numberOfUsers);
        ranges::sort(events, {}, [](auto& e) { return pair(stoi(e[1]), e[0][2]); });
        for (auto& e : events) {
            int cur_t = stoi(e[1]);
            string& mention = e[2];
            if (e[0][0] == 'O') online_t[stoi(mention)] = cur_t + 60;
            else if (mention[0] == 'A') {
                for (int& v : res) v++;
            } 
            else if (mention[0] == 'H') {
                for (int i = 0; i < numberOfUsers; i++) {
                    if (online_t[i] <= cur_t) res[i]++;
                }
            } 
            else {
                for (const auto& part : mention | ranges::views::split(' ')) {
                    string s(part.begin() + 2, part.end());
                    res[stoi(s)]++;
                }
            }
        }
        return res;
    }
};
