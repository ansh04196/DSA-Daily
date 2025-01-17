// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        bool zeroFlag = false;
        int zeroCount = 0;
        int prod = 1;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 0){
                zeroCount++;
                zeroFlag = true;
            }
            else{
                prod = prod * arr[i];
            }
        }
        vector<int>res;
        for(int i = 0 ; i < arr.size(); i++){
            if(arr[i] != 0){
                if(zeroFlag){
                    res.push_back(0);
                }
                else{
                    res.push_back(prod / arr[i]);
                }
            }
            else{
                if(zeroCount == 1){
                    res.push_back(prod);
                }
                else{
                    res.push_back(0);
                }
            }
        }
        return res;
    }
};
