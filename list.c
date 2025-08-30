// Singly-Linked List

#include <stdlib.h>
#include <stdio.h>

struct Node 
{
  int data;
  struct Node *next;
};

typedef struct Node node_t;

void print(node_t *head);
node_t *create(int data);
void *insert_at_head(node_t **head, node_t *newNode);
node_t *find_node(node_t *head, int data);
void *insert_in_middle(node_t *oldNode, node_t *newNode);
void *remove_node(node_t **head, node_t *oldNode);

void main()
{
  node_t *head = NULL;
  node_t *temp;

  for (size_t i = 0; i < 10; i++)
  {
    temp = create(i);
    insert_at_head(&head, temp);
  }

  printf("Before insert:\t");
  print(head);
  
  // After insert
  temp = find_node(head, 4);  
  insert_in_middle(temp, create(4));
  printf("\nAfter insert:\t");
  print(head);
  
  // After remove
  remove_node(&head, temp);
  printf("\nAfter remove:\t");
  print(head);
  printf("\n");
}

void print(node_t *head)
{
  node_t *temp = head;
  while (temp != NULL)
  {
    printf("%d\t", temp->data);
    temp = temp->next;
  }
}

node_t *create(int data)
{
  node_t *newNode = malloc(sizeof(node_t));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void *insert_at_head(node_t **head, node_t *newNode)
{
  newNode->next = *head;
  *head = newNode;
}

node_t *find_node(node_t *head, int data)
{
  node_t *temp = head;
  while (temp != NULL)
  {
    if(temp->data == data)
    {
      return temp;
    }
    temp = temp->next;
  }
}

void *insert_in_middle(node_t *oldNode, node_t *newNode)
{
  newNode->next = oldNode->next;
  oldNode->next = newNode;
}

void *remove_node(node_t **head, node_t *oldNode)
{
  if (*head == oldNode)
  {
    *head = oldNode->next;
  }
  else
  {
    node_t *temp = *head;
    while (temp != NULL && temp->next!=oldNode)
    {
      temp = temp->next;
    }

    if (temp == NULL)
    {
      return;
    }

    temp->next = oldNode->next;
    oldNode->next = NULL;
  }
}
