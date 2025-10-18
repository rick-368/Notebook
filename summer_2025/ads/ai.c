#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node *PtrToNode;
struct Node {
    int Data[4]; 
    PtrToNode child[5];
    PtrToNode parent;
    int data_num;
    int is_leaf;
};
typedef PtrToNode Tree; 

int In(int key, int Data[4], int num){
    int i;
    for(i = 0; i < num; i++){
        if(key == Data[i]) {
            return -1; // 重复键
        }
        if(key < Data[i]){
            for(int j = num; j > i; j--){
                Data[j] = Data[j-1];
            }
            Data[i] = key;
            return i;
        }
    }
    Data[num] = key;
    return num;
}

void Print(Tree root) {
    if (root == NULL) return;
    
    printf("Node: ");
    for(int i = 0; i < root->data_num; i++) {
        printf("%d ", root->Data[i]);
    }
    printf("(leaf: %d)\n", root->is_leaf);
    
    if (!root->is_leaf) {
        for(int i = 0; i <= root->data_num; i++) {
            Print(root->child[i]);
        }
    }
}

Tree Split(Tree node){
    Tree new_node = (Tree)malloc(sizeof(struct Node));
    new_node->data_num = 0;
    new_node->parent = node->parent;
    
    if(node->is_leaf) {
        // 叶子节点分裂
        new_node->is_leaf = 1;
        
        // 原节点保留前2个数据
        node->data_num = 2;
        
        // 新节点获得后2个数据
        new_node->Data[0] = node->Data[2];
        new_node->Data[1] = node->Data[3];
        new_node->data_num = 2;
        
        // 如果是根节点分裂
        if(node->parent == NULL) {
            Tree new_root = (Tree)malloc(sizeof(struct Node));
            new_root->Data[0] = node->Data[2]; // 中间值提升
            new_root->data_num = 1;
            new_root->is_leaf = 0;
            new_root->parent = NULL;
            
            new_root->child[0] = node;
            new_root->child[1] = new_node;
            
            node->parent = new_root;
            new_node->parent = new_root;
            
            return new_root;
        } else {
            // 非根节点分裂，需要将中间值插入父节点
            Tree parent = node->parent;
            int pos = In(node->Data[2], parent->Data, parent->data_num);
            if(pos != -1) {
                parent->data_num++;
                
                // 调整子节点指针
                for(int i = parent->data_num; i > pos + 1; i--) {
                    parent->child[i] = parent->child[i-1];
                }
                parent->child[pos+1] = new_node;
                
                // 检查父节点是否需要分裂
                if(parent->data_num == 4) {
                    return Split(parent);
                }
            }
        }
    } else {
        // 内部节点分裂
        new_node->is_leaf = 0;
        
        // 原节点保留前2个数据和前3个子节点
        node->data_num = 2;
        
        // 新节点获得后2个数据和后3个子节点
        new_node->Data[0] = node->Data[3];
        new_node->data_num = 1;
        
        new_node->child[0] = node->child[3];
        new_node->child[1] = node->child[4];
        new_node->child[0]->parent = new_node;
        new_node->child[1]->parent = new_node;
        
        if(node->parent == NULL) {
            Tree new_root = (Tree)malloc(sizeof(struct Node));
            new_root->Data[0] = node->Data[2]; // 中间值提升
            new_root->data_num = 1;
            new_root->is_leaf = 0;
            new_root->parent = NULL;
            
            new_root->child[0] = node;
            new_root->child[1] = new_node;
            
            node->parent = new_root;
            new_node->parent = new_root;
            
            return new_root;
        } else {
            Tree parent = node->parent;
            int pos = In(node->Data[2], parent->Data, parent->data_num);
            if(pos != -1) {
                parent->data_num++;
                
                for(int i = parent->data_num; i > pos + 1; i--) {
                    parent->child[i] = parent->child[i-1];
                }
                parent->child[pos+1] = new_node;
                
                if(parent->data_num == 4) {
                    return Split(parent);
                }
            }
        }
    }
    
    return NULL;
}

Tree Insert(int key, Tree root){
    int index;
    if(root == NULL){
        root = (Tree) malloc(sizeof(struct Node));
        root->Data[0] = key;
        root->parent = NULL;
        root->data_num = 1;
        root->is_leaf = 1;
        for(int i = 0; i < 5; i++) {
            root->child[i] = NULL;
        }
        return root;
    }   
    
    Tree current = root;
    Tree parent = NULL;
    
    // 找到插入的叶子节点
    while(current->is_leaf == 0){
        parent = current;
        int i;
        for(i = 0; i < current->data_num; i++){
            if(key < current->Data[i]){
                current = current->child[i];
                break;
            }
        }
        if(i == current->data_num){
            current = current->child[current->data_num];
        }
    }
    
    // 在叶子节点中插入
    index = In(key, current->Data, current->data_num);
    if(index == -1) {
        printf("Key %d is duplicated\n", key);
        return root; // 重复键，直接返回
    }
    current->data_num++;
    
    // 检查是否需要分裂
    if(current->data_num == 4){
        Tree new_root = Split(current);
        if(new_root != NULL) {
            return new_root;
        }
    }
    
    // 返回根节点
    while (root->parent != NULL){
        root = root->parent;
    }
    return root;
}

int main(){
    int N;
    scanf("%d", &N);
    int data[N];
    int count = 0;
    int read;
    int index = 1;
    
    for(int i = 0; i < N; i++){
        scanf("%d", &read);
        index = 1;
        for(int j = 0; j < count; j++){
            if(data[j] == read){
                printf("Key %d is duplicated\n", read);
                index = 0;
                break;
            }
        } 
        if(index){
            data[count] = read;
            count++;    
        }
    }
    
    Tree root = NULL;
    for (int i = 0; i < count; i++) {
        root = Insert(data[i], root);
    }
    Print(root);
    
    return 0;
}



