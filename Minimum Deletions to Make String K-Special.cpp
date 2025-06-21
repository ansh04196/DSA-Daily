class Solution {
public:
    int minimumDeletions(string word, int k) {
        int deleted = 0, res = word.size();
        vector<int> freq(26, 0);
        for(auto c : word) freq[c - 'a']++;             
        sort(freq.begin(), freq.end());              
        for(int i = 0; i < freq.size(); i++){         
            int curr = deleted, minFreq = freq[i];    
            for(int j = freq.size() - 1; j > i; j--){  
                if (freq[j] - minFreq <= k) break;    
                curr += freq[j] - minFreq - k;
            }
            res = min(res, curr);
            deleted += freq[i];     
        }
        return res;
    }
};
