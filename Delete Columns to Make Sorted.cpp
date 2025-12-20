class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        for (int columnIter = 0; columnIter < strs[0].size(); columnIter++){
            for (int wordIter = 0; wordIter < strs.size() - 1; wordIter++){
                if (strs[wordIter][columnIter] > strs[wordIter + 1][columnIter]){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
