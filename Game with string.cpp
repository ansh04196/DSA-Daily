class Solution{
public:
    //Function to find the minimum value.
    int minValue(string s, int k){
        //Map to store the frequency of each character.
        map<char, int> mp;
        //Priority queue to store the frequencies in descending order.
        priority_queue<int> pq;
        
        //Iterating through the string to count the frequency of each character.
        for(int i = 0;i < s.size();i++)
            mp[s[i]]++;
        
        //Pushing the frequencies into the priority queue.
        for(auto it = mp.begin();it != mp.end();it++)
            pq.push(it->second);
        
        //Decreasing the frequencies k times to obtain the minimum value.
        while(k--){
            int x = pq.top();
            x--;
            pq.pop();
            pq.push(x);
        }
        
        //Calculating the result by squaring the remaining frequencies in the priority queue.
        int result = 0;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            result += (x*x);
        }
        
        //Returning the minimum value.
        return result;
    }
};
