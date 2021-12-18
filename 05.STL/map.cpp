//
// Created by dji on 11/2/21.
//
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Key{
    int a;
    float b;
};
struct Value{
    int c;
    float d;
};
struct KeyCompare{
    bool operator()(const Key& a, const Key&b){
        return (a.a == b.a)?(a.b<b.b):(a.a<b.a);
    }
};

void remove_iter(){
    map<Key,Value,KeyCompare> m;
    Key k1 = {1,2};
    Value v1 = {3,4};
    m.insert(pair<Key, Value>(k1,v1));
    Key k2 = {5,6};
    Value v2 = {7,8};
    m.insert(pair<Key, Value>(k2,v2));
    cout<<m.size()<<endl;


    vector<Key> v;
    for (auto & iterator : m) {
        if (iterator.first.a<3){
            v.push_back(iterator.first);
        }
    }

    for (auto & i : v) {
        cout<<"erase num:"<<m.erase(i)<<endl;
    }
    cout<<m.size()<<endl;
    cout<<m.begin()->first.a<<endl;

}

int main(int argc, char** argv){
    remove_iter();
    return 0;
}
