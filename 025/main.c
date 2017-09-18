#include<stdlib.h> /* size_t */
#include<stdio.h> /* printf */

struct node {
    int data;
    struct node *next;
};

struct list {
    size_t sz;
    struct node *head;
};

struct list* kPrimes(int k, int start, int nd);
int puzzle(int s);

int main(void) {
    /*
    struct list* res = kPrimes(5, 1000, 1040);
    struct node* ptr = (*res).head;

    for (int i=0;i<(*res).sz;i++) {
        printf("%d ", (*ptr).data);
        ptr = (*ptr).next;
    }
    printf("\n");
    */

    int res_puz = puzzle(138);
    printf("%d\n", res_puz);

    return 0;
}

