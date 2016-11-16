// You are given a Directed Acyclic Graph (DAG) with vertices and edges. Each vertex has an integer, a[v], associated with it and the initial value of a[v] is 0 for all vertices. You must perform q queries on the DAG, where each query is one of the following types:
//
//     1 u x: Set to for all such that there is a path in the DAG from to .
//     2 u x: Set to for all such that there is a path from to and .
//     3 u: Print the value of on a new line.
//
// Input Format
//
//  The first line contains three space-separated integers describing the respective values of n(the number of vertices in the DAG), m(the number of edges in the DAG), and q(the number of queries to perform).
// Each of the m subsequent lines contains two space-separated integers describing the respective values of u and  v (where 1 <= u,v <= n, u!= v ) denoting a directed edge from vertex u to vertex v in the graph.
//             Each of the subsequent lines contains a query in one of the three formats described above.
//
// Constraints
//    2 <= n <= 10^5
//    1 <= m,q <= 10^5
//    0 <= x <= 10^9
//    0 <=  a[v] <= 10^9
//                 It's guaranteed that the graph is acyclic, but there may be more than one edge connecting two nodes.
//
//                 Output Format
//
//                 For each query of type (i.e., 3 u), print the value of on a new line.
//   Sample input
//   6 5 18
//   1 2
//   1 3
//   3 4
//   2 4
//   5 6
//   1 1 3
//   3 1
//   3 2
//   3 3
//   3 4
//   1 2 2
//   3 1
//   3 2
//   3 3
//   3 4
//   2 6 7
//   3 5
//   3 6
//   2 1 3
//   3 1
//   3 2
//   3 3
//   3 4
//
//   Sample Output
//   3
//   3
//   3
//   3
//   3
//   2
//   3
//   2
//   0
//   0
//   3
//   2
//   3
//   2
//
//   Explanation
//   The diagram below depicts the changes to the graph after all type and type queries:
//  Initial Graph [a1=0] -> [a2=0],  [a1=0] -> [a3=0], [a2=0] -> [a4=0],  [a3=0] -> [a4=0], [a5=0] -> [a6=0]
//   Query 1 [a1=3] -> [a2=3],  [a1=3] -> [a3=3], [a2=3] -> [a4=3],  [a3=3] -> [a4=3], [a5=0] -> [a6=0] {all values in path changed to 3}
//   Query 6 [a1=3] -> [a2=2],  [a1=3] -> [a3=3], [a2=2] -> [a4=2],  [a3=3] -> [a4=2], [a5=0] -> [a6=0] {all values in path changed to 2}
//   Query 11 [a1=3] -> [a2=2],  [a1=3] -> [a3=3], [a2=2] -> [a4=2],  [a3=3] -> [a4=2], [a5=0] -> [a6=0] {No chanbge as no value s are > 7}
//   Query 14 [a1=3] -> [a2=2],  [a1=3] -> [a3=3], [a2=2] -> [a4=2],  [a3=3] -> [a4=2], [a5=0] -> [a6=0] {No chanbge as no value s are > 3}
