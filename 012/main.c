#include <stdlib.h> // rand(), malloc(), free()
#include <stddef.h> // NULL

struct node {
  int value;
  struct node* left;
  struct node* right;
};

int sumTheTreeValues(struct node* root);


