#include <bits/stdc++.h>
using namespace std;

int maxn = 1e5 + 5;
int lista[maxn], minPorBlok[maxn];
int valueIni[maxn], valueFin[maxn], posGroup[maxn];
int oo = maxn;
int L, Q, rootList;

int query(int ini, int fin){
    int menor = oo;
    int i = ini;
    // recorre el primer grupo
    while(posGroup[i] == posGroup[ini] && posGroup[i] != posGroup[fin])
    {menor = min(menor, lista[i]); i ++;}
    // recorre los grupos intermedios
    while(posGroup[i] != posGroup[fin])
    {menor = min(menor, minPorBlok[ posGroup[i] ]); i = ini[ posGroup[i] + 1 ]}
    // recorre el ultimo grupo
    while(i <= fin)
    {menor = min(menor, lista[i]); i++;}

    return menor;
}
void build(){
    int index = 1;
    valueIni[index] = 1;
    minPorBlok[index] = oo;
    for(int i = 1; i <= L; i++)
    {
        minPorBlok[index] = min(minPorBlok[index], lista[i]);
        posGroup[i] = index;
        if(i % rootList == 0)
        {
            valueFin[index] = i;
            index++;
            valueIni[index] = i + 1;
            minPorBlok[index] = oo;
        }
    }
    valueFin[index] = L;
    return;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".in", "r", stdin);
    int cases; cin >> cases;
    for(int c = 1; c <= cases; c ++)
    {
       cin >> L >> Q;
       rootList = sqrt(L);
       for(int i = 1; i <= L; i++)
       {
          cin >> lista[i];
       }
       build();
       cout << "Case " << c << ":\n"
       for(int i = 1; i <= Q; i++)
       {
          int a, b; cin >> a >> b;
          cout << query(a, b) << "\n";
       }
    }
    return 0;
}


/*Given an array with N elements, indexed from 1 to N.
Now you will be given some queries in the form I J, your task is to find the minimum value from index I to J.
Input:
      Input starts with an integer T (≤ 5), denoting the number of test cases.
      The first line of a case is a blank line.
      The next line contains two integers N (1 ≤ N ≤ 105), q (1 ≤ q ≤ 50000).
      The next line contains N space separated integers forming the array. There integers range in [0, 105].
      The next q lines will contain a query which is in the form I J (1 ≤ I ≤ J ≤ N).
Output:
      For each test case, print the case number in a single line.
      Then for each query you have to print a line containing the minimum value between index I and J.

