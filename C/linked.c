#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node * next;
};  // typedef = Node

struct list {
    Node * head;
};  // typedef = List

void init_node(Node * n) {
    n->next = NULL;
    n->val = -1;
}

Node * create_node(int x) {
    Node * newest = malloc(sizeof(Node));
    newest->val = x;
    newest->next = NULL;
    return newest;
}

void addFirst(List * start, int x) {
    Node * newest = create_node(x);
    newest->next = start->head;
    start->head = newest;
}

void addLast(List * list, int x) {
    if (list->head == NULL)
        list->head = create_node(x);
    else {
        Node * newest = list->head;
        while (newest->next != NULL) {
            newest = newest->next;
        }
        newest->next = create_node(x);
    }
}

List * makelist() {
    List * list = malloc(sizeof(List));
    if (!list)
        return NULL;
    list->head = NULL;
    return list;
}

void print_list(List * list) {
    Node * current = list->head;
    if(list->head == NULL) 
        return;
    for(; current != NULL; current = current->next) {
        printf("%d\n", current->val);
    }
}

void reverse(List * list) {
    Node * temp = NULL;
    Node * r = NULL;
    Node * current = list->head;
    while (current != NULL) {
        temp = current;
        current = current->next;
        temp->next = r;
        r = temp;
    }
    list->head = r;
}

void destroy_list(List * list) {
    Node * temp = list->head;
    Node * current = temp;
    while (temp != NULL) {
        current = temp->next;
        free(temp);
        temp = current;
    }
    free(list);
}
