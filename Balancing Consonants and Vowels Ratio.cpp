class Solution {
  public:
  bool isVowel(char c) {
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

    int countBalanced(vector<string>& arr) {
       unordered_map<int, int> mp;
       mp[0]=1;
       int preDiff = 0;
       int result = 0;
       for(auto it : arr){
           int vowels = 0, consonants = 0;
           for(auto i : it){
               if(isVowel(i)) vowels++;
               else consonants++;
           }
           int diff =  vowels-consonants;
           preDiff += diff;
           if(mp.count(preDiff)) result += mp[preDiff];
           mp[preDiff]++;
       }
       return result;
    }
};
//GFG POTD solution for 01 August
