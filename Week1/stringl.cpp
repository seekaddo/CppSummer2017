/* =============================================================================== */
/* CPP Programming (Summer2017)                                                    */
/* Created by Addo Dennis on 05/07/2017.                                           */
/* =============================================================================== */
/* Little playground with CPP. Is all mixture                                      */
/*                                                                                 */
/* Tested with g++ 6.3.0 , You can use clang++                                     */
/* =============================================================================== */
/* Author: Dennis Addo                                                             */
/* =============================================================================== */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::string;


bool is_palindrome(const string& str){

    return std::equal(str.begin(),str.begin()+str.size()/2,str.rbegin());  //remove_copy_if remove_copy
}

bool evenNum(const int &s){
    return (s %2 == 0);
}

bool smallnum(const int& s){
    return s > 5;
}




int main() {


    string s = "eye";

    cout << "The string: "+ s + (is_palindrome(s)?" is a palindrome":" is not palindrome") << '\n' <<endl;


    //std::vector<string> words = {"food","girls", "cat","dogs","mi","ku","y"};
    std::vector<int> nums = {3,4,6,7,8,2,9,13,45,87};
    std::sort(nums.begin(),nums.end(),std::less<int>());  // sort with smaller first

    //std::remove_copy_if(words.begin(),words.end(),words.begin(),evenNum);

    //returns a pointer to the last olds / false predicate
    std::vector<int>::iterator rel = std::stable_partition(nums.begin(), nums.end(), evenNum);

    for (std::vector<int>::iterator i = nums.begin(); i != nums.end() ; ++i) {
        cout << *i <<endl;
    }

    //extract from the old bis the end of the whole nums
    std::vector<int> olds(rel,nums.end());

    //remove from the old pointer to the end
    nums.erase(rel,nums.end());

    cout << "old nums: " <<endl;
    for (std::vector<int>::iterator i = olds.begin(); i != olds.end() ; ++i) {
        cout << *i <<endl;
    }



    cout << "After removing olds numbers" <<endl;
    for (std::vector<int>::iterator i = nums.begin(); i != nums.end() ; ++i) {
        cout << *i <<endl;
    }


    std::vector<int> n = {3,4,6,7,8,2,9,13,45,87};
    std::vector<int> b;


    std::remove_copy_if(n.begin(),n.end(),back_inserter(b),smallnum); // don't store return value if you use back_inserter


    cout << "big numbers" <<endl;
    for (std::vector<int>::iterator i = b.begin(); i != b.end() ; ++i) {
        cout << *i <<' ';
    }

    cout <<endl;


    return 0;
}


