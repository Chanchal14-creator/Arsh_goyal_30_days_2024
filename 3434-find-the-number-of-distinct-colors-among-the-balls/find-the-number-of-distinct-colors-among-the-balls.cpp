class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColors; // Map to store the color of each ball
        unordered_map<int, int> colorCount; // Map to count occurrences of each color
        unordered_set<int> distinctColors;  // Set to store distinct colors
       vector<int> result;

    for (const auto& query : queries) {
        int ball = query[0];
        int color = query[1];

        // Check if the ball already has a color
        if (ballColors.count(ball) > 0) {
            int oldColor = ballColors[ball];
            // Decrease the count of the old color
            colorCount[oldColor]--;
            if (colorCount[oldColor] == 0) {
                distinctColors.erase(oldColor);
            }
        }

        // Assign the new color to the ball
        ballColors[ball] = color;
        // Increase the count of the new color
        colorCount[color]++;
        distinctColors.insert(color);

        // Record the current number of distinct colors
        result.push_back(distinctColors.size());
    }

    return result;
    }
};