#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// return stack used size
bool pop_sequence(vector<int> pop_sequence, int stack_capacity, int sequence_len){
    vector<int> input_sequence;
    for(int i = 1; i < sequence_len+1; ++i){
        input_sequence.push_back(i);
    }
    bool flag = true;
    for(int i = 0; i < sequence_len-1; ++i){
        int current_num = pop_sequence[i];
        int next_num = pop_sequence[i+1];
        auto start_iter = input_sequence.begin();
        auto end_iter = input_sequence.end();
        auto item = find(start_iter, end_iter, current_num);
        // judge if stack overflow
        int used_size = item - start_iter + 1;
        if(used_size > stack_capacity){
            flag = false;
        }
        // judge stack logic
        int item_flag = false;
        int start_idx = used_size - 2; 
        if(start_idx < 0){start_idx = used_size - 1;}
        for(int j = start_idx; j < input_sequence.size(); ++j){
            if(next_num == current_num){
                item_flag = false;
            }
            if(input_sequence[j] != next_num){
                continue;
            }
            item_flag = true;
        }
        if(item_flag == false){
            flag = false;
            break;
        }
        // pop current element
        input_sequence.erase(item);
    }
    return flag;

}

int main()
{
    int stack_capacity, sequence_len, check_num;
    cin>>stack_capacity>>sequence_len>>check_num;
    
    vector<vector<int>> data;
    for(int i = 0; i < check_num; ++i){
        vector<int> pop_sequence;
        data.push_back(pop_sequence);
        for(int j = 0; j < sequence_len; ++j){
            int number;
            cin>>number;
            data[i].push_back(number);
        }
    }

    for(int i = 0; i < check_num; ++i){
        bool state = pop_sequence(data[i], stack_capacity, sequence_len);
        // print
        if(state == false){cout<<"NO";}
        else{cout<<"YES";}
        if(i < check_num - 1){
            cout<<endl;
        }
    }

    return 0;
}
