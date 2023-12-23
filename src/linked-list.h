#ifndef LINKEDLISTDT

#define LINKEDLISTDT

/**
 * @brief Represents a single node in a linked list.
 * @members
 *   * `value`: The integer value stored in the node.
 *   * `next`: A pointer to the next node in the list, or NULL if it's the tail.
 */
typedef struct node
{
    int value;
    struct node *next;
} node;

/**
 * @brief Represents a linked list of nodes.
 * @members
 *   * `head`: A pointer to the first node in the list, or NULL if the list is empty.
 *   * `tail`: A pointer to the last node in the list, or NULL if the list is empty.
 *   * `length`: The number of nodes in the list.
 */
typedef struct list
{
    node *head;
    node *tail;
    int length;
} list;


/**
 * @return A pointer to a newly allocated `list` struct, or NULL on failure.
 * @details This function dynamically allocates memory for a new `list` struct using `malloc` and initializes it to represent an empty list.
 *          The `head` and `tail` pointers are set to NULL, indicating that no elements are currently present. The `length` field is set to 0.
 * @return values
 *   * `list*`: a pointer to the newly allocated and initialized `list` struct.
 *   * `NULL`: if memory allocation for the `list` struct fails.
 * @notes
 *   * The returned list must be freed using `list_clear()` function then `free(list)` when it is no longer needed to avoid memory leaks.
 */
list *init_list(); 

/**
 * @brief Creates a new node with the given value.
 * @param value The integer value to store in the node.
 * @return A pointer to the newly created node, or NULL on failure.
 * @details This function dynamically allocates memory for a new `node` struct using `malloc` and initializes its fields.
 *          The `value` field is set to the provided `value`, and the `next` pointer is set to NULL, indicating that it's the end of the list.
 * @return values
 *   * `node*`: a pointer to the newly allocated and initialized `node` struct.
 *   * `NULL`: if memory allocation for the `node` struct fails.
 */
node *create_node(int value); 

/**
 * @brief Finds a node with the given value in the list.
 * @param list The list to search.
 * @param value The value to search for.
 * @return A pointer to the found node, or NULL if the value is not found.
 * @details This function iterates through the list, starting from the head, and compares the value of each node with the provided `value`.
 *          It returns a pointer to the first node that matches the value, or NULL if no such node is found.
 * @return values
 *   * `node*`: a pointer to the found node with the matching `value`.
 *   * `NULL`: if the value is not found in the list.
 */
node *list_find(list *list, int value); 

/**
 * @brief Finds the node before a given value in the list.
 * @param list The list to search.
 * @param value The value to search for.
 * @return A pointer to the node before the given value, or NULL if the value is not found or is at the head of the list.
 * @details This function iterates through the list, starting from the head, and compares the value of the next node with the provided `value`.
 *          It returns a pointer to the node that precedes the node with the matching value, or NULL if no such node is found (either because the value is not in the list or it's at the head).
 * @return values
 *   * `node*`: a pointer to the node before the node with the matching `value`.
 *   * `NULL`: if the value is not found in the list, or if it's at the head.
 */
node *list_before(list *list, int value); 

/**
 * @brief Prints the values within square brackets, separated by commas.
 *        Handles empty lists correctly.
 * @param list The list to print.
 * @return 1 if printing is successful, 0 if there's an error.
 */
int list_print(list *list);

/**
 * @brief Clears the list, freeing all nodes and their memory.
 * @param list The list to be cleared.
 * @return 1 on success, 0 on failure.
 * @details Iterates through the list, detaching and freeing each node.
 *          Updates the head and tail pointers as needed. Resets `length` to 0.
 * @notes Free the entire list using `free(list)` to avoid leaks.
 */
int list_clear(list *list); 

/**
 *  @brief Removes the first element from a list.
 *  @param list Pointer to the list.
 *  @return 1 if an element was popped, 0 otherwise.
 *  @details This function removes the first element from the list by updating the head pointer and freeing the memory used by the removed element. The length of the list is also decremented.
*/
int list_popstart(list *list);

/**
 * @brief Removes the last node and frees its memory.
 * @param list The list to modify.
 * @return 1 if successful, 0 if empty.
 * @details
 *   - Finds the node before the tail.
 *   - Detaches and frees the tail.
 *   - Updates tail pointer and length.
 */
int list_popend(list *list); 

/**
 * Removes the first node with the given value, freeing its memory.
 * @param list The list to modify.
 * @param value The value to search for and remove.
 * @return 1 if successful, 0 if value not found or list is empty.
 * @details
 *  - Checks for empty list.
 *  - Finds the node before the one to remove or remove head if target is head.
 *  - Detaches the target node and updates pointers.
 *  - Frees the node's memory and decrements list length.
 */
int list_remove(list *list, int value); 

/**
 * @brief Adds a new node with a value to the start of the list.
 * @param list The list to modify.
 * @param value The value to store in the new node.
 * @return 1 if successful, 0 if value already exists or memory fails.
 * @details
 *   - Checks for duplicates and creates the new node.
 *   - Links the new node to the head and updates pointers.
 *   - Increments length.
 */
int list_pushstart(list *list, int value); 

/**
 * @brief Adds a new node to the end of the list.
 * @param list The list to modify.
 * @param value The value to store in the node.
 * @return 1 if successful, 0 if value exists or memory fails.
 * @details
 *  - Handles empty lists efficiently.
 *  - Checks for duplicates.
 *  - Links the new node to the tail.
 *  - Updates length.
 */
int list_pushend(list *list, int value); 

/**
 * @brief Inserts a new node after a specific value in the list.
 * @param list The list to modify.
 * @param value The value to store in the new node.
 * @param valueBefore The value to insert after.
 * @return 1 if successful, 0 if errors occur.
 * @details
 *   - Handles empty lists and edge cases.
 *   - Checks for duplicates.
 *   - Finds the correct position and inserts the new node.
 *   - Updates length.
 */
int list_insert_after(list *list, int value, int valueBefore); 

/**
 * @brief Inserts a new node before a specific value in the list.
 * @param list The list to modify.
 * @param value The value to store in the new node.
 * @param valueAfter The value to insert before.
 * @return 1 if successful, 0 if errors occur.
 * @details
 *   - Handles duplicates and empty lists.
 *   - Optimizes for inserting before the head.
 *   - Finds the correct position and inserts the node.
 *   - Updates length.
 */
int list_insert_before(list *list, int value, int valueAfter); 

/**
 * @brief Replaces the first occurrence of a value with a new value.
 * @param list The list to modify.
 * @param oldvalue The value to replace.
 * @param newvalue The new value to insert.
 * @return 1 if successful, 0 if the value is not found or the list is empty.
 * @details
 *   - Checks for an empty list.
 *   - If found, updates the node's value with the new value.
 */
int list_replace(list *list, int oldvalue, int newvalue); 

/**
 * @brief Sorts the list in ascending order using a bubble sort algorithm by swapping node values.
 * @param list The list to sort.
 * @return 1 if successful, 0 if empty or already sorted.
 * @details
 *   - Uses a nested loop approach for comparisons and swaps.
 *   - Iterates through the list multiple times until no swaps occur.
 *   - Swaps adjacent nodes if they are out of order.
 *   - Time complexity: O(n^2) in the worst and average cases.
 */
int list_sort(list *list);

#endif