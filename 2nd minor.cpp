#include "minor2(header).cpp"
#include<iostream>
#include<map>
#include<limits>
using namespace std;

long long int arr[900][13];

const int verify=3000;
const long long int n=100;
bool knn(int x,int k);
int final_result[verify]=
{0,0,2,0,0,0,0,0,1,0,
0,0,0,0,0,0,0,0,1,0,
0,0,0,0,2,0,0,0,1,1,
0,1,0,0,0,0,2,0,0,0,
0,0,0,0,1,0,0,0,0,0,
0,0,0,0,2,0,0,0,0,2,
0,0,0,0,0,0,0,0,0,0,
0,2,0,1,0,0,0,0,0,0,
0,0,0,0,0,1,1,0,0,0,
0,0,0,2,0,0,0,0,0,0,

2,0,0,0,1,1,0,0,0,0,
1,0,1,2,0,0,0,0,0,0,
0,0,1,2,0,0,0,0,0,0,
1,0,0,0,2,0,0,0,0,0,
1,0,0,0,0,0,0,0,0,0,
0,0,0,2,0,0,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,
0,0,1,0,0,2,0,0,0,2,
1,0,0,0,0,0,0,0,0,2,
0,0,0,0,0,0,2,0,0,0,

0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
1,0,2,0,0,0,0,1,1,0,
0,0,1,0,0,1,2,0,0,0,
2,0,0,0,2,0,0,0,0,0,
0,1,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,0,0,
1,0,0,0,1,0,0,0,0,0,
0,2,0,2,0,0,2,0,0,0,
0,0,0,0,0,0,0,1,0,0,

2,0,0,0,0,0,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,2,0,0,0,2,0,
0,0,2,1,0,0,0,0,0,0,
0,0,0,0,1,2,0,0,0,0,
0,0,0,0,0,0,1,0,0,0,
0,0,0,0,0,0,0,0,1,0,
0,0,2,0,2,0,0,0,0,0,
0,0,2,0,0,0,0,0,0,0,

0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,1,0,0,2,
0,0,0,0,0,0,0,0,2,0,
0,0,0,0,1,0,0,2,0,0,
0,0,0,0,0,1,0,0,0,2,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,2,0,
0,0,0,0,0,0,0,1,0,1,
0,0,0,2,0,0,0,0,1,0,
0,0,0,0,2,0,0,0,2,0,

0,0,0,0,0,0,0,0,0,0,
0,1,0,0,0,0,0,2,0,0,
0,1,0,0,0,0,0,0,0,0,
0,2,1,0,1,0,1,0,0,0,
0,0,0,0,0,2,0,0,0,0,
0,0,0,0,0,0,2,0,0,0,
0,2,0,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,1,2,0,0,0,2,0,0,
0,0,0,0,0,0,0,0,0,0,

0,0,2,0,0,2,0,0,0,0,
0,0,0,0,0,0,2,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,1,0,2,0,0,
0,0,0,2,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,2,1,0,0,0,0,0,0,
0,0,2,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,2,
0,2,0,0,0,0,0,0,0,0,

0,0,0,0,0,0,1,2,0,0,
1,0,0,0,1,0,0,0,1,0,
0,1,0,0,0,0,0,1,0,1,
0,0,0,0,0,0,0,1,0,0,
0,0,1,0,1,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,1,1,1,0,0,0,0,0,0,
1,0,0,0,0,2,0,0,1,0,
0,0,0,0,0,1,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,

0,0,0,0,0,0,0,0,0,0,
0,0,2,0,2,0,0,0,0,0,
0,0,0,2,0,0,2,0,0,0,
0,0,0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,

0,0,0,0,0,0,0,0,0,0,
2,0,0,0,2,0,0,0,0,2,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,2,0,0,0,
1,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,2,0,2,0,2,0,0,0,
0,0,0,0,0,2,0,1,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,

0,0,1,0,0,0,0,0,0,0,
0,0,0,0,2,0,2,0,0,2,
0,0,0,0,0,0,0,0,0,0,
2,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,2,0,0,0,0,0,
0,2,0,0,0,2,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,2,0,0,0,
0,0,0,0,0,0,0,0,0,0,

0,1,0,0,0,0,0,0,0,2,
0,0,0,0,0,0,2,0,0,0,
0,2,0,0,0,0,0,0,0,2,
0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,0,0,
0,0,0,0,1,0,0,0,0,0,
0,0,0,0,0,0,1,0,0,0,
0,0,2,0,1,0,2,0,0,0,
0,2,0,0,0,0,0,0,0,0,

0,1,0,0,0,1,0,0,1,0,
0,2,0,0,0,0,0,0,0,0,
0,0,0,1,0,0,0,1,1,0,
0,0,0,0,2,0,2,0,0,0,
0,0,2,0,0,0,0,0,0,0,
1,0,0,1,2,1,0,0,0,1,
0,0,0,1,0,0,1,0,0,1,
1,0,0,1,1,1,0,0,0,1,
0,1,0,0,0,0,2,1,1,0,
0,0,2,1,0,0,0,0,1,0,

2,0,0,1,0,2,0,0,1,0,
0,1,1,0,0,0,0,1,0,0,
0,1,0,0,0,0,0,0,1,0,
0,1,1,0,0,0,1,0,2,0,
0,0,0,2,0,0,1,1,0,0,
2,1,0,0,0,0,0,1,0,0,
1,0,0,0,1,0,0,0,0,1,
0,0,0,2,0,0,1,0,0,0,
1,0,0,1,1,1,1,0,0,1,
2,1,0,2,1,0,0,1,0,0,

0,2,0,0,0,1,0,0,1,0,
0,0,0,0,1,2,0,0,0,0,
0,0,0,1,0,0,1,0,1,0,
0,0,2,0,0,0,0,1,0,0,
0,0,0,0,0,0,0,1,2,1,
0,0,1,0,2,0,0,0,0,1,
1,2,0,1,0,1,0,0,1,0,
1,0,0,1,0,1,0,0,0,0,
0,1,0,0,0,0,0,1,1,0,
0,0,1,0,1,2,0,0,1,2,

0,2,0,1,1,0,0,0,1,1,
1,0,0,0,1,1,0,0,1,2,
0,1,1,0,0,0,1,1,1,1,
1,0,1,0,0,0,0,0,1,0,
0,0,0,0,0,0,2,0,0,0,
0,1,1,1,0,0,0,0,1,2,
1,1,0,2,1,0,0,2,0,1,
0,0,0,0,0,1,0,0,1,1,
1,0,0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,0,0,

0,0,0,0,0,0,0,0,0,0,
0,0,1,0,0,1,0,0,0,0,
1,0,1,0,0,1,0,0,0,0,
0,0,0,0,0,0,0,1,1,0,
0,0,0,0,0,2,0,0,0,0,
1,0,0,0,0,0,0,0,0,2,
0,0,0,0,0,0,0,0,0,1,
0,2,0,0,0,0,1,0,0,0,
0,0,0,0,2,0,0,0,0,0,
0,0,0,0,0,0,0,2,0,0,

0,0,0,0,0,0,0,2,0,0,
0,0,0,0,0,0,0,0,0,0,
2,0,0,0,0,0,0,0,0,0,
0,2,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,1,2,
0,0,0,0,0,0,0,0,0,0,
0,0,2,0,0,0,0,0,0,0,
0,0,0,0,0,2,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,

0,0,0,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,0,0,
0,1,0,0,1,0,0,0,0,0,
1,0,0,0,0,0,0,0,0,0,
0,0,1,0,0,0,0,0,1,2,
0,0,0,0,0,0,1,2,0,2,
1,0,0,0,0,0,2,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,1,0,

0,0,2,0,0,0,2,0,0,0,
0,0,2,0,0,0,0,2,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,1,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,2,0,2,0,0,0,0,
0,0,0,1,0,0,0,2,1,2,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,2,0,0,0,2,0,0,0,0,

0,0,0,0,0,1,0,0,0,0,
0,2,0,0,0,0,0,0,1,0,
0,2,0,0,0,1,0,0,0,0,
0,0,1,0,0,0,0,0,0,0,
0,2,0,0,0,0,0,0,0,0,
0,2,0,0,0,0,2,0,0,1,
1,0,0,1,0,0,0,0,0,0,
0,0,0,0,0,1,0,0,0,0,
1,0,0,2,1,0,0,0,0,1,
0,2,1,1,0,0,1,0,0,0,

0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,1,2,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,1,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,2,0,0,0,0,
2,0,0,2,0,0,0,0,0,0,
2,1,0,0,0,0,0,0,0,0,

0,0,0,0,0,0,0,0,0,0,
0,1,0,0,0,1,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,1,0,0,1,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,1,1,0,0,
0,0,0,0,0,0,1,0,0,0,
0,0,0,0,0,0,0,0,1,0,
2,0,2,0,0,1,2,0,0,1,
0,0,0,1,0,2,0,0,0,0,

0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,1,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,1,2,0,2,0,2,0,0,0,
0,0,0,2,1,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,1,0,0,0,0,0,0,0,0,
0,0,0,2,0,2,0,0,0,0,

0,0,0,0,2,0,0,0,2,0,
0,0,0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,2,0,0,0,0,
0,0,0,0,2,0,0,0,0,0,
0,0,1,0,0,0,2,0,2,0,
1,0,0,0,0,0,0,0,0,0,
0,1,0,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,2,0,0,

0,0,0,0,2,0,2,0,0,0,
0,0,0,0,0,0,0,0,0,0,
2,0,0,0,0,0,0,0,0,0,
0,1,0,0,0,1,1,0,0,0,
0,0,0,0,0,0,0,0,0,0,
2,0,0,2,0,0,0,0,0,2,
2,0,0,0,0,0,0,0,0,0,
0,0,1,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,2,0,0,0,0,2,0,1,

0,0,0,0,0,2,0,0,0,0,
0,0,0,2,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,2,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,0,1,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,2,0,2,1,0,0,0,0,

0,0,0,0,0,0,0,1,0,2,
0,0,0,0,2,0,0,0,1,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,1,0,0,0,0,0,
0,0,0,0,2,0,1,0,2,0,
0,0,0,0,2,0,1,0,0,0,
2,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,1,0,1,0,
0,0,0,0,0,0,0,1,0,0,
0,0,0,0,0,0,0,0,0,0,

0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,1,
0,0,2,0,1,2,0,0,2,0,
0,0,0,0,0,0,0,0,0,0,

0,0,0,1,0,0,0,0,0,0,
0,0,2,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,2,0,0,2,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,1,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,2,0,1,
2,0,0,0,2,0,0,2,0,0}
;
int result[]=
{
0,0,0,1,0,0,0,0,0,1,
0,0,0,1,1,0,0,1,0,0,
1,1,0,0,0,0,0,0,0,0,
1,0,0,0,0,0,1,0,1,0,
0,0,0,0,0,2,0,2,0,0,
0,0,2,1,0,0,0,0,0,0,
0,1,1,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
2,0,0,0,0,0,0,0,0,0,
0,0,0,0,1,0,0,0,0,2,

0,0,2,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,0,0,
0,0,0,0,1,1,0,0,0,0,
0,0,1,0,0,0,0,1,1,1,
0,0,0,0,0,2,0,0,2,0,
0,0,1,0,2,0,0,0,0,0,
0,0,0,0,0,0,0,0,1,0,
2,1,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,1,1,

0,0,0,0,0,0,0,2,0,0,
2,0,0,1,0,2,1,0,1,0,
0,0,0,0,0,0,2,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,1,0,0,0,0,0,1,2,
1,0,0,0,2,0,0,0,0,2,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,2,0,0,0,0,0,0,

0,0,0,1,0,0,1,0,0,0,
0,0,2,2,0,0,0,0,0,0,
0,0,0,1,0,2,0,0,0,0,
0,0,0,0,1,0,0,0,2,0,
0,0,0,0,0,0,0,2,2,0,
0,0,0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,0,0,
0,0,0,0,0,0,0,0,2,0,
0,0,0,2,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,

0,0,0,0,0,2,0,0,0,0,
0,0,0,0,0,0,0,0,1,2,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,2,1,1,2,1,
0,0,0,0,0,0,0,0,1,1,
0,0,0,0,0,0,0,0,0,0,
0,0,1,1,0,1,0,1,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,2,0,1,2,0,
0,0,0,2,2,0,0,0,1,0,
0,1,0,1,0,0,0,0,1,0,
0,0,0,0,0,0,0,0,1,0,
0,1,0,0,0,1,0,0,0,0,
0,1,0,0,0,0,0,0,2,0,
2,0,0,0,2,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,1,0,0,1,0,0,0,0,0,
1,0,0,1,2,0,0,0,0,1,
0,0,0,0,0,0,0,0,0,0,
2,0,1,0,2,0,0,0,0,0,
0,0,0,0,0,0,0,2,0,0,
0,0,0,0,0,0,0,0,0,0,
1,0,2,0,0,0,0,0,1,0,
0,0,0,0,0,0,0,0,1,0,
0,0,0,2,0,2,0,0,0,0,
0,0,0,2,0,0,0,0,0,2,
0,0,0,0,0,1,0,0,0,0,
0,0,0,0,0,0,2,0,0,0,
0,0,0,0,0,0,0,0,2,0,
0,0,0,0,0,1,0,0,0,0,
0,0,0,0,1,0,1,2,0,0,
0,0,0,0,2,0,0,0,0,0,
0,0,0,0,0,0,2,0,0,0,
0,0,0,0,0,2,0,0,0,0,
0,0,0,0,0,0,0,0,0,1,
0,0,0,0,2,0,0,0,0,2,
0,0,0,0,0,0,0,0,0,0,
0,1,0,0,0,1,0,0,0,0,
0,0,0,2,0,0,0,0,0,0,
0,1,0,0,0,0,0,0,0,2,
0,0,2,0,0,0,2,0,0,0,
0,0,0,0,0,1,1,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,2,1,0,0,
0,0,0,0,0,0,0,0,0,0,
0,1,1,2,0,2,0,0,0,0,
2,0,0,0,1,0,0,0,0,1,
0,0,0,0,0,0,0,0,1,0,
1,0,0,0,0,2,0,0,0,0,
0,0,0,0,1,1,2,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,2,0,0,0,0,0,1,0,0,1,0,2,0,0,0,0,0,1,0,0,0,0,0,0,2,1,
0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,
2,0,0,2,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0

};

