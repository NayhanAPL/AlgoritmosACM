#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 * 3 + 5;
int lista[maxn];
vector<int> ordenadosPorBlok[maxn];
int valueIni[maxn], valueFin[maxn], posGroup[maxn];
int rootList;
int n, m, u;

int findIndex(int posGrupo, int value){
    int right = ordenadosPorBlok[posGrupo].size() - 1;
    int left = 0;
    int center = right / 2;
    while (left < right)
    {
        if(ordenadosPorBlok[posGrupo][center] >= value)
        {
            right = center - 1;
            center = (right + left) / 2;
        }
        if(ordenadosPorBlok[posGrupo][center] < value)
        {
            left = center + 1;
            center = (right + left) / 2;
        }
    }
    return center;
}
void update( int cont, int u, int ini, int fin, int posShange){
    int value = u * cont / (fin - ini + 1);
    lista[posShange] = value;
    int indexI = valueIni[posGroup[posShange]];
    int indexF = valueFin[posGroup[posShange]];
    ordenadosPorBlok[posGroup[posShange]].clear();
    for(int i = indexI; i <= indexF; i++)
    {
        ordenadosPorBlok[posGroup[posShange]].push_back(lista[i]);
    }
    sort(ordenadosPorBlok[posGroup[posShange]].begin(), ordenadosPorBlok[posGroup[posShange]].end());
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
        i = valueIni[ posGroup[i] + 1 ];
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
    return cont;
}
void build(){
    int index = 1;
    valueIni[index] = 1;
    for(int i = 1; i <= n; i++)
    {
        ordenadosPorBlok[index].push_back(lista[i]);
        posGroup[i] = index;
        if(i % rootList == 0)
        {
            sort(ordenadosPorBlok[index].begin(), ordenadosPorBlok[index].end());
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
        cout << lista[i] << "\n";
    }
    return 0;
}


/*Write a program to transform an array A[1], A[2], . . . , A[n] according to m instructions. Each instruction
(L, R, v, p) means: First, calculate how many numbers from A[L] to A[R] (inclusive) are strictly less
than v, call this answer k. Then, change the value of A[p] to u ∗ k/(R − L + 1), here we use integer
division (i.e. ignoring fractional part).
Input:
      The first line of input contains three integer n, m, u (1 ≤ n ≤ 300, 000, 1 ≤ m ≤ 50, 000, 1 ≤ u ≤
      1, 000, 000, 000). Each of the next n lines contains an integer A[i] (1 ≤ A[i] ≤ u). Each of the next
      m lines contains an instruction consisting of four integers L, R, v, p (1 ≤ L ≤ R ≤ n, 1 ≤ v ≤ u,
      1 ≤ p ≤ n).
Output:
      Print n lines, one for each integer, the final array.
