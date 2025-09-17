class FoodRatings {
public:
    unordered_map<string,set<pair<int,string>>> cuisine_rating;
    unordered_map<string,int> food_rating;
    unordered_map<string,string> food_cuisines; 
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            food_rating.insert({foods[i],ratings[i]});
            food_cuisines.insert({foods[i],cuisines[i]});
            cuisine_rating[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine=food_cuisines[food];
        int old_rating=food_rating[food];
        cuisine_rating[cuisine].erase({-old_rating,food});
        cuisine_rating[cuisine].insert({-newRating,food});
        food_rating[food]=newRating;
    }

    string highestRated(string cuisine) {
        return cuisine_rating[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */