#include "list.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

bool list_add(List *list, void *item) {
  if (list == NULL) {
    return false;
  }

  if (list->capacity == list->size)
    if (!list_resize(list, list->capacity * 2))
      return false;

  list->items[list->size++] = item;

  return true;
}

bool list_add_at(List *list, int index, void *item) {
  if (list == NULL || index < 0 || index > list->size) {
    return false;
  }

  if (list->capacity == list->size)
    if (!list_resize(list, list->capacity * 2))
      return false;

  for (int i = list->size; i > index; i--) {
    list->items[i] = list->items[i - 1];
  }

  list->items[index] = item;
  list->size++;

  return true;
}

void list_clear(List *list) {
  if (list == NULL) {
    return;
  }
  free(list->items);
  list->size = 0;
  list->capacity = LIST_INIT_CAPACITY;
  list->items = malloc(sizeof(void *) * list->capacity);
}

bool list_contains(List *list, void *item) {
  for (int i = 0; i < list_size(list); i++) {
    const void *tmp = list_get(list, i);
    if (item == tmp) {
      return true;
    }
  }
  return false;
}

void list_destroy(List *list) {
  if (list != NULL) {
    if (list->items != NULL) {
      free(list->items);
    }
    free(list);
  }
}

void *list_get(List *list, int index) {
  return (list != NULL && list->size > 0 && index < list->size && index >= 0)
             ? list->items[index]
             : NULL;
}

int list_index_of(List *list) {
  return (list != NULL && list->size > 0) ? 0 : -1;
}

bool list_is_empty(List *list) {
  return (list != NULL && list->size > 0) ? false : true;
}

int list_last_index_of(List *list) {
  return (list != NULL && list->size > 0) ? (list->size - 1) : -1;
}

List *list_new() {
  List *list = malloc(sizeof(struct _List));
  if (list != NULL) {
    list->size = 0;
    list->capacity = LIST_INIT_CAPACITY;
    list->items = malloc(sizeof(void *) * list->capacity);
  }
  return list;
}

bool list_remove(List *list, int index) {
  if (list == NULL || index < 0 || index >= list->size)
    return false;

  for (int i = index; i < list->size - 1; i++) {
    list->items[i] = list->items[i + 1];
  }

  list->size--;

  if (list->size > 0 && list->size == list->capacity / 4)
    list_resize(list, list->capacity / 2);

  return true;
}

bool list_resize(List *list, int capacity) {
  if (list == NULL) {
    return false;
  }

  void *tmp = realloc(list->items, sizeof(void *) * capacity);

  if (tmp == NULL) {
    return false;
  }

  list->items = tmp;
  list->capacity = capacity;

  return true;
}

bool list_set(List *list, int index, void *item) {
  if (list == NULL || index < 0 || index >= list->size) {
    return false;
  }

  list->items[index] = item;
  return true;
}

int list_size(List *list) { return (list != NULL) ? list->size : -1; }
