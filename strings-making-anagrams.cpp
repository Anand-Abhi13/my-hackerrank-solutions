// Problem: Strings: Making Anagrams
// Link: https://www.hackerrank.com/challenges/ctci-making-anagrams

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int number_needed(string a, string b) {
   // Sort strings
   // Delete from end till strings match
   
   //Sort strings a and b
   sort(a.begin(), a.end());
   sort(b.begin(), b.end());

    //Search charecters
    int result = a.find("d");
    cout <<" search_result = " << result; 
   
   // Delete charecters in string
   while ((a.length() != 0 && b.length() != 0)){
        a.erase(remove(a.begin(), a.end(), char_to_delete), a.end());
   }
   
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
