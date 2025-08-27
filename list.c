/**
 * Linked Lists
 * 
 */
#include <stdlib.h>
#include <stdio.h>

struct Node 
{
  int data;
  struct Node *next;
};

typedef struct Node node_t;

void insert(node_t node, int pos);
void print(node_t *head);


void main()
{
  node_t n1, n2, n3;
  node_t *head = NULL;

  n1.data = 1;
  n2.data = 2;
  n3.data = 3;

  head = &n1;
  n1.next = &n2;
  n2.next = &n3;
  n3.next = NULL;

  print(head);
}

void print(node_t *head)
{
  node_t *temp = head;
  while (temp != NULL)
  {
    printf("%d\n", temp->data);
    temp = temp->next;
  }
}

void insert(node_t node, int pos)
{
  node_t temp;
  
}
