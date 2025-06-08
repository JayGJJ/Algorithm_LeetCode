/*
 * @lc app=leetcode.cn id=1146 lang=cpp
 *
 * [1146] 快照数组
 */

// @lc code=start
#include <map>
#include <unordered_map>
using namespace std;
class SnapshotArray {
public:
    int sid = 0;
    unordered_map<int,map<int,int>> mp;//分别存储索引，快照号，修改之后的值
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        mp[index][sid] = val;
    }
    
    int snap() {
        return sid++;
    }
    
    int get(int index, int snap_id) {//二分查找
        if(!mp.count(index))return 0;
        auto it = mp[index].upper_bound(snap_id);
        return it == mp[index].begin()?0:(--it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end

