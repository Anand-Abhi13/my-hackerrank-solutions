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
   
    // Declare index
    int a_i = 0;
    int b_i = 0;
   
   // Logic 1
    while ((a.length() != 0 && b.length() != 0)){
        if (b.find(a[a_i]) == -1){
                number_needed ++;
                // Delete charecters in string
                a.erase(remove(a.begin(), a.end(), a[a_i]), a.end());
        }

        else {
            a_i ++;
        }
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
