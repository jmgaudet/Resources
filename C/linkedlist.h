#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


typedef struct node Node;
typedef struct list List;

List * makelist();
Node * create_node(int x);
void init_node(Node * n);
void addFirst(List * start, int x);
void addLast(List * list, int x);
void print_list(List * list);
void reverse(List * list);
void destroy_list(List * list);


#endif  // LINKEDLIST_H_
