#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
// Input: ’size’: size of an array
// Output: a pointer of type BStree,
// i.e. a pointer to an allocated memory of BStree_struct type
// Effect: dynamically allocate memory of type BStree_struct
// allocate memory for a Node array of size+1 for member tree_nodes
// allocate memory for an unsigned char array of size+1 for member is_free
// set all entries of is_free to 1
// set member size to ’size’;
BStree bstree_ini(int size) {
    //DECLARES VARIABLES
    BStree newTree;
    Node *newNode;
    unsigned char *is_free;
    int i;
    //CREATES TREE, NODE AND is_free
    newTree= (BStree)malloc(sizeof(BStree_struct));
    newNode=(Node*)malloc((size+1)*sizeof(Node));
    is_free=(unsigned char*)malloc((size+1)*sizeof(unsigned char));
    //CREATES NODES IN TREE AND SETS IS_FREE
    newTree -> tree_nodes = newNode;
    newTree -> is_free = is_free;
    //SET EVERYTHING TO FREE
    for (i = 0; i < size+1;i++){
        newTree -> is_free[i] = '1';
    }
    //SET TREE SIZE TO SIZE
    newTree -> size = size;
    return newTree;
}

// Input: ’bst’: a binary search tree
// ’key’: a pointer to Key
// ’data’: an integer
// Effect: ’data’ with ’key’ is inserted into ’bst’
// if ’key’ is already in ’bst’, do nothing
void bstree_insert(BStree bst, Key *key, int data) {
    Node *newNode;
    newNode=(Node *)malloc(sizeof(Node));
    newNode -> key = key;
    newNode -> data = data;
    int c = 1;
    //ROOT OF THE FUNCTION
    if (bst ->is_free[1] == '1'){
        bst -> tree_nodes[1] = *newNode;
        bst -> is_free[1] = '0';
    //INSERTS INTO TREE
    }else{
        insert(bst,newNode,c);
    }

}

//HELPER METHOD
void insert(BStree tree, Node *newNode,int c){
    //CHECKS ROOT IS EMPTY
    if (tree -> is_free[c] == '1'){
        tree -> tree_nodes[c] = *newNode;
        tree -> is_free[c] = '0';
    }
        //CHECKS LEFT NODE
        else if (key_comp(*newNode->key, *tree -> tree_nodes[c].key) < 0){
                insert(tree,newNode,c*2);
        }
        //CHECKS RIGHT NODE
        else if (key_comp(*newNode->key, *tree -> tree_nodes[c].key) > 0){
                insert(tree,newNode,c*2+1);
        }
}

//HELPER METHOD
void inOrder(BStree tree, int c){
    //CHECKS IF EMPTY
    if(tree->is_free[c] == '0'){
        //CHECKS IF LEFT IS EMPTY
        if(tree->is_free[2*c] == '0'){
            inOrder(tree,2*c);
        }
        //PRINTS
        print_node(tree->tree_nodes[c]);
        //CHECKS IF RIGHT IS EMPTY
        if(tree->is_free[2*c+1]=='0'){
                inOrder(tree,2*c+1);
        }
    }
}

// Input: ’bst’: a binary search tree
// Effect: print all the nodes in bst using in order traversal
void bstree_traversal(BStree bst) {
    int i = 1;//STARTS AT ROOT
    inOrder(bst,i);//CALLS inOrder
}

// Input: ’bst’: a binary search tree
// Effect: all memory used by bst are freed
void bstree_free(BStree bst) {
    free(bst);//RELEASE MEMORY
    bst = NULL;
}

