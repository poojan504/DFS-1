// we are given a matrix of image contains the value of each pixel and starting raw annd coloum 
// of the pixels
// we need to convert all the neighbouring pixels with the new color of the source pixel
// upuntil all the connected pixels are converted to the new color


// so starting from the source pixel we can think of each pixel connected to it as nodes and perform
// either BFS or DFS on each pixels and 
class Solution {
//we will also need a direction vector
vector<pair<int,int>>directions{{-1,0},{0,-1},{1,0},{0,1}};
private:
    void DFS(vector<vector<int>>& image, int sr, int sc, int color,int newColor)
    {
        //base case
        if(sr < 0 || sc < 0 || sr >=image.size() || sc >=image[0].size() || image[sr][sc] != color)
            return;
        //logic
        image[sr][sc]= newColor;
        //going in each direction
        for(auto [dr,dc] : directions)
        {
            int newr = sr + dr;
            int newc = sc + dc;
            DFS(image,newr,newc,color,newColor);
            
        }
        return;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //store the color at the given source location
        int curr_color = image[sr][sc];

        
        if(curr_color != color)
            DFS(image,sr,sc,curr_color,color);

       
        return image;
    }
};
//Time complexity is O(N)
//space complexity O(N)