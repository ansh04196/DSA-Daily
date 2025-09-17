struct MyComparator {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
        if (a.first != b.first) return a.first < b.first;  
        return a.second > b.second;  
    }
};
class FoodRatings {
private:
    unordered_map<string, int> foodRating;
    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, MyComparator>> map;
    unordered_map<string, string> cuisineToFood;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            map[cuisines[i]].push({ratings[i], foods[i]});
            cuisineToFood[foods[i]] = cuisines[i];
            foodRating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        foodRating[food] = newRating;
        map[cuisineToFood[food]].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto highest = map[cuisine].top();
        while (highest.first != foodRating[highest.second]){
            map[cuisine].pop();
            highest = map[cuisine].top();
        }
        return highest.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
