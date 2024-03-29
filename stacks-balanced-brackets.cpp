// Stacks: Balanced Brackets
nclude <map>
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

// Logic #1
// Passed: 19; Failed: None; Segmentation Fault: None
bool is_balanced(string expression) {
  
    std::stack<char> check;
    
    for(auto c : expression){
        if(c == '{' || c == '(' || c == '[')
            check.push(c);
        
        else{
            if(check.empty()){return false;}
            
            if((c == '}' && check.top() == '{')||
               (c == ')' && check.top() == '(')||
               (c == ']' && check.top() == '['))
                    check.pop();
            }
    }   
    return (check.empty());
    
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

