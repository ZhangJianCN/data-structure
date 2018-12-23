#include <iostream>
using namespace std;

template <class T>
struct TreeNode{
    int left;
    int right;
    T data;

    TreeNode():left(-1),right(-1){};
};

int input(int tree_node_num, TreeNode<char> *&tree_node_array);
bool compare_tree(int tree1_node_idx, int tree2_node_idx, TreeNode<char> *tree1_array, TreeNode<char> *tree2_array);
char child_data(int idx, TreeNode<char> *tree_array);

int main(){
    int tree1_node_num;
    TreeNode<char>* tree1_array;
    cin>>tree1_node_num;
    int root1 = input(tree1_node_num, tree1_array);
    
    int tree2_node_num;
    TreeNode<char>* tree2_array;
    cin>>tree2_node_num;
    int root2 = input(tree2_node_num, tree2_array);
    
    bool root_status = (root1 == -1 || root2 == -1);
    if(root_status){
        if(root1 == -1 && root2 == -1){
            cout<<"Yes";
            return 0;
        }
        else{
            cout<<"No";
            return 0;
        }
    }
    
    bool flag = compare_tree(root1, root2, tree1_array, tree2_array);
    if(flag){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    return 0;
 }  

int input(int tree_node_num, TreeNode<char> *&tree_node_array){
    int* check = new int[tree_node_num]; 
    tree_node_array  = new TreeNode<char>[tree_node_num];
    for(int i = 0; i < tree_node_num; ++i){
        cin>>tree_node_array[i].data;
        char left, right;
        cin>>left;
        cin>>right;
        if(left  != '-'){
            tree_node_array[i].left = left - '0';
            check[tree_node_array[i].left] = 1;
        }
        else{
            tree_node_array[i].left = -1;
        }

        if(right != '-'){
            tree_node_array[i].right = right - '0';
            check[tree_node_array[i].right] = 1;
        }
        else{
            tree_node_array[i].right = -1;
        }
        
    } 
    for(int i = 0; i < tree_node_num; ++i){
        if(!check[i]){
            return i;
        }
    }
    return -1;
 }

 bool compare_tree(int tree1_node_idx, int tree2_node_idx, TreeNode<char> *tree1_array, TreeNode<char> *tree2_array){
    TreeNode<char> tree1_node = tree1_array[tree1_node_idx];
    TreeNode<char> tree2_node = tree2_array[tree2_node_idx];
    
    if(tree1_node.data != tree2_node.data){
        return false;
    }
    char tree1_node_left_data = child_data(tree1_node.left, tree1_array);
    char tree1_node_right_data = child_data(tree1_node.right, tree1_array);
    char tree2_node_left_data = child_data(tree2_node.left, tree2_array);
    char tree2_node_right_data = child_data(tree2_node.right, tree2_array);

    bool status1 = (tree1_node_left_data == tree2_node_left_data) && 
                   (tree1_node_right_data == tree2_node_right_data);  
    bool status2 = (tree1_node_left_data == tree2_node_right_data) && 
                   (tree1_node_right_data == tree2_node_left_data); 

    if(status1){
        bool status1_1 = true, status1_2 = true;
        if(tree1_node_left_data != '-'){
            status1_1 = compare_tree(tree1_node.left, tree2_node.left, tree1_array, tree2_array);
        }
        if(tree1_node_right_data != '-'){
            status1_2 = compare_tree(tree1_node.right, tree2_node.right, tree1_array, tree2_array);
        }
        if((status1_1 && status1_2) == false){
            return false;
        }
    }
    if(status2){
        bool status2_1 = true, status2_2 = true;
        if(tree1_node_left_data != '-'){
            status2_1 = compare_tree(tree1_node.left, tree2_node.right, tree1_array, tree2_array);
        }
        if(tree1_node_right_data != '-'){
            status2_2 = compare_tree(tree1_node.right, tree2_node.left, tree1_array, tree2_array);
        }
        if((status2_1 && status2_2) == false){
            return false;
        }
    }
    return status1 || status2;
 }

char child_data(int idx, TreeNode<char> *tree_array){
    if(idx == -1){
        return '-';
    }
    else{
        return tree_array[idx].data; 
    }
}