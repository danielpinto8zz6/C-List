# C-List

### Sample
```c
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

```c
typedef struct _List {
  void **items; /** Array of pointers **/
  int size;     /** Number of elements in the array **/
  int capacity; /** Capacity of the array **/
} List;

/**
 * @brief  Inserts the specified item at the specified position in the specified
 * list
 * @note
 * @param  *list: list to be processed
 * @param  index: index at which the specified element is to be inserted
 * @param  *item: item to be inserted
 * @retval true if succeed, false otherwise
 */
// bool list_add_at(List *list, int index, void *item);

/**
 * @brief  Appends the specified item to the end of the specified list
 * @note
 * @param  *list: list to be processed
 * @param  *item: item to be appended
 * @retval true if succeed, false otherwise
 */
bool list_add(List *list, void *item);

/**
 * @brief  Removes all of the item from the specified list
 * @note
 * @param  *list: list to be processed
 * @retval None
 */
void list_clear(List *list);

/**
 * @brief  Check if the specified list contains the specified item
 * @note
 * @param  *list: list to be processed
 * @param  *item: item whose presence in this list is to be tested
 * @retval true if the list contains the specified item
 */
bool list_contains(List *list, void *item);

/**
 * @brief  Erase all elements of the specified list and free all alocated memory
 * @note
 * @param  *list: list to be processed
 * @retval None
 */
void list_destroy(List *list);

/**
 * @brief  Returns the element at the specified position in the specified list.
 * @note
 * @param  *list: list to be processed
 * @param  index: index of the item to return
 * @retval The item at the specified position in the list
 */
void *list_get(List *list, int index);

/**
 * @brief  Returns the index of the first occurrence of the specified list
 * @note
 * @param  *list: list to be processed
 * @retval  index of the first occurrence of the specified list, or -1 if the
 list does exists or contains no elements
 */
int list_index_of(List *list);

/**
 * @brief  Returns true if the specified list contains no item
 * @note
 * @param  *list: list to be processed
 * @retval true if the list contains no item
 */
bool list_is_empty(List *list);

/**
 * @brief  Returns the index of the last occurrence of the specified list
 * @note
 * @param  *list: list to be processed
 * @retval  index of the last occurrence of the specified list, or -1 if the
 list does exists or contains no elements
 */
int list_last_index_of(List *list);

/**
 * @brief  Initialize a new list
 * @note
 * @retval the list initialized
 */
List *list_new();

/**
 * @brief  Removes the item at the specified position in the specified list.
 Shifts any subsequent item to the left (subtracts one from their indices)
 * @note
 * @param  *list: list to be processed
 * @param  index: the index of the item to be removed
 * @retval true if succeed, false otherwise
 */
bool list_remove(List *list, int index);

/**
 * @brief  Change the capacity of the list, allocates memory if necessary
 * @note
 * @param  *list: list to be processed
 * @param  size: number of elements that can be stored in the list
 * @retval true reallocation succeed or if there is enought space
 */
bool list_resize(List *list, int capacity);

/**
 * @brief  Replaces the item at the specified position in the specified list
 * with the specified item
 * @note
 * @param  *list: list to be processed
 * @param  index: index of the item to replace
 * @param  *item: item to be stored at the specified position
 * @retval true if succeed, false otherwise
 */
bool list_set(List *list, int index, void *item);

/**
 * @brief  Returns the number of elements in the specified list
 * @note
 * @param  *list: list to be processed
 * @retval number of elements in the list
 */
int list_size(List *list);
#endif
```
