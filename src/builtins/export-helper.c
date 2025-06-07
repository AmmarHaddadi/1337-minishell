#include "../main.h"

void bubble_sort_shellvars(t_shellvar *head) {
	if (!head)
		return;

	int swapped = 1;
	t_shellvar *ptr;
	t_shellvar *last = NULL;

	while (swapped) {
		swapped = 0;
		ptr = head;

		while (ptr->next != last) {
			if (my_strcmp(ptr->key, ptr->next->key) > 0) {
				// Swap the contents of the two nodes
				char *tmp_key = ptr->key;
				char *tmp_val = ptr->value;
				bool tmp_exp = ptr->exported;

				ptr->key = ptr->next->key;
				ptr->value = ptr->next->value;
				ptr->exported = ptr->next->exported;

				ptr->next->key = tmp_key;
				ptr->next->value = tmp_val;
				ptr->next->exported = tmp_exp;

				swapped = 1;
			}
			ptr = ptr->next;
		}

		last = ptr; // each pass puts the largest item at the end
	}
}

