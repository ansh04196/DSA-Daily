class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
          unordered_map<char, int> m;
        for(auto i:s1) m[i]++;
        for(auto i:s2) m[i]--;
        for(auto i:m) if(i.second!=0) return false;
        return true;
    }
};
