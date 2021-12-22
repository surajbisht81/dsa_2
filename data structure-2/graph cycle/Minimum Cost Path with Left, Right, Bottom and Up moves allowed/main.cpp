#include <bits/stdc++.h>
using namespace std;
#define ROW 5
#define COL 5
int row[]={1, 0, -1,  0};
int col[]={0, 1,  0, -1};

struct cell
{
    int x, y, dist;
    cell(int x, int y, int dist):
        x(x), y(y), dist(dist) {}
};

bool isSafe(int x, int y)
{
    if(x<0 or x>=ROW or y<0 or y>=COL)
        return false;
    return true;
}
bool operator<(const cell& a, const cell& b)
{
    if (a.dist == b.dist)
    {
        if (a.x != b.x)
            return (a.x < b.x);
        else
            return (a.y < b.y);
    }
    return (a.dist < b.dist);
}
int MinCost(int grid[][COL])
{
    set<cell> st;
    st.insert(cell(0, 0, 0));

    int dis[ROW][COL];
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            dis[i][j]=INT_MAX;
        }
    }

    dis[0][0]=grid[0][0];

    while(!st.empty())
    {
        cell k = *(st.begin());
        st.erase(st.begin());

        for(int i=0; i<4; i++)
        {
            int x= k.x+row[i];
            int y=k.y +col[i];
            if(!isSafe(x, y))
                continue;

            if(dis[x][y]> dis[k.x][k.y]+grid[x][y])
            {
                if(dis[x][y]!=INT_MAX)
                    st.erase(st.find(cell(x, y, dis[x][y])));

                dis[x][y] = dis[k.x][k.y]+grid[x][y];
                st.insert(cell(x, y, dis[x][y]));
            }
        }
    }
    return dis[ROW-1][COL-1];
}
int main()
{
     int grid[ROW][COL] =
    {
        31, 100, 65, 12, 18,
        10, 13, 47, 157, 6,
        100, 113, 174, 11, 33,
        88, 124, 41, 20, 140,
        99, 32, 111, 41, 20
    };

    cout<<MinCost(grid);
    return 0;
}
