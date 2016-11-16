// Given 'n' strictly convex simple polygons and 'm' ellipses on a plane, find any point lying in their intersection. Then print two lines of output, where the first line contains the point's 'x' coordinate and the second line contains its 'y' coordinate. The point lying on the boundary of an ellipse or polygon is considered to be an inner point.
//
// Input Format
//
// The first line contains an integer, 'n' , denoting the number of polygons.
// The next set of lines defines 'n' polygons, where each polygon 'i' is described as follows:
//
//     The first line contains an integer, 'v[i]', denoting the number of vertices in polygon 'i'.
//         Each of the 'v[i]' subsequent lines contains two space-separated integers denoting the respective 'x' and 'y' coordinates for one of polygon i's vertices. The list of vertices is given in counterclockwise order.
//
//         The next line contains an integer, 'm', denoting the number of ellipses.
//         Each of the m subsequent lines contains five space-separated integers denoting the respective values of x1, y1, x2, y2, and 'a', which are the coordinates of the four focal points and the semi-major-axis for an Ellipse.
//
//         Constraints
//      1 <= n <= 500
//      3 <= v[i] <= 1500
//      3 <= sum(v[i], i between 0, n-1) <= 1500
//      1 <= m <= 1500
//      coordinates of points are integers in the inclusive range [ -10^4, 10^4]
//      All semi major axes are integers <= 10^4
//      It is guaranteed that a solution exists
//      THe challenge has binary scoring
//
// Output Format
//      Print two lines describing an (x,y) point inside the intersection. The first line must be a real number denoting the point's 'x' coordinate, and the second line must be a real number denoting its 'y' coordinate. Your answer is considered to be correct if there is a point, (x0, y0), inside the intersection such that the distance between (x,y) and (x0, y0) is at most 10^4.
//
//                         Sample Input
//
//                         2
//                         4
//                         0 0
//                         2 0
//                         2 1
//                         0 1
//                         3
//                         -1 -1
//                         5 1
//                         0 5
//                         1
//                         1 2 1 4 2
//
//                         Sample Output
//
//                         0.999998
//                         1
//
// Explanation
//     The intersection consists of only one point: (1,1). As its distance to (0.999998,1) is <= 10^4, this is a correct answer. Thus, we print the x coordinate, 0.999998, on the first line and the y coordinate, 1, on the second line.
