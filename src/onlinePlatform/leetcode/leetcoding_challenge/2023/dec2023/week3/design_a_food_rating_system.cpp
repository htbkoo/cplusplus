#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <sstream>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        foodCuisines = unordered_map<string, string>();
        foodRatings = unordered_map<string, int>();
        m = unordered_map<string, map<int, set<string>>>();

        for (int i = 0; i < foods.size(); ++i) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodCuisines[food] = cuisine;
            foodRatings[food] = rating;
            m[cuisine][rating].insert(food);
        }

    }

    void changeRating(string food, int newRating) {
        string cuisine = foodCuisines[food];

        int rating = foodRatings[food];
        m[cuisine][rating].erase(food);

        if (m[cuisine][rating].size() == 0) {
            m[cuisine].erase(rating);
        }

        foodRatings[food] = newRating;
        m[cuisine][newRating].insert(food);
    }

    string highestRated(string cuisine) {
        auto last = prev(end(m[cuisine]));
        auto foods = last -> second;
        return *begin(foods);
    }

private:
    unordered_map<string, string> foodCuisines;
    unordered_map<string, int> foodRatings;
    unordered_map<string, map<int, set<string>>> m;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

int main() {
    vector<string> foods{"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines{"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings{9, 12, 8, 15, 14, 7};

    FoodRatings fr(foods, cuisines, ratings);

    cout << fr.highestRated("korean") << endl;
    cout << fr.highestRated("japanese") << endl;
    fr.changeRating("sushi", 16);
    cout << fr.highestRated("japanese") << endl;
    fr.changeRating("ramen", 16);
    cout << fr.highestRated("japanese") << endl;

    return 0;
}