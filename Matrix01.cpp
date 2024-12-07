// starting from each non zero value mat we can perform DFS or BFS
// so if we perform DFS we iterate each direction untill we find the zero but thing to understand is
// we need to keep the track of the counter in the local scope so at any level we find the 0 we get the
// value of the level


class Solution {
    vector<pair<int,int>>dirs{{0,-1},{0,1},{-1,0},{1,0}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>tracker;
        int dist = 1;
        //iterating over the each value in mat
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j =0; j < mat[0].size(); j++)
            {
                if(mat[i][j] == 0)
                    tracker.push({i,j});
                else
                    mat[i][j] = -1;
            }
        }

        while(!tracker.empty())
        {
            int size = tracker.size();
            
            for(int i = 0; i < size; i++)
            {
                int row = tracker.front().first;
                int col = tracker.front().second;
                tracker.pop();

                for(auto [dr,dc]: dirs)
                {
                    int newr = row + dr;
                    int newc = col + dc;

                    if(newr >= 0 && newc >= 0 && newr < mat.size() && newc < mat[0].size())
                    {
                        if(mat[newr][newc]== -1)
                        {
                            mat[newr][newc] = dist;
                            tracker.push({newr,newc});
                        }
                    }
                }
            }
            dist++;                        
        }

        return mat;

    }
};

//Time complexity O(mxn)
//space complexity O(mxn)