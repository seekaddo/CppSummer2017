/* =============================================================================== */
/* CPP Programming (Summer2017)                                                    */
/* Created by Addo Dennis on 13/07/2017.                                           */
/* =============================================================================== */
/* Little playground with CPP. Question from Hackerrank.com                        */
/*                                                                                 */
/* Tested with g++ 6.3.0 , You can use clang++                                     */
/* =============================================================================== */
/* Author: Dennis Addo                                                             */
/* =============================================================================== */

/*\brief
 *
 * Input Format
 
 The first line contains two space-separated integers denoting the respective values of
 (the number of variable-length arrays) and  (the number of queries).
 Each line  of the  subsequent lines contains a space-separated sequence in the format k a[i]0 a[i]1 …
 a[i]k-1 describing the -element array located at .
 Each of the  subsequent lines contains two space-separated integers describing the respective values of
 (an index in array ) and  (an index in the array referenced by ) for a query.
 
 Constraints
 
 All indices in this challenge are zero-based.
 All the given numbers are non negative and are not greater than
 Output Format
 
 For each pair of  and  values (i.e., for each query), print a single integer denoting
 the element located at index of the array referenced by . There should be a total of  lines of output.
 
 Sample Input
 
 2 2
 3 1 5 4
 5 1 2 8 9 3
 0 1
 1 3
 Sample Output
 
 5
 9
 
 *
 * */


#include <cmath>
#include <vector>
#include <iostream>
using namespace std;


int main(void) {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n, nq ,s , v ;
    cin >> n >> nq;
    
    vector<vector<int>> vla;
    for(int i = 0; i < n; i++){
        cin >> s;
        vla.emplace_back(s); //avoids the extra copy or move operation required when using push_back.
        for(int a =0; a < s; a++){
            cin >> vla[i][a];
        }
    }
    
    
    for(int i = 0; i <nq; i++){
        cin >> s >> v;
        cout << vla[s][v] <<endl;
    }
    return 0;
}
