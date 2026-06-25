#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for(int i = 0 ; i<queries.size(); i++){
        int arrIndexOne = queries[i][0];
        int arrIndexTwo = queries[i][1];
        swap(arr[arrIndexOne], arr[arrIndexTwo]);
        return arr;
    }  
}