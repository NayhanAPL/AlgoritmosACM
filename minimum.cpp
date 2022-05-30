#include <bits/stdc++.h>
using namespace std;

int lista[L], minPorBlok[L];
int valueIni[L], valueFin[L], posGroup[L];

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
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".in", "r", stdin);

    int oo = 106;
    cin >> cases;
    for(int c = 1; c <= cases; c ++)
    {
       cin;
       int L, Q; cin >> L >> Q;
       int rootList = sqrt(L);
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



