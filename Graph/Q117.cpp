//flood fill algo
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& img, int x, 
         int y, int oldColor, int newColor) {
    
    if (x < 0 || x >= img.size() || 
        y < 0 || y >= img[0].size() || img[x][y] != oldColor) {
              return; 
    }

    // Update the color of the current pixel
    img[x][y] = newColor;

    // Recursively visit all 4 connected neighbors
    dfs(img, x + 1, y, oldColor, newColor); 
    dfs(img, x - 1, y, oldColor, newColor); 
    dfs(img, x, y + 1, oldColor, newColor); 
    dfs(img, x, y - 1, oldColor, newColor); 
}

vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, 
    int sc, int newColor) {

    // If the starting pixel already has the new color,
    // no changes are needed
    if (img[sr][sc] == newColor) {
        return img;
    }

    // Call DFS to start filling from the source pixel
     // Store original color
    int oldColor = img[sr][sc];
    dfs(img, sr, sc, oldColor, newColor);

    return img;
}

int main() {
    vector<vector<int>> img = {
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 1}
    };

    int sr = 1, sc = 2;

    int newColor = 2;        

    vector<vector<int>> result = floodFill(img, sr, sc, newColor);

    for (auto& row : result) {
        for (auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << " ";
    }
    return 0;
}
