# C-List

### Sample
```
  List *list = list_new();

  list_add(list, "one");
  list_add(list, "two");
  list_add(list, "tree");
  list_add(list, "four");
  list_add(list, "five");

  for (int i = 0; i < list_size(list); i++)
    printf("%s \n", (const char *)list_get(list, i));
  printf("\n");

  list_remove(list, 3);
  list_remove(list, 2);
  list_remove(list, 1);

  list_set(list, 0, "Set used here");

  list_add_at(list, 1, "Add at used here");

  for (int i = 0; i < list_size(list); i++)
    printf("%s \n", (const char *)list_get(list, i));
  printf("\n");

  list_destroy(list);
```
