#include <bits/stdc++.h>
using namespace std;

int lista[L], mul3PorBlok[L];
int valueIni[L], valueFin[L], posGroup[L];

void update(int ini, int fin){
    for(int i = ini; i <= fin; i++)
    {
       lista[i] ++;
       int g = posGroup[i];
       if(lista[i] % 3 == 0)
       {mul3PorBlok[g] ++;}
    }
    return;
}
void build(){
    int index = 1;
    valueIni[index] = 0;
    mul3PorBlok[index] = 0;
    for(int i = 0; i < L; i++)
    {
        posGroup[i] = index;
        if(i % rootList == 0)
        {
            valueFin[index] = i;
            index++;
            valueIni[index] = i + 1;
            mul3PorBlok[index] = 0;
        }
    }
    valueFin[index] = L;
    return;
}
int query(int ini, int fin){
    int cont = 0;
    int i = ini;
    // recorre el primer grupo
    while(posGroup[i] == posGroup[ini] && posGroup[i] != posGroup[fin])
    {if(lista[i] % 3 == 0){cont ++}; i ++;}
    // recorre los grupos intermedios
    while(posGroup[i] != posGroup[fin])
    {cont += mul3PorBlok[ posGroup[i] ]; i = ini[ posGroup[i] + 1 ]}
    // recorre el ultimo grupo
    while(i <= fin)
    {if(lista[i] % 3 == 0){cont ++}; i++;}

    return cont;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".in", "r", stdin);

    cin >> cases;
    for(int c = 1; c <= cases; c ++)
    {
       cin;
       int L, Q; cin >> L >> Q;
       int rootList = sqrt(L);
       for(int i = 0; i <= L; i++)
       {
          lista[i] = 0;
       }
       build();
       cout << "Case " << c << ":\n"
       for(int i = 1; i <= Q; i++)
       {
          int oper, a, b; cin >> oper >> a >> b;
          if(oper == 1){cout << query(a, b) << "\n";}
          if(oper == 0){update(a, b)} 
          cin >> oper >> a >> b  
       }
    }
    return 0;
}

