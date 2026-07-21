class Solution {
public:
    bool isSafe(int row , int col , vector<string>&ds , int n){
        int duprow=row;
        int dupcol=col;

        //upper diagonal
        while(row >= 0 && col >=0){
            if(ds[row][col] == 'Q')return false;
            row--;
            col--;
        }
        row=duprow;
        col=dupcol;

        //left
        while(col >= 0){
            if(ds[row][col]=='Q')return false;
            col--;
        }
        row=duprow;
        col=dupcol;

        //lower diagonal
        while(row <n && col >= 0){
            if(ds[row][col]=='Q')return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col , vector<string>&ds , int &count , int n){
        if(col == n){
            count++;
            return;
        }

        for(int row = 0 ; row <n ;row++){
            if(isSafe(row , col , ds , n)){
                ds[row][col]='Q';     //do something
                solve(col +1 , ds , count , n);   //explore
                ds[row][col]='.';    //undo 
            }
        }
    }
    int totalNQueens(int n) {
        int count=0;
       vector<string> ds;
       string s(n,'.');
       for(int i=0;i<n;i++){
        ds.push_back(s);
        }
        solve(0 , ds , count , n);
        return count;
    }
};