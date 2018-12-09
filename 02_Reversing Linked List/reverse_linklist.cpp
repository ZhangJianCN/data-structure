#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct Node{
    string current_address;
    int data;
    string next_address;

    Node(string _current_address, int _data, string _next_address):
            current_address(_current_address), data(_data), next_address(_next_address){};
};

void reverse(vector<string> &address_vector){
    int size = address_vector.size();
    for(int i = 0; i < floor(size/2.0f); ++i){
        string tmp;
        tmp = address_vector[i];
        address_vector[i] = address_vector[size-i-1];
        address_vector[size-1-i] = tmp;
    }
}

int main(){
    // input
    unordered_map<string, Node> map;
    string start_address;
    int linklist_len;
    int reverse_len;
    cin>>start_address>>linklist_len>>reverse_len;
    for(int i; i<linklist_len; ++i){
        string current_address;
        int current_data;
        string next_address;
        cin>>current_address>>current_data>>next_address;
        Node node(current_address, current_data, next_address);
        map.insert(make_pair(current_address, node));
    }

    //sort vector
    vector<string> address_vector;
    string current_address = start_address;
    for(int i = 0; i < linklist_len; ++i){
        auto node_iter = map.find(current_address);
        if(node_iter == map.end()){break;};
        address_vector.push_back(current_address);
        current_address = node_iter->second.next_address;
        if(current_address == "-1"){break;};
    }

    int vector_size = address_vector.size();
    vector<string> res;
    for(int i = 0; i < ceil(vector_size/float(reverse_len)); ++i){
        int start = i*reverse_len;
        int end = min(reverse_len, vector_size-reverse_len*i);
        vector<string> tmp (address_vector.begin() + start,address_vector.begin() + start + end);
        if(i < floor(vector_size/float(reverse_len))){reverse(tmp);};
        res.insert(res.end(), tmp.begin(), tmp.end());
    }
    int res_size = res.size();
    for(int i = 0; i < res_size-1; ++i){
        string key = res[i];
        string next_key = res[i+1];
        auto node_iter = map.find(key);
        auto node_iter2 = map.find(next_key);
        cout<<node_iter->second.current_address<<" ";
        cout<<node_iter->second.data<<" ";
        cout<<node_iter2->second.current_address<<endl;
    }
    string key = res[res.size()-1];
    auto node_iter = map.find(key);
    cout<<node_iter->second.current_address<<" "<<node_iter->second.data<<" "<<"-1";

    return 0;
}