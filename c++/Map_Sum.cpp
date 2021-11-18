//677. Map Sum Pairs

#include <iostream>
#include <unordered_map>

class MapSum {
public:
    MapSum() {}

    void insert(std::string key, int val) {
        mp[key] = val;
    }

    int sum(std::string prefix) {
        int re = 0;
        for(auto & [key,val] : mp) {
            if(key.substr(0, prefix.size()) == prefix) {
                re += val;
            }
        }
        return re;
    }

private:
    std::unordered_map<std::string, int> mp;
};