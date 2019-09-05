/**
 * Generic Linked List Implementation
 */

#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int val;
    struct node * next;
};  // typedef = Node

struct list {
    Node * head;
    int length;
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

void addFirst(List * l, int x) {
    Node * newest = create_node(x);
    newest->next = l->head;
    l->head = newest;
    l->length++;
}

void addLast(List * l, int x) {
    if (l->head == NULL)
        l->head = create_node(x);
    else {
        Node * newest = l->head;
        while (newest->next != NULL) {
            newest = newest->next;
        }
        newest->next = create_node(x);
    }
}

List * makelist() {
    List * l = malloc(sizeof(List));
    if (!l)
        return NULL;
    l->head = NULL;
    l->length = 0;
    return l;
}

void print_list(List * l) {
    Node * current = l->head;
    if(l->head == NULL) 
        return;
    for(; current != NULL; current = current->next) {
        if (current->next == NULL)
            printf("%d\n", current->val);
        else
            printf("%d, ", current->val);
    }
}

void reverse(List * l) {
    Node * temp = NULL;
    Node * r = NULL;
    Node * current = l->head;
    while (current != NULL) {
        temp = current;
        current = current->next;
        temp->next = r;
        r = temp;
    }
    l->head = r;
}

Node *list_nth_node(List *l, int n) {
    assert(0 <= n && n < l->length);
    Node *iter = l->head;
    int i = 0;
    while (i < n) {
        iter = iter->next;
        i++;
    }
    return iter;
}

void remove_nth(List * l, int n) {
    assert(0 <= n < l->length);
    Node * old_node = NULL;
    if (n == 0) {
        old_node = l->head;
        l->head = old_node->next;
    }
    else {
        Node * old_proceeding = list_nth_node(l, n-1);
        old_node = old_proceeding->next;
        old_proceeding->next = old_node->next;
    }
    l->length -= 1;
    free(old_node);
}

void destroy_list(List * l) {
    Node * temp = l->head;
    Node * current = temp;
    while (temp != NULL) {
        current = temp->next;
        free(temp);
        temp = current;
    }
    free(l);
    l = NULL;
}
