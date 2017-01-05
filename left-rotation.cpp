// Arrays: Left Rotation
// Link to problem: https://www.hackerrank.com/challenges/ctci-array-left-rotation

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

vector<int> array_left_rotation(vector<int> a, int n, int k) {

    for(int j = 0; j < k ; j++){
        
        int i = 0;
        int n_ele = a[0];
        
        while(i != n){
            a[i] = a[i + 1];
            i++;   
        }
        a[n - 1] = n_ele;
    }
    //print a[((n - k) + i)%n] 
    return a;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}

