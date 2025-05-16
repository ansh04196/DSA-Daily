
#define p pair<int, pair<int, int>>

class Solution{
    public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        // Create a min heap to store element, array no & idx
        int k = arr.size(), n = arr[0].size();
        priority_queue<p, vector<p>, greater<p>> pq;
        int mn = INT_MAX, mx = INT_MIN, range = INT_MAX;
        int l=0, h=0;
        for(int i=0; i<k; i++){
            pq.push({arr[i][0], {i, 0}});
            mn = min(arr[i][0], mn);
            mx = max(arr[i][0], mx);
        }
        while(!pq.empty()){
            p temp = pq.top();
            pq.pop();
            int mini = temp.first;
            if(range > mx-mini){
                mn = mini;
                l = mn;
                h = mx;
                range = mx - mn;
            }
            int i = temp.second.first, j = temp.second.second;
            if(j == n-1) 
                break;
            pq.push({arr[i][j+1], {i, j+1}});
            if(mx < arr[i][j+1])
                mx = arr[i][j+1];
        }
        return {l, h};
    }
};


//GFG POTD solution for 16 May
