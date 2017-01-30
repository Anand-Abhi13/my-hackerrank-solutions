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
// Logic 2
// Passed: 8; Failed: 12; Runtime Error: None  

bool ransom_note(vector<string> magazine, vector<string> ransom) {     
    // Save in map;
    map <string, int> magazine_map;
    for(auto m_note : magazine)
        magazine_map[m_note] += 1;
    
    // If value not present in dict; return false
    // If repeated words; Reduce count by 1
    for (const auto &r_note : ransom)
        if(magazine_map[r_note] == 0) return false;
	else magazine_map[r_note] --;

    // If value exits returns true
    return true;
    
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
