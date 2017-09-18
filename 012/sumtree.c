struct node {
  int value;
  struct node* left;
  struct node* right;
};

int sumTheTreeValues(struct node* root) {
    if (root) {
        return (*root).value + sumTheTreeValues((*root).left) +
               sumTheTreeValues((*root).right);
    } else {
        return 0;
    }
}

