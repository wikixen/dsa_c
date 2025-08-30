// Doubly-Linked List
#include <stdlib.h>
#include <stdio.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

typedef struct Node node_t;

void print(node_t *head);
node_t *create(int data);
void *insert(node_t **head, node_t *newNode);

void main()
{
  node_t *head = NULL;
  node_t *temp;

  for (size_t i = 0; i < 10; i++)
  {
    temp = create(i);
    insert(&head, temp);
  }

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

node_t *create(int data)
{
  node_t *newNode = malloc(sizeof(node_t));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

void *insert(node_t **head, node_t *newNode)
{
  newNode->next = *head;
  newNode->prev = 
  *head = newNode;
}
