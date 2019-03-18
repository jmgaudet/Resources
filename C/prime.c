#include <stdio.h>
#include <stdlib.h>

struct Prime
{
    int x, y;
    int * primelist;
};

void makePrimeList(struct Prime p);
void swap(int* a, int* b);

int main(int argc, char const *argv[])
{
    int x, y;
    printf("Enter two numbers to find all prime numbers between them:\n");
    scanf("%d %d", &x, &y);

    printf("This is what you entered: %d, and %d.\nI will now display all intermediate prime numbers, inclusive:\n", x, y);
    if (x > y)
        swap(&x, &y);
    struct Prime myPrimes;
    myPrimes.x = x;
    myPrimes.y = y;
    myPrimes.primelist = malloc(sizeof(int)*(y-x));
    
    makePrimeList(myPrimes);


}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void makePrimeList(struct Prime p) {
    int t = p.x;
    int size = p.y-p.x;
    printf("this is x: %d, and this is y: %d\n", p.x,p.y);
    for (int i = 0; i < size; i++) {
        p.primelist[i] = t;
        t++;
    }
    for (int i = 0; i < size; i++) {
        printf("p.primeList[%d] = %d\n", i, p.primelist[i]);
    }
}