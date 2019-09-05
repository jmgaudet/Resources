#include <stdio.h>
#include "linkedlist.h"

int main() {

    List * list1 = makelist();

    // Adding to the list:
    addFirst(list1, 44);

    addLast(list1, 2);
    addLast(list1, 5);
    addLast(list1, 432);

    addFirst(list1, 7);
    addFirst(list1, 1);

    print_list(list1);

    // Demonstrating some capabilities:
    printf("%s", "-------------------------\n");
    printf("%s", "Demonstrating the reversal of a list:\n");
    reverse(list1);
    print_list(list1);

    printf("%s", "-------------------------\n");
    printf("%s", "Removing an nth item from the list:\n");    
    remove_nth(list1, 3);
    print_list(list1);

    destroy_list(list1);

}
