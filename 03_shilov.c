#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>
typedef struct node
{
  int data;
  struct node * left;
  struct node * right;
  struct node * parent;
} node;
typedef struct tree
{
  struct node * root;
  int count;            
} tree;
void init(tree * t)
{
    struct tree * new_tree = malloc(sizeof new_tree);
    new_tree->root = NULL;
    new_tree->count = 0;
    t = new_tree;
}
int find(tree* t, int value, node* n)
{
  struct node * nodenode;
  nodenode = t->root;
  if (t->root == NULL){
    return 1;
  }
  while (1){
    if (nodenode == NULL) {
      return 1;
    } else if (nodenode->data == value){
      n->data = nodenode->data;
      n->left = nodenode->left;
      n->right = nodenode->right;
      n->parent = nodenode->parent;
      return 0;
    } else if (value > nodenode->data){
      nodenode = nodenode->right;
    } else {
      nodenode = nodenode->left;
    }
  }
  return 1;
}
int insert(tree* t, int value)
{
  struct node * n, ** nodenode, * last_node = NULL;
  struct node * en;
  en = malloc(sizeof * en);
  int error = find(t, value, en);
  if (error == 0){
    return 1;
  }
  nodenode = &t->root;
  n = t->root;
  while (1){
    if (n == NULL) {
      n = *nodenode = malloc(sizeof * n);
      if (n != NULL){
        n->data = value;
        n->left = NULL;
        n->right = NULL;
        n->parent = last_node;
        t->count++;
        return 0;
      } else {
        return 2; 
      }
    }
    last_node = n;  
    if (value > n->data){
      nodenode = &n->right;
      n = n->right;
    } else {
      nodenode = &n->left;
      n = n->left;
    }
  }
  return 0;
}
int depth(struct node * n, int deep){
  if (n == NULL){
    return deep;
  }
  int depth1 = depth(n->left, deep + 1);
  int depth2 = depth(n->right, deep + 1);
  return (depth1 > depth2) ? depth1 : depth2;
}
void printNode(struct node * n, int current, int deep, int first){
  if (current == deep){
      if (first > 0){
        printf(" ");
      } 
    if (n == NULL){
      printf("_");
    } else{
      printf("%d", n->data);
    } 
  } else if (n != NULL){
    printNode(n->left, current + 1, deep, first);
    printNode(n->right, current + 1, deep, first + 1);
  } else {
    printNode(n, current + 1, deep, first);
    printNode(n, current + 1, deep, first + 1);
  }
}
void print(struct node * n)
{
  int m = depth(n, 0);
  for (int i = 1; i <= m; i++){
    printNode(n, 1, i, 0);
    printf("\n");
  }
}   
void printTree(struct tree * t)
{
    print(t->root);
}
void print_obhod1(struct node * n)
{
  int m = depth(n, 0);
  int flag_tree = 0;
  for (int i = 1; i <= m; i++){
    if (flag_tree > 0){
        printf(" ");
    } else {
        flag_tree++;
    }
    printNode(n, 1, i, 0);
  }
}   
void print_obhod2(struct tree * t)
{
    node * a[15];
    int ab = 0;
    node * write[15];
    int wb = 0;
    node * n = t->root;
    while (wb < t->count){ 
        while (n != NULL){
            wb++;
            if (n->right != NULL){
                ab++;
                a[ab] = n->right;
            }
            write[wb] = n;
            n = n->left;
        }
        n = a[ab];
        ab -= 1;    
    }  
    int flag_tree = 0;
    for (int i = 1; i <= wb; i++){
        if (flag_tree > 0){
            printf(" ");
        } else {
            flag_tree++;
        }
        printf("%d", write[i]->data);
    } 
  printf("\n");
}   
void print_obhod3(struct node * n, int flag_tree)
{
    if (n->left != NULL){
        print_obhod3(n->left, flag_tree + 1);
    } 
    if (n->right != NULL){
        print_obhod3(n->right, flag_tree + 1);
    }
    printf("%d", n->data);
    if (flag_tree > 0){
        printf(" ");
    }   
}   
int main(){
  struct tree * t = malloc(sizeof t);
  init(t);
  for (int i = 0; i < 7; i++){
    int a;
    scanf("%d", &a);
    insert(t, a);
  }
  print_obhod3(t->root, 0);
  printf("\n");
  return 0;
}