int tds=50;
int c[n];
int ta[100000][no_of_attributes];
int te=300;
//int tds=sizeof(result)/sizeof(result[0]);

//NO of conditions
int noc_account_age=4;
int noc_no_of_followers=4;//
int noc_no_of_following=4;//
int noc_no_of_lists=2;//
int noc_no_of_retweets=4;
int noc_no_of_hashtags=3;//
int noc_no_of_status=3;//
int noc_no_of_users_mentioned=3;//
int noc_no_of_urls=3;//
int noc_no_of_characters=3;//
int noc_no_of_digits=3;//
int noc_no_of_favourites=4;//
int noc_verified=2;//

//no_of_attributes=13;
    static map<string,int>tweet_attributes_no=
    {
        {"account_age",0},
        {"no_of_followers",1},
        {"no_of_following",2},
        {"no_of_lists",3},
        {"no_of_retweets",4},
        {"no_of_hashtags",5},
        {"no_of_status",6},
        {"no_of_users_mentioned",7},
        {"no_of_urls",8},
        {"no_of_characters",9},
        {"no_of_digits",10},
        {"no_of_favourites",11},
        {"verified",12}
    };

int noc[no_of_attributes]={4,4,4,2,4,3,3,3,3,3,3,4,2};
int account_age_category(long long int x)
{
    if(x<=0)return 0;
    if(x>5 && x<=100)return 1;
    if(x>100 && x<1000000)return 2;
    else return 3;
}
int no_of_followers_category(long int x)
{
    if(x<=100)return 0;
    if(x>100 && x<1000)return 1;
    if(x>1000 && x<=5000)return 2;
    if(x>5000)return 3;
}
int no_of_following_category(long int x)
{
    if(x==0)return 0;
    if(x>0 && x<100)return 1;
    if(x>100 && x<=5000)return 2;
    if(x>5000)return 3;
}

