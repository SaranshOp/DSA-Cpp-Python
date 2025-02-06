 #include <iostream> 
 using namespace std; 
 #include <bits/stdc++.h> 


vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{ 
    int  col = 0;
    vector<int> ans;

while(col < mCols){
    if(col%2 == 0){
      for (int row = 0; row < nRows; row++) {
            ans.push_back(arr[row][col]);
        }
    }
    else{ 
        for(int row = nRows - 1 ; row >= 0; row-- ){
            ans.push_back(arr[row][col]);
        }
    }
    col++;

    }
    return ans;
}
 
 
 int main(){ 
//    test case
//   2
// 3 4
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 4 4
// 1 2 4 5
// 3 6 8 10
// 11 12 13 15
// 16 14 9 7
 return 0; 
 } 