#include <bits/stdc++.h>
using namespace std;

int lista[2], sumPorBlok[2];
int valueIni[2], valueFin[2], posGroup[2];

void update(int pos, int val){
    int g = posGroup[pos];
    lista[pos] = val;
    sumPorBlok[g] = 0;
    for(int i = valueIni[g]; i <= valueFin[g]; i++){
        sumPorBlok[g] += lista[i];
    }
    return;
}
void build(){
    int index = 1;
    valueIni[index] = 1;
    sumPorBlok[index] = 0;
    for(int i = 1; i <= L; i++)
    {
        sumPorBlok[index] += lista[i];
        posGroup[i] = index;
        if(i % rootList == 0)
        {
            valueFin[index] = i;
            index++;
            valueIni[index] = i + 1;
            sumPorBlok[index] = 0;
        }
    }
    valueFin[index] = L;
    return;
}
int query(int ini, int fin){
    int suma = 0;
    int i = ini;
    // recorre el primer grupo
    while(posGroup[i] == posGroup[ini] && posGroup[i] != posGroup[fin])
    {suma += lista[i]; i ++;}
    // recorre los grupos intermedios
    while(posGroup[i] != posGroup[fin])
    {suma += sumPorBlok[ posGroup[i] ]; i = ini[ posGroup[i] + 1 ]}
    // recorre el ultimo grupo
    while(i <= fin)
    {suma += lista[i]; i++;}

    return suma;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int cases = 1;
    int L; cin >> L;
    while(cases != 0)
    while(L != 0)
    for(int c = 1; c <= cases; c ++)
    {
       int rootList = sqrt(L);
       for(int i = 1; i <= L; i++)
       {
          cin >> lista[i];
       }
       build();
       cout << "Case " << cases << ":";
       int a, b;
       string oper; cin >> oper >> a >> b
       while(oper != "FIN")
       {
          if(oper == "M"){cout << query(a, b) << "\n";}
          if(oper == "S"){update(a, b)} 
          cin >> oper >> a >> b        
       }
     cout << ""
     cin >> L;
     cases ++;
    }
    return 0;
}
