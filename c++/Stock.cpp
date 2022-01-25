// 2034. Stock Price Fluctuation 
#include <iostream>
#include <map>
#include <set>
#include <limits.h>

using namespace std;

class StockPrice {
public:
    void update(int timestamp, int price) {
        auto p = list.find(timestamp);
        if(p != list.end())
            set.erase(set.find(p->second));
        list[timestamp] = price;
        set.insert(price);
    }
    
    int current() {
        auto i = list.rbegin();
        return i->second;
    }
    
    int maximum() {
        return *set.rbegin();
    }
    
    int minimum() {
        return *set.begin();
    }

    void print(){
        for(auto i : list){
            cout<<i.first<<" " << i.second << endl;
        }
    }
private:
    map<int, int> list;
    multiset<int> set;
};

int main(){
    StockPrice* obj = new StockPrice();
    obj->update(1, 10);
    obj->update(2, 5);
    obj->print();
    int param_2 = obj->current();
    int param_3 = obj->maximum();
    int param_4 = obj->minimum();
    cout << param_2 << " " << param_3 << " " << param_4 << endl;
    return 0;
}