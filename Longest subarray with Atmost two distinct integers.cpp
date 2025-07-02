class Solution {
  public:
    int totalElements(vector<int>& arr) {

    map<int, int> mp;  
    int i = 0, j = 0, n = arr.size();
    int size = 0;

    while (j < n) {

        mp[arr[j]]++;

        // If we have more than 2 distinct elements, 
        // shrink the window from the left
        while (mp.size() > 2) {

            mp[arr[i]]--;

            // If a number’s count becomes 0
            // remove it completely from the map
            if (mp[arr[i]] == 0)
                mp.erase(arr[i]);
            
            // move the left boundary forward
            i++;  
        }

        // Window is valid (has at most 2 distinct numbers)
        // update the best size
        size = max(size, j - i + 1);
        
        // expand the window to the right
        j++;  
    }

    return size;
    }
};