int no_of_lists_category(long int x)
{
    if(x==0)return 0;
    if(x>0)return 1;
}
int no_of_retweets_category(long int x)
{
    if(x==0)return 0;
    if(x>0 && x<10)return 1;
    if(x>10 && x<=100)return 2;
    if(x>100)return 3;
}
int no_of_hashtags_category(long int x)
{
    if(x==0)return 0;
    if(x==1)return 1;
    if(x>=2)return 2;

}
int no_of_status_category(long int x)
{
    if(x<=1000)return 0;
    if(x>1000 && x<10000)return 1;
    if(x>10000)return 2;

}

int no_of_users_mentioned_category(long int x)
{
    if(x==0)return 0;
    if(x==1)return 1;
    if(x>=2)return 2;

}
int no_of_urls_category(long int x)
{
    if(x==0)return 0;
    if(x==1)return 1;
    if(x>=2)return 2;
}

int no_of_characters_category(int x)
{
    if(x<50)return 0;
    if(x>=50 && x<100)return 1;
    if(x>=100)return 2;
}

int no_of_digits_category(int x)
{
    if(x==0)return 0;
    if(x<=5)return 1;
    if(x>5)return 2;
}

int no_of_favourites_category(long int x)
{
    if(x==0)return 0;
    if(x>0 && x<=200)return 1;
    if(x>200 && x<=3000)return 2;
    if(x>3000)return 3;
}
int verified_category(long int x)
{
    if(x==0)return 0;
    if(x==1)return 1;
}

