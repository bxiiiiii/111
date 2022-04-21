#include <iostream>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

class LRUCache {
 public:
  LRUCache(int capacity) { capacity_ = capacity; }
  int get(int key) {
    if (ma.find(key) == ma.end()) {
      return -1;
    } else {
      li.splice(li.begin(), li, ma[key]);
      return ma[key]->second;
    }
  }
  void put(int key, int value) {
    if (ma.find(key) == ma.end()) {
      li.emplace_front(key, value);
      ma[key] = li.begin();
      if (ma.size() > capacity_) {
        ma.erase(li.back().first);
        li.pop_back();
      }

    } else {
      ma[key]->second = value;
      li.splice(li.begin(), li, ma[key]);
    }
  }

 private:
  int capacity_;
  list<pair<int, int>> li;
  unordered_map<int, list<pair<int, int>>::iterator> ma;
};