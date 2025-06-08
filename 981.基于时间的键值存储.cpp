/*
 * @lc app=leetcode.cn id=981 lang=cpp
 *
 * [981] 基于时间的键值存储
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class TimeMap {
private://以key为键，二元组(时间戳和value)为值存储映射关系
    unordered_map<string,vector<pair<int,string>>> map;
public:
    TimeMap() { 
    }
    
    void set(string key, string value, int timestamp) {
        map[key].emplace_back(timestamp,value);//放入key对应的vector容器中
    }
    string get(string key, int timestamp) {
        auto &up  = map[key];//找到key对应的vector
        //设置占位符，strin({127})确保一定大于等于所有的timestamp值
        pair<int,string> target = make_pair(timestamp,string({127}));
        //利用二分查找找到timestamp时刻前的最大值
        auto str = upper_bound(up.begin(),up.end(),target);
        if (str!=up.begin())
        {//确保存在小于timestamp的值并且容器不为空
            return (str-1)->second;//返回前一个位置的value值
        }
        return "";//无对应值则返回空
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

