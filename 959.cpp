// 959 
// mostly implementation based question. But had to se hint first to get the gist. 
// you just have to convert the slashes to 1s. 
// EXACTLY LIKE A DISPLAY TAKES A PIXEL!

class Solution {
public:

    vector<vector<int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};

    void recur(vector<vector<int>> b, vector<vector<int>> &vis, int n, int i, int j){
        vis[i][j] = 1;
        for(int k=0; k<4; k++){
            int xs = i+dir[k][0];
            int ys = j+dir[k][1];
            if(xs >= 0 && xs <n && ys >=0 && ys<n && !vis[xs][ys] && !b[i][j]){
                recur(b,vis, n, xs, ys);
            }
        }
        return;
    }

    int countRegions(vector<vector<int>> b){
        int res = 0;
        int n = b.size();

        vector<vector<int>> vis(n, vector<int>(n, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(b[i][j] == 0 && !vis[i][j]){
                    res++;
                    recur(b, vis, n, i, j);
                }
            }
        }

        return res; 
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> b(90, vector<int>(90, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == ' '){
                    continue;
                } else if(grid[i][j] == '/'){
                    int x = 3*i;
                    int y = 3*j;
                    b[x+2][y] = 1;
                    b[x+1][y+1] = 1;
                    b[x][y+2] = 1;
                } else {
                    int x = 3*i;
                    int y = 3*j;
                    b[x][y] = 1;
                    b[x+1][y+1] = 1;
                    b[x+2][y+2] = 1;
                    // j++;
                }
            }
        }

        if(n != 30) {
            int x = 3*n;
            for(int i=0; i<=x; i++){
                b[x][i] = 1;
                b[i][x] = 1;
            }
        }

        for(int i=0; i<15; i++){
            for(int j=0; j<15; j++){
                cout<<b[i][j] << " ";
            }
            cout << "\n";
        }

        return n==30 ? countRegions(b) : countRegions(b) - 1;
    }
};

