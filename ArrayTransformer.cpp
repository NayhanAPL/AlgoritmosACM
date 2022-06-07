#include <bits/stdc++.h>
using namespace std;

int maxn = 1e5 * 3 + 5;
int lista[maxn], ordenadosPorBlok[maxn];                            //lista rara
int valueIni[maxn], valueFin[maxn], posGroup[maxn];
int rootList;
int n, m, u;

int findIndex(int posGrupo, int value){
    int right = rootList;
    int left = 0;
    int center = right / 2;
    while (left < rigth)
    {
        if(ordenadosPorBlok[posGrupo, center] => value)           //lista rara
        {
            right = center;
            center = (right + left) / 2;
        }
        if(ordenadosPorBlok[posGrupo, center] < value)            //lista rara
        {
            left = center + 1;
            center = (right + left) / 2;
        }
    }
    return center;
}
void update( int cont, int u, int ini, int fin, int posShange){
    int value = u * cont / (fin − ini + 1);
    lista[posShange] = value;
    int indexI = valueIni[posGroup[posShange]];
    int indexF = valueFin[posGroup[posShange]];
    ordenadosPorBlok[posGroup[posShange]].Clear();                  //lista rara
    for(int i = indexI; i <= indexF; i++)
    {
        ordenadosPorBlok[posGroup[posShange]].Add(lista[i]);        //lista rara
    }
    ordenadosPorBlok[index].OrderByAscending();                     //lista rara
    return;
}
int query(int ini, int fin, int value, int posShange){
    int i = ini;
    int cont = 0;
    // recorre el primer grupo
    while(posGroup[i] == posGroup[ini] && posGroup[i] != posGroup[fin])
    {
        if(lista[i] < value)
        {
            cont ++;
        }
        i ++;
    }
    // recorre los grupos intermedios
    while(posGroup[i] != posGroup[fin])
    {
        int index = findIndex(posGroup[i], value);
        cont += index;
        i = ini[ posGroup[i] + 1 ];
    }
    // recorre el ultimo grupo
    while(i <= fin)
    {
        if(lista[i] < value)
        {
            cont ++;
        }
        i ++;
    }
    update(cont, u, ini, fin, posShange);
    return;
}
void build(){
    int index = 1;
    valueIni[index] = 1;
    for(int i = 1; i <= n; i++)
    {
        ordenadosPorBlok[index].Add(lista[i]);                   //lista rara
        posGroup[i] = index;
        if(i % rootList == 0)
        {
            ordenadosPorBlok[index].OrderByAscending();          //lista rara
            valueFin[index] = i;
            index++;
            valueIni[index] = i + 1;
        }
    }
    valueFin[index] = n;
    return;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".in", "r", stdin);

    cin >> n >> m >> u;
    rootList = sqrt(n);
    for(int i = 1; i <= n; i ++)
    {
        cin >> lista[i];
    }
    build();
    for(int i = 1; i <= m; i ++)
    {
        int L, R, v, p; cin >> L >> R >> v >> p;
        query(L, R, v, p);
    }
    for(int i = 1; i <= n; i ++)
    {
        cout << lista[i];
    }
    return 0;
}
