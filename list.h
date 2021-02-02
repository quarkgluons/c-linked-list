#include <stdlib.h>
#include <stdio.h>

typedef struct node {
  int data;
  struct node * next;
} node;

node * create_node(int data) {
  node * p = (node *)malloc(sizeof(node));

  return p;
}

node * add_head(node * head, int data) {
  if (head == NULL) return create_node(data);

  node * p = create_node(data);
  p->data = data;
  p->next = head;

  return p;
}

void  traverse_list(node * head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
}

node * delete_node(node *head, int data) {
  if (head == NULL) {
    return NULL;
  }
  if (head->data == data) {
    node * temp = head;
    head = head->next;
    free(temp);
    return head;
  }
  node * forward_ptr = head->next;
  node *back_ptr = head;
  while (forward_ptr != NULL) {
    if (forward_ptr->data == data) {
      back_ptr->next = forward_ptr->next;
      free(forward_ptr);
      return head;
    }
    back_ptr = forward_ptr;
    forward_ptr = forward_ptr->next;
  }

  return head;
}

void free_list(node *head) {

  while(head != NULL) {
    node *temp = head;
    head = head->next;
    free(temp);
  }
}
