#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Prime {
    int x, y;
    int size;
    int* primelist;
};

void makePrimeList(struct Prime* p);
void swap(int* a, int* b);
bool checkPrime(int num);
void displayPrimeList(struct Prime p);
void deleteList(struct Prime* p);

int main(int argc, char const* argv[]) {
    int x, y;
    bool done = false;
    while(!done) {
        printf("Enter two numbers to find all prime numbers between them:\n");
        scanf("%d %d", &x, &y);
        if (x > 1 && y > 1)
            done = true;
        else
            printf("\nYou have entered illegal values. Try again.\n");
    }
    printf("This is what you entered: %d, and %d.\nI will now display all intermediate prime numbers, inclusive:\n", x, y);
    if (x > y)
        swap(&x, &y);
    struct Prime myPrimes;
    myPrimes.x = x;
    myPrimes.y = y;
    myPrimes.primelist = malloc(sizeof(int)*(y-x));
    
    makePrimeList(&myPrimes);
    displayPrimeList(myPrimes);

    deleteList(&myPrimes);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void makePrimeList(struct Prime* p) {
    int t = 0;
    p->size = p->y - p->x;
    for (int i = p->x; i <= p->y; i++) {
        if (checkPrime(i)) {
            p->primelist[t] = i;
            t++;
        }
        else 
            (p->size)--;
    }
}

bool checkPrime(int num) {
    for (int i = 2; i <= num/2; i++) {
        if ((num % i) == 0)
            return false;
    }
    return true;
}

void displayPrimeList(struct Prime p) {
    for (int i = 0; i <= p.size; i++)
        printf("p.primeList[%d] = %d\n", i, p.primelist[i]);
}

void deleteList(struct Prime* p) {
    p->size = 0;
    if (p->primelist != NULL)
        free(p->primelist);
}