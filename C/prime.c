#include <stdio.h>

struct Prime
{
    int x, y;
    int * primelist;
};

void makePrimeList(struct Prime p);

int main(int argc, char const *argv[])
{
    int x, y;
    printf("Enter two numbers to find all prime numbers between them:\n");
    scanf("%d %d", &x, &y);

    printf("This is what you entered: %d, and %d.\nI will now display all intermediate prime numbers, inclusive:\n", x, y);
    struct Prime myPrimes;
    myPrimes.x = x;
    myPrimes.y = y;
    
    makePrimeList(myPrimes);


}

void makePrimeList(struct Prime p) {
    int i = p.x;
    for ( ; i < p.y; i++) {
        
    }
}