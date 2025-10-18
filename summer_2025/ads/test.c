# include <stdio.h>
# include <stdlib.h>
# include <math.h>
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
    for(i=0; i<num; i++){
        if(key < Data[i]){
            for(int j=num; j>i; j--){
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
    Tree quene[1000];
    if(root == NULL){
    }
    else{
        int fr=0,re=0;
        quene[re]=root;
        int num = 1;
        int num2;
        re++;
        while(fr!=re){
            Tree temp=quene[fr];
            fr++;
            printf("[");
            for(int i=0; i<temp->data_num; i++){
                printf("%d",temp->Data[i]);
                if(i!= temp->data_num-1){
                    printf(",");
                }
            }
            printf("]");
            num--;
            if(temp->is_leaf == 0){
                for(int i=0; i<temp->data_num+1; i++){
                    if(temp->child[i]!= NULL){
                        num2++;
                        quene[re] = temp->child[i];
                        re++;
                    }
                }
            }
            if(num==0){
                printf("\n");
                num=num2;
                num2=0;
            }
        }
    }
           
}
Tree Split(Tree root){
    if(root->is_leaf == 1){
        Tree root2 = (Tree) malloc(sizeof(struct Node));
            root2->Data[0] = root->Data[2];
            root2->Data[1] = root->Data[3];
            root2->data_num = 2;
            root2->is_leaf = 1;
        if(root->parent == NULL){
            Tree root1 = (Tree) malloc(sizeof(struct Node));
            root1->Data[0] = root->Data[2];
            root1->data_num = 1;
            root1->is_leaf = 0;
            root1->parent = NULL;
            root1->child[0] = root;
            root->parent = root1;
            root->data_num = 2;
            root2->parent = root1;
            root1->child[1] = root2;
            return root1;
        }
        else{
            root->data_num = 2;
            root2->parent = root->parent;
            Tree root1 = root->parent;
            int index;
            index = In(root->Data[2], root1->Data, root1->data_num);
            root1->data_num++;
            for(int i=root1->data_num; i>index+1; i--){
                root1->child[i] = root1->child[i-1];
            }
            root1->child[index+1] = root2;
            if(root1->data_num == 3){
                Tree new_root = Split(root1);
                return new_root;
            }
        }
    }
    else{
        root->data_num = 1;
        Tree root2 = (Tree) malloc(sizeof(struct Node));
        root2->Data[0] = root->Data[2];
        root2->data_num = 1;
        root2->is_leaf = 0;
        root2->child[0] = root->child[2];
        root2->child[1] = root->child[3];
        root2->child[2] = NULL;
        root2->child[3] = NULL;
        root2->child[4] = NULL;
        root2->child[0]->parent = root2;
        root2->child[1]->parent = root2;
        if(root->parent == NULL){
            Tree root1 = (Tree) malloc(sizeof(struct Node));
            root1->Data[0] = root->Data[1];
            root1->data_num = 1;
            root1->is_leaf = 0;
            root1->parent = NULL;
            root1->child[0] = root;
            root1->child[1] = root2;
            root->parent = root1;
            root2->parent = root1;
            return root1;
        }
        else{
            root2->parent = root->parent;
            Tree root1 = root->parent;
            int index;
            index = In(root->Data[1], root1->Data, root1->data_num);
            root1->data_num++;
            for(int i=root1->data_num; i>index+1; i--){
                root1->child[i] = root1->child[i-1];
            }
            root1->child[index+1] = root2;
            if(root1->data_num == 3){
                Tree new_root = Split(root1);
                return new_root;
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
    Tree root_temp = root;
    while(root_temp->is_leaf == 0){
        int i;
        for(i = 0; i < root_temp->data_num; i++){
            if(key < root_temp->Data[i]){
                root_temp = root_temp->child[i];
                break;
            }
        }
        if(i == root_temp->data_num){
            root_temp = root_temp->child[root_temp->data_num];
        }
    }
    index = In(key, root_temp->Data,root_temp->data_num);
    root_temp->data_num++;
    if(root_temp ->data_num == 4){
        Tree new_root = Split(root_temp);
        if(new_root != NULL) {
            return new_root;
        }
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
    for(int i=0; i<N; i++){
        scanf("%d", &read);
        index = 1;
        for(int j=0; j<count;j++){
            if(data[j] == read){
                printf("Key %d is duplicated\n", read);
                index =0;
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
        root =Insert(data[i], root);
    }
    Print (root);
}