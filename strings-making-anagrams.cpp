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

//Logic 2
int number_needed(string a, string b) {
    int number_needed = 0;
    vector<int> freq (26, 0); // Create a vector with 26 values all set to 0
    
    //Complexity: O(N)
    for(auto ch : a) ++freq[ch - 'a']; //ch - 'a' evaluates -> ascii code(ch) - 97
    for(auto ch : b) --freq[ch - 'a']; // This loops accounts for charecters that exists in both strings
    
    //The sum of absolute values in freq evalutates to the number needed 
    for(auto fq : freq)number_needed += abs(fq);
        
    return number_needed;
    
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
