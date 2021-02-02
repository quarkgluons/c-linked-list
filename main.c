#include <stdio.h>

#include "list.h"

int main() {

  node *head = NULL;

  for (int i = 0; i < 10; i++) {

    head = add_head(head, i);

    traverse_list(head);
    printf("\n");
  }

  for (int i = 0; i < 10; i+=2) {
    head = delete_node(head, i);
    traverse_list(head);
    printf("\n");
  }

  for (int i = 1; i < 10; i += 2) {
    head = delete_node(head, i);
    traverse_list(head);
    printf("\n");
  }

  free(head);

  return 0;
}
