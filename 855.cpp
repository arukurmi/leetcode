// 855: Spiral Matrix III

// Good problem. To learn: how to just ignore somethings and get the right by putting conditions.
// Had to see the solution to get the approach but coded on my own.

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int count = 1;
        vector<vector<int>> gridSet;
        int x = rStart;
        int y = cStart;
        int i = 3;
        int width = 1;
        gridSet.push_back({x,y});

        while(count < rows*cols){
            for(int k=0; k<4; k++){
                i = (i+1) % 4;
                for(int k = 0; k < width; k++){
                    x = x+dir[i][0];
                    y = y+dir[i][1];

                    if(x >= 0 && x < rows && y >= 0 && y < cols){
                        gridSet.push_back({x, y});
                        count++;
                    }
                }
                if(i%2 != 0) width++;
            }
        }

        return gridSet;
    }
};