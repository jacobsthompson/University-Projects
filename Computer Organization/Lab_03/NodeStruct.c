#include <stdio.h>
#include <stdlib.h>

struct Node {
    int iValue;
    float fValue;
    struct Node *next;
};

int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;
	
	// Insert code here
	printf("Value of Head: %d\n", *head);
    printf("Adress of Head: %p\n", head);
    printf("Value of iValue: %d\n", head->iValue);
    printf("Adress of iValue: %p\n", &head->iValue);
    printf("Value of fValue: %f\n", head->fValue);
    printf("Adress of fValue: %p\n", &head->fValue);
    printf("Adress of next: %p\n", head->next);
	
	
	return 0;
}