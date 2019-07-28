#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

BStree bstree_ini(void){//CONSTRUCTOR, ALLOCATES MEMORY AND RETURNS EMPTY BSTREE
    BStree emptyTree;
    emptyTree = (BStree)malloc(sizeof(BStree_node));
    *emptyTree = NULL;
    return emptyTree;
}

void bstree_insert(BStree bst, Key key, Data data){//INSERT KEY AND DATA INTO TREE UNLESS IT IS ALREADY EXISTS
    if(*bst == NULL){
        *bst = new_node(key,data);//CHECKS IF ROOT EXISTS, IF IT DOESNT IT SETS THE ROOT AS THE KEY AND DATA
    }else{
        insert(*bst,key,data);//IF THE ROOT EXISTS CALLS INSERT FUNCTION
    }
}

void insert(BStree_node *node, Key key, Data data){//INSERTS UNIQUE NODE INTO TREE
     if(key_comp(node->key,key)>0){//LEFT
        if(node->left != NULL){
        insert(node->left,key,data);
        }
        else{
        node->left = new_node(key,data);
        }
    }
    else if(key_comp(node->key,key)<0){//RIGHT
        if(node->right != NULL){
        insert(node->right,key,data);
        }
        else{
        node->right = new_node(key,data);
        }
    }

}

BStree_node *new_node(Key key, Data data){//ALLOCATES MEMORY FOR NEW NODE, RETURNS NEW NODE WITH KEY & DATA SET
    BStree_node *newNode;
    newNode = (BStree_node *)malloc(sizeof(BStree_node));
    newNode -> key = key;
    newNode -> data=data;
    return newNode;
}

//Finds the corresponding node to the key using a recursive search
Data bstree_search(BStree bst, Key key){//RECURSIVELY FIND NODE
    if(*bst == NULL){
        return NULL;//CHECKS IF TREE IS EMPTY
    }
    return find(*bst,key);
}
Data find(BStree_node *searchNode, Key key){//GOES LEFT TO RIGHT RECURSIVELY SEARCHIN FOR NODE OR NULL
    if(searchNode ==NULL){//BSAE CASE 1
        return NULL;
    }
    if(key_comp(searchNode->key,key)==0){//BASE CASE 2
        return searchNode->data;
    }
    else if(key_comp(searchNode->key,key)<0){//RIGHT
        return find(searchNode->right,key);
    }
    else{
        return find(searchNode->left,key);//LEFT
    }
}
void bstree_traversal(BStree bst){//PRINTS INORDER TRAVERSAL RECURSIVELY
    if(bst!=NULL){
        inorderTraversal(*bst);
    }
}
void inorderTraversal(BStree_node *node){//RECURSIVE INORDER TRAVERSAL
    if(node == NULL){
        return;
    }
    inorderTraversal(node->left);//LEFT
    key_print(node->key);
    data_print(node->data);
    inorderTraversal(node->right);//RIGHT
}
void bstree_free(BStree bst){
    freeNode(*bst);
    free(bst);
}
void freeNode(BStree_node *node){//FREE MEMORY OF EACH NODE RECURSIVELY
    if(node == NULL){
        return;
    }
    freeNode(node->left);
    freeNode(node->right);
    if(node->key != NULL){
    key_free(node->key);
    }
    if(node->data!= NULL){
    data_free(node->data);
    }
}