float a_yes_result_yes[no_of_attributes][10]={0.5};
float a_no_result_yes[no_of_attributes][10]={0.5};
float a_yes_result_no[no_of_attributes][10]={0.5};
float a_no_result_no[no_of_attributes][10]={0.5};

float tp=0;
float tn=0;
int nts=sizeof(result)/sizeof(result[0]);
float ppositive=0;
float pnegative=0;

int main()
{
    cout<<"nts is "<<nts<<endl;
    for(int i=0;i<nts;i++)
    {
        if(result[i]==1)
        {
            tp++;
        }
        else if(result[i]==0)
        {
            tn++;
        }
    }
    ppositive=tp/nts;
    pnegative=1-ppositive;
    cout<<"start"<<endl;
    get_array(arr);
    cout<<"milgya"<<endl;

    //copy afyer 1500 to tezt array

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<no_of_attributes;j++)
        {
            ta[i][j]=arr[i+te][j];
        }
    }
    cout<<"milgya"<<endl;

    int counts=0;
    for(long long int i=0;i<100;i++)
    {
        cout<<counts++<<" ";
        for(int j=0;j<no_of_attributes;j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }

    cout<<"milgya"<<endl;

    for(int i=0;i<no_of_attributes;i++)
    {
        float yes_yes[10]={0},yes_no[10]={0},no_yes[10]={0},no_no[10]={0};

        for(int j=0;j<nts;j++)
        {
           // if(arr[j][9]!=0)
            //{

                if(i==0)
                {
                    if(result[j]==1)
                    {
                        yes_yes[account_age_category(arr[j][0])]++;
                        //cout<<yes_yes[0]<<"  "<<yes_yes[1]<<"  "<<yes_yes[2]<<" "<<yes_yes[3]<<endl;
                        //cout<<yes_yes[account_age_category(arr[j][0])]<<endl;
                        for(int l=0;l<noc_account_age;l++)
                        {
                            if(l!=account_age_category(arr[j][0]))
                                no_yes[l]++;
                        }

                    }
                    if(result[j]==0)
                    {
                        yes_no[account_age_category(arr[j][0])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=account_age_category(arr[j][0]))
                                no_no[l]++;
                        }
                    }

                }

                if(i==1)
                {
                    if(result[j]==1)
                    {
                        yes_yes[no_of_followers_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_followers_category(arr[j][1]))
                                no_yes[l]++;
                        }

                    }
                    if(result[j]==0)
                    {
                        yes_no[no_of_followers_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_followers_category(arr[j][1]))
                                no_no[l]++;
                        }
                    }

                }
                if(i==2)
                {
                    if(result[j]==1)
                    {
                        yes_yes[no_of_following_category(arr[j][2])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_following_category(arr[j][2]))
                                no_yes[l]++;
                        }

                    }
                    if(result[j]==0)
                    {
                        yes_no[no_of_following_category(arr[j][2])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_following_category(arr[j][2]))
                                no_no[l]++;
                        }
                    }

                }

               if(i==3)
                {
                    if(result[j]==1)
                    {
                        yes_yes[no_of_lists_category(arr[j][3])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_lists_category(arr[j][3]))
                                no_yes[l]++;
                        }

                    }
                    if(result[j]==0)
                    {
                        yes_no[no_of_lists_category(arr[j][3])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_lists_category(arr[j][3]))
                                no_no[l]++;
                        }
                    }

                }
               if(i==4)
                {
                    if(result[j]==1)
                    {
                        yes_yes[no_of_retweets_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_retweets_category(arr[j][1]))
                                no_yes[l]++;
                        }

                    }
                    if(result[j]==0)
                    {
                        yes_no[no_of_retweets_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_retweets_category(arr[j][1]))
                                no_no[l]++;
                        }
                    }

                }
               if(i==5)
                {
                    if(result[j]==1)
                    {
                        yes_yes[no_of_hashtags_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_hashtags_category(arr[j][1]))
                                no_yes[l]++;
                        }

                    }
                    if(result[j]==0)
                    {
                        yes_no[no_of_hashtags_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_hashtags_category(arr[j][1]))
                                no_no[l]++;
                        }
                    }

                }
               if(i==6)
                {
                    if(result[j]==1)
                    {
                        yes_yes[no_of_status_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_status_category(arr[j][1]))
                                no_yes[l]++;
                        }

                    }
                    if(result[j]==0)
                    {
                        yes_no[no_of_status_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_status_category(arr[j][1]))
                                no_no[l]++;
                        }
                    }

                }
               if(i==7)
                {
                    if(result[j]==1)
                    {
                        yes_yes[no_of_users_mentioned_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_users_mentioned_category(arr[j][1]))
                                no_yes[l]++;
                        }

                    }
                    if(result[j]==0)
                    {
                        yes_no[no_of_users_mentioned_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_users_mentioned_category(arr[j][1]))
                                no_no[l]++;
                        }


                    }
                }

                if(i==8)
                {
                    if(result[j]==1)
                    {
                        yes_yes[no_of_urls_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_urls_category(arr[j][1]))
                                no_yes[l]++;
                        }

                    }
                    if(result[j]==0)
                    {
                        yes_no[no_of_urls_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_urls_category(arr[j][1]))
                                no_no[l]++;
                        }


                    }
                }

                if(i==9)
                {
                    if(result[j]==1)
                    {
                        yes_yes[no_of_characters_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_characters_category(arr[j][1]))
                                no_yes[l]++;
                        }

                    }
                    if(result[j]==0)
                    {
                        yes_no[no_of_characters_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_characters_category(arr[j][1]))
                                no_no[l]++;
                        }


                    }
                }

                if(i==10)
                {
                    if(result[j]==1)
                    {
                        yes_yes[no_of_digits_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_digits_category(arr[j][1]))
                                no_yes[l]++;
                        }

                    }
                    if(result[j]==0)
                    {
                        yes_no[no_of_digits_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_digits_category(arr[j][1]))
                                no_no[l]++;
                        }


                    }
                }

                if(i==11)
                {
                    if(result[j]==1)
                    {
                        yes_yes[no_of_favourites_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_favourites_category(arr[j][1]))
                                no_yes[l]++;
                        }

                    }
                    if(result[j]==0)
                    {
                        yes_no[no_of_favourites_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=no_of_favourites_category(arr[j][1]))
                                no_no[l]++;
                        }


                    }
                }
    /*
                if(i==12)
                {
                    if(result[j]==1)
                    {
                        yes_yes[verified_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=verified_category(arr[j][1]))
                                no_yes[l]++;
                        }

                    }
                    if(result[j]==0)
                    {
                        yes_no[verified_category(arr[j][1])]++;
                        for(int l=0;l<noc[i];l++)
                        {
                            if(l!=verified_category(arr[j][1]))
                                no_no[l]++;
                        }


                    }
                }
            yes_yes[account_age_category(arr[j][0])]
    */
                //cout<<"second time  "<<yes_yes[account_age_category(arr[j][0])]<<endl;;
                //cout<<"aresultyesyes  ";

                //}
        }

        float norm=0;
        for(int x=0;x<noc[i];x++)
            {

                if(tp>0 && yes_yes[x]>0)
                {
                    a_yes_result_yes[i][x]=yes_yes[x]/tp;
                    //cout<<a_yes_result_yes[i][x]<<"  "<<yes_yes[x]<<"  "<<tp<<"  "<<endl;;
                }
                else
                {
                    a_yes_result_yes[i][x]=norm;
                }

                if(tn>0 && yes_no[x]>0)
                {
                    a_yes_result_no[i][x]=yes_no[x]/tn;
                }
                else
                {
                    a_yes_result_no[i][x]=norm;
                }

                if(tp>0 && no_yes[x]>0)
                {
                    a_no_result_yes[i][x]=no_yes[x]/tp;
                }
                else
                {
                    a_no_result_yes[i][x]=norm;
                }

                if(tn>0 && no_no[x]>0)
                {
                    a_no_result_no[i][x]=no_no[x]/tn;
                }
                else
                {
                    a_no_result_no[i][x]=norm;
                }

            }
            //cout<<"end"<<endl<<endl;
    }

    cout<<"noof att "<<no_of_attributes<<endl<<endl;

    for(int i=0;i<no_of_attributes;i++)
    {
        for(int j=0;j<noc[i];j++)
        {
                cout<<a_yes_result_yes[i][j]<<" ";
                cout<<a_yes_result_no[i][j]<<" ";
                cout<<a_no_result_yes[i][j]<<" ";
                cout<<a_no_result_no[i][j]<<" ";
                cout<<endl;
        }
        cout<<endl<<endl;
    }

    float prob_of_spam=0;
    float prob_of_not_spam=0;
    for(long int i=0;i<n;i++)
    {
        int cat[no_of_attributes];
        cat[0]=account_age_category(ta[i][0]);
        cat[1]=no_of_followers_category(ta[i][1]);
        cat[2]=no_of_following_category(ta[i][2]);
        cat[3]=no_of_lists_category(ta[i][3]);
        cat[4]=no_of_retweets_category(ta[i][4]);
        cat[5]=no_of_hashtags_category(ta[i][5]);
        cat[6]=no_of_status_category(ta[i][6]);
        cat[7]=no_of_users_mentioned_category(ta[i][7]);
        cat[8]=no_of_urls_category(ta[i][8]);
        cat[9]=no_of_characters_category(ta[i][9]);
        cat[10]=no_of_digits_category(ta[i][10]);
        cat[11]=no_of_favourites_category(ta[i][11]);
        cat[12]=verified_category(ta[i][12]);

        float pos_prob=ppositive,neg_prob=pnegative;
        for(int j=0;j<no_of_attributes-1;j++)
        {
            pos_prob=pos_prob*a_yes_result_yes[j][cat[j]]/1;
            neg_prob=neg_prob*a_yes_result_no[j][cat[j]]/1;
        }
       // cout<<pos_prob<<","<<neg_prob<<"  ";
        //cout<<endl<<endl;
        if(pos_prob>=neg_prob)
        {
            c[i]=1;
        }
        else if(pos_prob<neg_prob)
        {
            c[i]=0;
        }
        else
        {
            c[i]=knn(i,7);
        }
            //cout<<pos_prob<<"  "<<neg_prob<<"   "<<c[i]<<endl;

    }

    for(int i=0;i<n;i++)
    {
        //cout<<"c "<<i+1<<" "<<c[i]<<endl;
    }


    float pos_as_pos=0;
    float pos_as_neg=0;
    float neg_as_pos=0;
    float neg_as_neg=0;

    for(int i=0;i<n;i++)
    {
        if(c[i]==1  &&  final_result[i]==1)
        {
            pos_as_pos++;
        }

        if(c[i]==0  &&  final_result[i]==1)
        {
            pos_as_neg++;
        }

        if(c[i]==1  &&  final_result[i]==0)
        {
            neg_as_pos++;
        }

        if(c[i]==0  &&  final_result[i]==0)
        {
            neg_as_neg++;
        }
    }

    float precision=1,recall=1;

    cout<<pos_as_pos<<"  "<<pos_as_neg<<"  "<<neg_as_pos<<"  "<<neg_as_neg<<endl;
    if(pos_as_pos+neg_as_pos>0)
    {
            precision=pos_as_pos/(pos_as_pos+neg_as_pos);

    }
    else
    {
       precision=0;
    }

    if(pos_as_pos+neg_as_pos>0)
    {
    recall=pos_as_pos/(pos_as_pos+pos_as_neg);
    }
    else
    {
        recall=0;
    }
    float tpr,fpr;
    tpr=pos_as_pos/(pos_as_pos+pos_as_neg);
    fpr=(pos_as_neg/(neg_as_pos+pos_as_neg))*neg_as_pos;
    cout<<"PRECISION  "<<precision<<endl<<"  RECALL  "<<recall<<endl;
    cout<<"TPR "<<tpr<<endl;
    cout<<"  FPR  "<<fpr<<endl;
    return 0;
}



bool knn(int x,int k)
{
    long long int diff[1000]={0};
    for(int i=0;i<nts;i++)
    {
        long long int mdiff;
        for(int j=0;j<no_of_attributes;j++)
        {
            mdiff+=ta[x][j]-arr[i][j];
        }
        diff[i]=mdiff;
    }
    int nearest_neigh[k];
    long long int min_diff=INT_MAX;
    int checked[1000]={0};
    for(int i=0;i<k;i++)
    {
        min_diff=INT_MAX;
        for(int j=0;j<nts;j++)
        {
            if(checked[j]==0)
            if(diff[j]<min_diff)
            {
                nearest_neigh[i]=j;
            }
        }
        checked[nearest_neigh[i]]=1;
    }
    int no_spam=0,no_not_spam=0;
    for(int i=0;i<k;i++)
    {
        if(result[nearest_neigh[i]])
        {
            no_spam++;
        }
        else
        {
            no_not_spam++;
        }
    }
    if(no_spam>no_not_spam)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
