# Readme push_swap

This project has been created as part of the 42 curriculum by mschappe, ldauber

## Description

This project is supposed to sort a stack with 4 different algorithm using 2 stacks, one (**a**) ****who is fill with a random amount of negative and/or positive numbers without any duplicate, and the other (**b**) must be empty.

## Instruction

### Operations :

The stack must be sorted using only given operations :

**sa** : Swap the first two elements at the top of stack a.
**sb** : Swap the first two elements at the top of stack b.
**ss** : sa and sb at the same time.
**pa** : Take the first element at the top of b and put it at the top of a.
**pb** : Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
**ra** : Shift up all elements of stack a by one. The first element becomes the last one.
**rb** : Shift up all elements of stack b by one. The first element becomes the last one.
**rr** : ra and rb at the same time.
**rra** : Shift down all elements of stack a by one. The last element becomes the first one.
**rrb** : Shift down all elements of stack b by one. The last element becomes the first one.
**rrr** : rra and rrb at the same time.

None of this command will be executing if the stack they trying to modifies are empty.

### Algorithms :

We must implement four distinct sorting strategies. Our program must be able to select a strategy at runtime based on the input configuration.

The four different algorithm must be able to generate a sequence of operation that sorted the stack and print it on the standard output.

The are the fourth algorithm we decided to implement and their internal technique:

- Simple algorithm : Insertions sort adaptation, this is a simple sorting algorithm that works by iteratively inserting each element of stack **a** into its decreasing position in the stack **b**. Then push back sorted in increasing order in the stack **a**.
- Medium algorithm : Bucket sort adaptation, this is a sorting technique that involves dividing elements into various buckets. These buckets are formed by uniformly distributing the elements. Once they’re divided into buckets, they can be sorted using any other sorting algorithm. Finally, the sorted elements are gathered together in an ordered fashion.
- Complex algorithm : Radix sort adaptation, This is a linear sorting algorithm (for fixed length digit counts) that sorts elements by processing them digit by digit. It is an efficient sorting algorithm for integers or strings with fixed-size keys.
- The fourth algorithm is an adaptive strategy created by us depending on the measured disorder we will see later.

The final objective is to reflect the cost measured in numbered of operations generated when we state a complexity class, not the theoretical complexity of a classical array-based algorithm.

### Disorder :

Disorder is a number between 0 and 1 that telling us how far the initial stack if from being sorted

If the numbers are already in the right order, disorder must be 0. If it is in the worst order possible, disorder must be 1.

To calculate this, we used an adaptation of the following function in Python given in the subject : 

function compute_disorder(stack a):
    mistakes = 0
    total_pairs = 0
    for i from 0 to size(a)-1:
        for j from i+1 to size(a)-1:
            total_pairs += 1
            if a[i] > a[j]:
                mistakes += 1
    return mistakes / total_pairs

In the adaptive algorithm, we have to select which algorithm we’re gonna use with the disorder according to the following rules:

- Low disorder: if disorder < 0.2, your chosen method must run in O(n²) time.
- Medium disorder: if 0.2 ≤ disorder < 0.5, your chosen method must run in
O(n√n) time.
- High disorder: if disorder ≥ 0.5, your chosen method must run in O(n log n)
time.

### Validation :

To validate this project, you must achieve certain performance targets with a minimal
number of operations:
- For 100 random numbers, your program should use:
         ◦ Less than 2000 operations to pass (minimum requirement)
         ◦ Less than 1500 operations for good performance
         ◦ Less than 700 operations for excellent performance
• For 500 random numbers, your program should use:
         ◦ Less than 12000 operations to pass (minimum requirement)
         ◦ Less than 8000 operations for good performance
         ◦ Less than 5500 operations for excellent performance

## Resources
https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/

https://www.geeksforgeeks.org/dsa/bucket-sort-2/

https://fr.wikipedia.org/wiki/Tri_par_paquets

https://fr.wikipedia.org/wiki/Tri_par_base

http://www.giacomazzi.fr/infor/Tri/TRadix.htm

https://en.wikipedia.org/wiki/Radix_sort