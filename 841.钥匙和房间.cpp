/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
private:
    vector<bool> vis;//记录节点是否被访问
    int num;//记录访问过的节点数量
public:
    //深度搜索
    void dfs(vector<vector<int>>& rooms,const int &x){
        vis[x] = true;//将当前访问节点标志位设为true
        num++;//访问节点数+1
        for (auto &room: rooms[x])
        {//取出每把钥匙
            if (!vis[room])//若此钥匙对应的节点没有被访问过，则搜索对应节点
            {
                dfs(rooms,room);
            }
        }
        
    }
    //采用深度搜索查看从0节点出发是否可以到达所有节点
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vis.resize(n);//数组扩容
        this->num = 0;
        dfs(rooms,0);
        return num==n;//若最终访问过所有房间，则返回true
    }
};
// @lc code=end

