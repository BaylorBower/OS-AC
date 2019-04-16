# Lab 1.75 Setup
## Objective ##
The objective of this lab is to create two more types of data structures `doubly_linked_list` and a `circular_buffer`. Make sure to fully test this methods and data structures in your main. 


## Doubly Linked List 
A `doubly_linked_list` is simliar to a `linked_list` from the last lab except that each node contains a pointer to its predecessor in addition to its sucessor. Towards this end here is what you must complete in this section.
+ Create a `struct` for a *doubly linked list node* that contains two entries `data` and `next`. 
	- `data` is an integer. This represents the value we are actually storing. (Note: "doubly" here refers to forwards and backwards, not the contents of what is being stored.)
	- `key` is an integer. This is used for sorting. 
	- `next` is a pointer the next element in the list. This is zero if its the last element in the list.
	- `last` is a pointer the last element in the list. This is zero if its the first element in the list.
+ Create a `struct` for a *doubly linked list* that contains one entry `head` that points to the first element of the doubly linked list. 
+ Create a method `insert_dll` that takes three parameters, a doubly linked list struct, a data integer, and a key integer. This will insert the data integer as a liked list node struct, *sorted* by the key value. If there is already an element with the associated key in the list then the value will *not* be inserted. If the value fails to be inserted for any reason, it will return a 0. If successful, this will return 1.
+ Create a method `is_in_list_dll` that takes two parameters, a doubly linked list struct and an key integer. This will return 1 if there is an element in the doubly linked list that has the associated key integer, it returns a 0 if there isn't. -1 if there is an error. (May not need to return -1 depending on how you implement it.)
+ Create a method `find_element_dll` that takes two parameters, a doubly linked list struct and an key integer. This will return the value for the associated key from the list. If the node isn't present or something goes wrong it will return a 0.
+ Create a method `remove_dll` that takes two parameters, a doubly linked list struct and an key integer. This will remove the node with the associated key from the list. If the node is removed it will return a 1. If the node isn't present or something goes wrong it will return a 0.
+ Create a method `print_dll` that takes one parameter a doubly linked list struct. This prints out a list of all of the *integer values* of the elements in the doubly linked list.  
+ Crate a method `create_array_dll` that takes one parameter a doubly linked list struct. This returns an array of all of the *integer values* of the elements in the doubly linked list. 

## Circular Buffer
A `circular_buffer` is at its heart a `doubly_linked_list` but there is no end and no beginning (*i.e.*, the successor of the last element is the first and the predecessor of the first element is the last element). Instead you keep track of a `head` and a `tail` the active part of the `circular_buffer` are the nodes between the `head` and `tail`. If you try and insert more elements than there are entries in the circular buffer, then you will get an error.

You can use the  `double_linked_list_node` you create above for this section or you can create your own struct for this section. **Note** if you do use `double_linked_list_node`, then `key` will be the same for all elements, because sorting isn't used in circular buffers. The directions below assume you make your own `circular_buffer_node` struct. 
+ Create a struct `circular_buffer` that contains
	- A size
	- An integer that contains the number of occupied slots.
	- A pointer to the head `circular_buffer_node`.
	- A pointer to the tail `circular_buffer_node`.	
+ Create a method `create_cl` that takes as a paramater the `size` of the buffer and returns a pointer to a `cicrular_buffer` with the `tail` and `head` property set to be the same `circular_buffer_node` in the list (It doesn't matter which node as long as they are the same). If `size` isn't set to be at least `1`, then this will return `1`. Otherwise, this will return `0`.
+ Create a method `push_cl` that (if space is available) will put an element at the current `head` pointer, advance `head` pointer by one node, and increment the number of occupied slots by one. This will return `0` if the node was added successfully. This will return `-1` if the `circular_buffer` is full and the element cannot be added.
+ Create a method `pop_cl` that (if there is at least one element in the buffer) will return the value of the element at the `tail`, advance the `tail` by one, and decrement the occupied slots by one. If there circular buffer contains no elements, then this will return `-1`. However, returning `-1` does not indicate failure since it's possible that `-1` was the value stored in the entry. To determine failure you must check the number of occupied slots before calling this method. 
+ Create a method `head_cl` that (if there is at least one element in the buffer) will return the value of the element at the `tail`. If there circular buffer contains no elements, then this will return `-1`. However, returning `-1` does not indicate failure since it's possible that `-1` was the value stored in the entry. To determine failure you must check the number of occupied slots before calling this method. 
