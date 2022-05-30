#include <bits/stdc++.h>
using namespace std;

int lista[L], max1SumPorBlok[L]; max2SumPorBlok[L];
int valueIni[L], valueFin[L], posGroup[L];

void update(int pos, int val){
    int g = posGroup[pos];
    lista[pos] = val;
    max1SumPorBlok[g] = 0;
    max2SumPorBlok[g] = 0;
    for(int i = valueIni[g]; i <= valueFin[g]; i++){
       if(max1SumPorBlok[g] < lista[i])
        {
            max2SumPorBlok[g] = max1SumPorBlok[g]
            max1SumPorBlok[g] = lista[i];
        }
        else if(max2SumPorBlok[g] < lista[i]){max2SumPorBlok[g] = lista[i];}
    }
    return;
}
void build(){
    int index = 1;
    valueIni[index] = 1;
    max1SumPorBlok[index] = 0;
    max2SumPorBlok[index] = 0;
    for(int i = 1; i <= L; i++)
    {
        if(max1SumPorBlok[index] < lista[i])
        {
            max2SumPorBlok[index] = max1SumPorBlok[index]
            max1SumPorBlok[index] = lista[i];
        }
        else if(max2SumPorBlok[index] < lista[i]){max2SumPorBlok[index] = lista[i];}
       
        posGroup[i] = index;
        if(i % rootList == 0)
        {
            valueFin[index] = i;
            index++;
            valueIni[index] = i + 1;
            max1SumPorBlok[index] = 0;
            max2SumPorBlok[index] = 0;
        }
    }
    valueFin[index] = L;
    return;
}
int query(int ini, int fin){
    int mayor1 = 0;
    int mayor2 = 0;
    int i = ini;
    // recorre el primer grupo
    while(posGroup[i] == posGroup[ini] && posGroup[i] != posGroup[fin])
    {
        if(mayor1 < lista[i])
        {
            mayor2 = mayor1
            mayor1 = lista[i];
        }
        else if(mayor2 < lista[i]){mayor2 = lista[i];}
        i ++;
     }
    // recorre los grupos intermedios
    while(posGroup[i] != posGroup[fin])
    {mayor = max(mayor, max1SumPorBlok[ posGroup[i] ])
       if(mayor1 < max1SumPorBlok[ posGroup[i] ])
        {
            mayor2 = mayor1
            mayor1 = max1SumPorBlok[ posGroup[i] ];
        }
        else if(mayor2 < max1SumPorBlok[ posGroup[i] ]){mayor2 = max1SumPorBlok[ posGroup[i] ];}
        if(mayor2 < max2SumPorBlok[ posGroup[i] ]){mayor2 = max2SumPorBlok[ posGroup[i] ];}
        i = ini[ posGroup[i] + 1 ]
    }
    // recorre el ultimo grupo
    while(i <= fin)
    {
        if(mayor1 < lista[i])
        {
            mayor2 = mayor1
            mayor1 = lista[i];
        }
        else if(mayor2 < lista[i]){mayor2 = lista[i];}
        i ++;
    }

    return mayor1 + mayor2;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".in", "r", stdin);

    cin >> L;
    for(int i = 1; i <= L; i ++)
    {
        cin >> lista[i]
    }
    int Q; cin >> Q;
    int rootList = sqrt(L);
    build();
    string oper;
    int a, b; cin >> oper >> a >> b  
    for(int i = 1; i <= Q; i++)
    {
       if(oper == "Q"){cout << query(a, b) << "\n";}
       if(oper == "U"){update(a, b)} 
       cin >> oper >> a >> b  
    }
   
    return 0;
}


