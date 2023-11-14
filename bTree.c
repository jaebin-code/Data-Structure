#include <stdio.h>
#include <stdlib.h>

typedef int BData;

typedef struct _bTreeNode
{
    BData item;
    struct _bTreeNode * left_child;
    struct _bTreeNode * right_child;
}BTreeNode;

BTreeNode *CreateNode(BData item);
void DestroyNode(BTreeNode *Node);
void CreateLeftSubtree(BTreeNode *root, BTreeNode * left);
void CreateRightSubtree(BTreeNode *root, BTreeNode *right);

void Inorder(BTreeNode *root);
void Preorder(BTreeNode *root);
void Postorder(BTreeNode *root);
void Levelorder(BTreeNode *root);

int CountNodes(BTreeNode *node);
int CountHeight(BTreeNode *node);

int main(){
    return 0;
}

BTreeNode *CreateNode(BData item){
    BTreeNode *node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->item = item;
    node->left_child = NULL;
    node->right_child = NULL;

    return node;
};
void DestroyNode(BTreeNode *Node){
    free(Node);
};
void CreateLeftSubtree(BTreeNode *root, BTreeNode *left){
    if(root->left_child != NULL){
        exit(1);
    }
    root->left_child=left;
};
void CreateRightSubtree(BTreeNode *root, BTreeNode *right){
    if (root->right_child != NULL)
    {
        exit(1);
    }
    root->right_child = right;
};
void Inorder(BTreeNode *root){
    if(root!=NULL){
        Inorder(root->left_child);
        printf("%d", root->item);
        Inorder(root->right_child);
    }
};
void Preorder(BTreeNode *root){
    if (root != NULL)
    {
        printf("%d", root->item);
        Preorder(root->left_child);
       
        Preorder(root->right_child);
    }
};
void Postorder(BTreeNode *root){
    if (root != NULL)
    {
        Postorder(root->left_child);
        Postorder(root->right_child);
        printf("%d", root->item);
    }
};
void Levelorder(BTreeNode *root){
    if( root == NULL) return;
    Queue queue;

    initQueue(&queue);
    EnQueue(&queue, root);
    while(!IsEmpty(&queue)){
        root = Peek(&queue);
        DeQueue(&queue);

        printf("%d",root->item);

        if(root->left_child!=NULL){
            EnQueue(&queue, root->left_child);
        }
        if(root->right_child!=NULL){
            EnQueue(&queue, root->right_child);
        }
    }
};

int CountNodes(BTreeNode *node){
    int r = 0, l = 0;
    if(node->left_child!=NULL){
        l = CountNodes(node->left_child);
    }
    if(node->right_child!=NULL){
        r = CountNodes(node->right_child);
    }
    return 1+r+l;
};
int CountHeight(BTreeNode *node){
    int r = 0, l = 0;
    if (node->left_child != NULL)
    {
        l = CountHeight(node->left_child);
    }
    if (node->right_child != NULL)
    {
        r = CountHeight(node->right_child);
    }
    return 1 + max(l,r);
};