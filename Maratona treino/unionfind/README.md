# Union-Find

Disjoint set is a data structure that folds a set in disjoint (non-overlapping) subsets. This data structure can be used to implement a Union-Find, that performs basically these two operations:
 - Union: Join of subsets
 - Find: Fetch of subset of a element

### Use case

The most remarkable use of a union-find is to check if a graph contains a cycle, useful in the Kruskal algorithm.

### Model

A simple model can capture the essence of the methods:
 - Objects (entity): 
> 0 1 2 3 4 5 6 7 8 9
 - Disjoint set (subset of entities):
> 0 1 { 2 3 9 } { 5 6 } 7 { 4 8 }
 - Find (query(2, 9) -> true):
> 0 1 { 2 3 9 } { 5 6 } 7 { 4 8 }
 - Union (merge(3, 8)):
> 0 1 { 2 3 4 8 9 } { 5 6 } 7

### Implementations

Here will be listed the known implementations. They will not be explained, since the exercise is to try to develop them. For further explanation, use the reference.

 - Quick-find
 - Quick-union
 - Path compression (use of heap)
 
### References
* https://www.cs.princeton.edu/~rs/AlgsDS07/01UnionFind.pdf
