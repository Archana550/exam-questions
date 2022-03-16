### Problem Description
Consider a set of web pages, numbered from 1 to N. Each web page has links to one or more web pages. Clicking on a link in a page, takes one to the other web page.
You are provided numbers of two web pages viz, starting web page and the end web page. Your task is to find the minimum number of clicks required to reach the end page from the start page.
If end page cannot be reached from start page, print -1 as the output. 

### Input
First line contains an integer N denoting number of web pages.
Next N lines contain L space separated integers dpicting linked webpage numbers(s) from the webpage.
Last line contains two space separated integers denoting starting page and ending page respectively.

### Output
Print the minimum number of clicks required to open the end page from the start page. If not possible print -1 as output.

### Example 1
```
// Input

5
2 4
1 
1 5
2 3
5 
2 3

//Output

3
```
### Example 2
```
// Input
3
2
1
1
2 3

// Output

-1

Explanation:
First line conveys that there is total 3 pages.
Second line conveys that there are links from page 1 to page 2.
Third line conveys that there is a link from page 2 to page 1.
Fourth line conveys that there are links from page 3 to page 1.
Since there is no such way to reach from page 2 to page 3, print -1 as output.
```



```
#include<bits/stdc++.h>
using namespace std;
int n;
vector < int >adj[1000];
vector < int >visited (100000, 0);
int mn = INT_MAX, res = 0, k = mn;
void dfs (int u, int v){
  if (u == v)
  {
      if (mn > res)
	   {
	       mn = res;
	   }
  }
  visited[u] = 1;
  
  for (auto j:adj[u]){
      if (visited[j] == 0){
	         res +=1;
	         visited[j] == 1;
	         dfs (j, v);
	         visited[j] == 0;
	         res -=1;
	  }
  }
  visited[u] = 0;
}

int main (){
  string s;
  getline (cin, s);
  n = s[0] - '0';
  string word;
  for (int i = 1; i < n + 1; i++){
      getline (cin, word);
      for (int j = 0; j < word.length (); j++){
	  if ((word[j] - '0') != -16){
	      adj[i].push_back (word[j] - '0');
	  }
      }
  }
  
  //print statements for testing
//   for (int i = 1; i < n + 1; i++)
//     {
//       for (int j = 0; j < adj[i].size (); j++)
// 	{
// 	  cout << adj[i][j] << " ";
// 	}
//     }
  //cout << endl;
  
  int start, end;
  cin >> start >> end;
  dfs (start, end);
  if (mn == k)
    cout << "-1";
  else
    cout << mn;
  return 0;
}
```
