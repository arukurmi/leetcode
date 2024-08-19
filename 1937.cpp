// 1937: Maximum Number of Points with Cost


class Solution {
public:
    long long maxPoints(vector<vector<int>>& a) {
        long long res = 0;
        long long n = a.size();
        long long m = a[0].size();
        vector<vector<long long>> newa(n, vector<long long>(m, 0));

        for(long long i=0; i<n; i++){
            for(long long j=0; j<m; j++){
                newa[i][j] = (long long) a[i][j];
            }
        }
        for(long long i=n-2; i>=0; i--){
            for(long long j=0; j< m; j++){
                long long curr = newa[i][j];
                long long tempSum = 0;
                for(long long k=0; k<m; k++){
                    tempSum = max(tempSum, newa[i+1][k] + curr - abs(k-j));
                }
                newa[i][j] = tempSum;
                // cout<<newa[i][i]<<" ";
            }
            // cout<<"\n";
        }

        for(long long j=0; j<m; j++){
            res = max(newa[0][j], res);
        }

        return res;
    }
};