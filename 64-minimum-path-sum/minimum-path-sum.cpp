class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>>dist(n,vector<int>(m,1e9));

        pq.push({grid[0][0],{0,0}});
        dist[0][0]=grid[0][0];
        int rows[2]={1,0};
        int cols[2]={0,1};
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int r=it.second.first;
            int c=it.second.second;
            int sum=it.first;
            for(int i=0;i<2;i++)
            {
                int nrow=r+rows[i];
                int ncol=c+cols[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && dist[nrow][ncol]>sum+grid[nrow][ncol])
                {
                    pq.push({sum+grid[nrow][ncol],{nrow,ncol}});
                    dist[nrow][ncol]=sum+grid[nrow][ncol];
                }
            }
        }
        return dist[n-1][m-1];

    }
};