/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */

// @lc code=start
#include <vector>
#define CAPACITY 1000
using namespace std;
class MyHashMap {
private:
    vector<pair<int,int>> hashmap[CAPACITY];
    int getIndex(int key){//hash key 值
        return key%CAPACITY;
    }
    int getPos(int index,int key){//获取键值对在vector容器中的下标
        for (int i = 0; i < hashmap[index].size(); i++)
        {   //在hashmap容器中下标index的位置遍历vector容器
            //检查vector容器的键值对中是否有key 的值
            if (hashmap[index][i].first == key)
            {
                return i;//查到key值，返回下标
            }
        }
        return -1;
    }
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int index = getIndex(key);
        int ret = getPos(index,key);
        if (ret>=0)
        {
           hashmap[index][ret].second = value;
        }else{
            hashmap[index].push_back(make_pair(key,value));
        }
    }
    
    int get(int key) {
        int index = getIndex(key);
        int ret = getPos(index,key);
        if (ret<0)
        {
            return -1;
        }else{
            return hashmap[index][ret].second;
        }
        
    }
    
    void remove(int key) {
        int index = getIndex(key);
        int ret = getPos(index,key);
        if (ret>=0)
        {
           hashmap[index].erase(hashmap[index].begin()+ret);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

