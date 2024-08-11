// 1568


class Solution {
public:

    void dfs(vector<vector<int>>& vis, int i, int j, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || !grid[i][j]) return;
        vis[i][j] = 1;
        vector<vector<int>> nextCord = {{i+1, j}, {i, j+1}, {i-1, j}, {i, j-1}};
        for(int k=0; k<4; k++){
            dfs(vis, nextCord[k][0], nextCord[k][1], grid);
        }
        return;
    }

    int minDays(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<vector<int>> lands;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]){
                    dfs(vis, i, j, grid);
                    count++;
                }
            }
        }

        if(count!=1) return 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]){
                    lands.push_back({i, j});
                    vis[i][j] = 0;
                }
            }
        }
        for(int a=0; a<lands.size(); a++){
            int k = lands[a][0];
            int c = lands[a][1];
            count = 0;
            grid[k][c] = 0;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!vis[i][j] && grid[i][j]){
                        dfs(vis, i, j, grid);
                        count++;
                    }
                }
            }
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    vis[i][j] = 0;
                }
            }
            grid[k][c] = 1;
            if(count != 1) return 1;
        }

        return 2;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();