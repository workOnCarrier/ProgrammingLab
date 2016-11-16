//Consider the following game:
//
//There are two players, First and Second, sitting in front of a pile of  stones. First always plays first.
//There is a set,'S' , of m distinct integers defined as S={s0, s1, ... ,sm-1}.
//The players move in alternating turns. During each turn, a player chooses some si belonging to S and splits one of the piles into exactly si smaller piles of equal size. If no  si exists, that will split one of the available piles into exactly si equal smaller piles, the player loses.
//Both players always play optimally.
//Given n, m, and the contents of S, find and print the winner of the game. If First wins, print First; otherwise, print Second.
//
//Input Format
//
//The first line contains two space-separated integers describing the respective values of n (the size of the initial pile) and m (the size of the set). 
//The second line contains  distinct space-separated integers describing the respective values of s0, s1, s2, ... , sm-1.
//
//Constraints
// 1 <= n <= 10^18
// 1 <= m <= 10
// 2 <= si <= 10^18
//Output Format
//
//Print First if the First player wins the game; otherwise, print Second.
//
//Sample Input
//15 3
//5 2 3
//Sample Output
//Second
//Explanation
//
//The initial pile has n=15 stones, and S={5,2,3}. During First's initial turn, they have two options:
//
//Split the initial pile into 5  equal piles, which forces them to lose after the following sequence of turns: 
// [15] -I-> (5[3]) -II-> (3[1],4[3]) -I-> (6[1],3[3]) -II-> (9[1],2[3]) -I-> (12[1],1[3]) -II-> (15[1]) -I-> looses
//Split the initial pile into 3 equal piles, which forces them to lose after the following sequence of turns: 
// [15] -I-> (3[5]) -II-> (5[1],2[5]) -I-> (10[1],1[5]) -II-> (15[1]) -I-> looses
//Because First never has any possible move that puts them on the path to winning, we print Second as our answer.
