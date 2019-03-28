#include<stdio.h> 
#include<stdlib.h> 
#include<stdbool.h>
#include <string.h>
typedef struct node
{
  int DATA;
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
    struct tree * new_t = malloc(sizeof new_t);
    new_t->root = NULL;
    new_t->count = 0;
    t = new_t;
}
int find(tree* t, int value, node* node1)
{
  struct node * node2;
  node2 = t->root;
  if (t->root == NULL)
  {return 1;}
  while (1){
    if (node2 == NULL) {
      return 1;
    } else if (node2->DATA == value){
      node1->DATA = node2->DATA;
      node1->left = node2->left;
      node1->right = node2->right;
      node1->parent = node2->parent;
      return 0;
    } else if (value > node2->DATA){
      node2 = node2->right;
    } else {
      node2 = node2->left;
    }
  }
  return 1;
}
int insert(tree* t, int value)
{
  struct node * node1, ** nodenode, * nodenodenode = NULL;
  struct node * e_n;
  e_n = malloc(sizeof * e_n);
  int error = find(t, value, e_n);
  if (error == 0){
    return 1;
  }
  nodenode = &t->root;
  node1 = t->root;
  while (1){
    if (node1 == NULL) {
      node1 = *nodenode = malloc(sizeof * node1);
      if (node1 != NULL){
        node1->DATA = value;
        node1->left = NULL;
        node1->right = NULL;
        node1->parent = nodenodenode;
        t->count++;
        return 0;
        return 2; 
      }
    }
    nodenodenode = node1;
    if (value > node1->DATA){
      nodenode = &node1->right;
      node1 = node1->right;
    } else {
      nodenode = &node1->left;
      node1 = node1->left;
    }
  }
  return 0;
}
int _remove(tree* t, int value){
  node * node1 = t->root;
  if (t->root == NULL){
    return 1;
  }
  while (1){
    if (node1 == NULL) {
      break;
      return 1;
    } else if (node1->DATA == value){
      break;
    } else if (value > node1->DATA){
      node1 = node1->right;
    } else {
      node1 = node1->left;
    }
  }
  if ((node1->left == NULL) && (node1->right == NULL)){
    if (node1->parent->right->DATA == node1->DATA){
      node1->parent->right = NULL;
    } else {
      node1->parent->left = NULL;
    }
  } else if (node1->right == NULL){
    *node1 = *node1->left;
  } else if (node1->left == NULL){
    *node1 = *node1->right;
  } else {
    node * search = node1->right;
    int min_value;
    node *min;
    while (1){
      if (search == NULL) {
        break;
      } else {
        min = search;
        min_value = search->DATA;
        search = search->left;
      }
    }
    node1->DATA = min->DATA;
    node1 = min;
    if ((node1->left == NULL) && (node1->right == NULL)){
      if (node1->parent->right->DATA == node1->DATA){
        node1->parent->right = NULL;
      } else {
        node1->parent->left = NULL;
      }
    } else if (node1->right == NULL){
      *node1 = *node1->left;
    } else {
      *node1 = *node1->right;
    }
  }
  t->count--;
  return 0;
}
int removeMin(node* node1){
  if (node1->left == NULL){
    node1 = node1->right;
  }
  while(1){
    if (node1->left == NULL){
      if ((node1->left == NULL) && (node1->right == NULL)){
        if (node1->parent->right->DATA == node1->DATA){
          node1->parent->right = NULL;
        } else {
          node1->parent->left = NULL;
        }
      } else if (node1->right == NULL){
        *node1 = *node1->left;
      } else {
        *node1 = *node1->right;
      }
      return node1->DATA;
    } else {
      node1 = node1->left;
    }
  }
}
int rotateRight(tree * t, node *x){
  node * y = x->left;
  if ((y != NULL) && (x != NULL)){
    x->left = y->right;
    if (y->right != NULL){
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent != NULL){
      if (x->parent->left == x){
        x->parent->left = y;
      } else {
        x->parent->right = y;
      }
    }
    t->root = y;
    y->right = x;
    x->parent = y;
    return 0;
  } else {return 1;}
}
int rotateLeft(tree * t, node *x){
  node * y = x->right;
  if ((y != NULL) && (x != NULL)){
    x->right = y->left; 
    if (y->left != NULL){
      y->left->parent = x; 
    }
    y->parent = x->parent;
    if (x->parent != NULL){
      if (x->parent->right == x){
        x->parent->right = y;
      } else {
        x->parent->left = y;
      }
    }
    t->root = y;
    y->left = x;
    x->parent = y;
    return 0;
	} else {
    return 1;
  }
}
int tree_depth(struct node * node1, int deep){
  if (node1 == NULL){
    return deep;
  }
  int d1 = tree_depth(node1->left, deep + 1);
  int d2 = tree_depth(node1->right, deep + 1);
  return (d1 > d2) ? d1 : d2;
}
void depth(struct node * node1){
  if (node1 != NULL){
    printf("%d ", node1->DATA);
    depth(node1->left);
    depth(node1->right);
	} else {
  }
}
void printNode(struct node * node1, int current, int deep, int first){
  if (current == deep){
      if (first > 0){
        printf(" ");
      }
    if (node1 == NULL){
      printf("_");
    } else{
      printf("%d", node1->DATA);} 
  } else if (node1 != NULL){
    printNode(node1->left, current + 1, deep, first);
    printNode(node1->right, current + 1, deep, first + 1);
  } else {
    printNode(node1, current + 1, deep, first);
    printNode(node1, current + 1, deep, first + 1);}
}
void print(struct node * node1)
{
  int m = tree_depth(node1, 0);
  for (int i = 1; i <= m; i++){
    printNode(node1, 1, i, 0);
    printf("\n");
  }
}   
void printTree(struct tree * t)
{
    print(t->root);
}
int main(){
  struct tree * t = malloc(sizeof t);
  init(t);
  for (int i = 0; i < 4; i++){
    int a;
    scanf("%d", &a);
    insert(t, a);
  }
  printTree(t);
  for (int i = 0; i < 3; i++){
    int a;
    scanf("%d", &a);
    insert(t, a);
  }
  printTree(t);
  int hate1;
  scanf("%d", &hate1);
  struct node * node1;
  node1 = malloc(sizeof * node1);
  find(t, hate1, node1);
  if (node1->parent != NULL){
    printf("%d ", node1->parent->DATA);
  } else {
    printf("_ ");
  }
  if (node1->left != NULL){
    printf("%d ", node1->left->DATA);
  } else {
    printf("_ ");
  }
  if (node1->right != NULL){
    printf("%d\n", node1->right->DATA);
  } else {
    printf("_\n");
  }
  int hate2;
  scanf("%d", &hate2);
  struct node * node2;
  node2 = malloc(sizeof * node2);
  int error = find(t, hate2, node1);
  if (error == 1){
    printf("-\n");
  } else {
    if (node2->parent != NULL){
      printf("%d ", node2->parent->DATA);
    } else {
      printf("_ ");
    }
    if (node2->left != NULL){
      printf("%d ", node2->left->DATA);
    } else {
      printf("_ ");
    }
    if (node2->right != NULL){
      printf("%d\n", node2->right->DATA);
    } else {
      printf("_\n");
    }
  }
  int hate3;
  scanf("%d", &hate3);
  _remove(t, hate3);
  printTree(t);
  while (rotateLeft(t, t->root) != 1);
  printTree(t);
  while (rotateRight(t, t->root) != 1);
  printTree(t);
  printf("%d\n", t->count);
  printf("-\n");
  return 0;
}
