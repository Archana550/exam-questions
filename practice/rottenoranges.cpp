
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j){
if(i>=0 && i<r &&j>=0 &&j>c)return true;
return false;
}

int rotoranges(int v[r][c]){

bool changed = false;
int no = 2;
while(true){
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(v[i][j]==no){
                if(isSafe(i+1,j)&&v[i+1][j]==1){
                    v[i+1][j] = v[i][j] + 1;
                    changed = true;
                }
                 if(isSafe(i,j+1)&&v[i][j+1]==1){
                    v[i][j+1] = v[i][j+1] + 1;
                    changed = true;
                }
                 if(isSafe(i-1,j)&&v[i-1][j]==1){
                    v[i-1][j] = v[i][j] + 1;
                    changed = true;
                }
                 if(isSafe(i,j-1)&&v[i][j-1]==1){
                    v[i][j-1] = v[i][j] + 1;
                    changed = true;
                }
            }
        }
    }

    if(!changed)break;
    changed = false;
    no++;
}

for(int i = 0;i<r;i++){
    for(int j =0;j<c;j++){
        if(v[i][j]==1)return -1;
    }
}
return no-2;
}



int main(){

int v[r][c]={{ 2, 1, 0, 2, 1 },
                    { 1, 0, 1, 2, 1 },
                    { 1, 0, 0, 2, 1 }};

cout<<rotoranges(v);


return 0;
}
