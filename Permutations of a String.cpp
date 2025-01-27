class Solution {
  public:
  // Apprach 1: Using next_permutation
  vector<string> Solve(string &s){
      vector<string>ans;
      sort(s.begin(),s.end());
      do{
          ans.push_back(s);
      }while(next_permutation(s.begin(),s.end()));
      return ans;
  }
    vector<string> findPermutation(string &s) {
        // Code here there
        return Solve(s);
    }
};


//GFG POTD solution for 28 January
