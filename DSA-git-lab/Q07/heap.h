#ifndef HEAP
#define HEAP
#include<stdlib.h>

typedef struct Tree{
    int val;
    struct Tree* parent;
    struct Tree* left;
    struct Tree* right;
}tree;

void insertLeft(tree* node, int val){
    node->left = (tree*)malloc(sizeof(tree));
    node->left->val = val;
    node->left->left = NULL;
    node->left->right = NULL;
    node->left->parent = node;
}

void insertRight(tree* node, int val){
    node->right = (tree*)malloc(sizeof(tree));
    node->right->val = val;
    node->right->left = NULL;
    node->right->right = NULL;
    node->right->parent = node;
}

void insertLeftNode(tree* root, tree* node){
    if(root == NULL){
        root = node;
        return;
    }
    while(root->left)
        insertLeftNode(root,node);
    root->left = node;
}

void insertRightNode(tree* root, tree* node){
    if(root == NULL){
        root = node;
        return;
    }
    while(root->right)
        insertLeftNode(root,node);
    root->right = node;
}

tree* initNode(tree* node, int val){
    if(node == NULL){
        node = (tree*)malloc(sizeof(tree));
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;
    }
    node->val = val;
    return node;
}

tree* insertAuto(tree* node, int val){
    if(node == NULL){
        node = initNode(node, val);
        return node;
    }
    if(val <=  node->val){
        if(node->left == NULL)
            insertLeft(node,val);
        else{
            insertAuto(node->left,val);
        }
    }
    else{
        if(node->right == NULL)
            insertRight(node, val);
        else{
            insertAuto(node->right,val);
        }
    }
    return node;
}

void postmalone(tree* node){
    if(node->left)
        postmalone(node->left);
    if(node->right)
        postmalone(node->right);
    if(node){
        printf("%d ", node->val);
    }
}

void postOrder(tree* node){
    postmalone(node);
    printf("\n");
}

void premalone(tree* node){
    if(node){
        printf("%d ", node->val);
    }
    if(node->left)
        premalone(node->left);
    if(node->right)
        premalone(node->right);
}

void preOrder(tree* node){
    premalone(node);
    printf("\n");
}

void inmalone(tree* node){
    if(node->left)
        inmalone(node->left);
    if(node){
        printf("%d ", node->val);
    }
    if(node->right)
        inmalone(node->right);
}

void inOrder(tree* node){
    inmalone(node);
    printf("\n");
}

tree* searchNode(tree* node, int val){
    if(node == NULL){
        return NULL;
    }
    if(node->val > val){
        return searchNode(node->left,val);
    }
    if(node->val < val)
        return searchNode(node->right,val);
    return node;

}

void deleteNode(tree* node){
    if(node->left){
        deleteNode(node->left);
    }   
    if(node->right){
        deleteNode(node->right);
    }
    if(node){
        //printf("Node getting deleted: %d\n", node->val);
        if(node->parent){
            if(node->parent->left == node)
                node->parent->left = NULL;
            if(node->parent->right == node)
                node->parent->right = NULL;
            node->parent = NULL;
        }
        free(node);
    }
}

int deleteFromTree(tree* heap, int val){
    tree* node = searchNode(heap, val);
    if(node == NULL){
        return 0;
    }
    deleteNode(node);
    return 1;
}

int treeHeight(tree* heap){
    int height = 0;
    while(heap != NULL){
        heap = heap->left;
        height++;
    }
    return height;
}
#endif //HEAP

int findMax(tree* heap){
    tree* node = heap;
    while(node->right != NULL){
        node = node->right;
    }
    return node->val;
}
