#include <bits/stdc++.h>
using namespace std;

int maxn = 1e5 + 5;
int lista[maxn], mul3PorBlok[maxn], sumaGrupal[maxn];
int valueIni[maxn], valueFin[maxn], posGroup[maxn];
int L, Q;
int rootList;

void update(int ini, int fin){
    int i = ini;
    int g;
    // recorre el primer grupo
    while(posGroup[i] == posGroup[ini] && posGroup[i] != posGroup[fin])
    {
        lista[i] ++;
        g = posGroup[i];
        if(lista[i] % 3 == 0)
        {
            mul3PorBlok[g] ++;
        }
        i ++;
    }
    // recorre los grupos intermedios
    while(posGroup[i] != posGroup[fin])
    {
        g = posGroup[i];
        sumaGrupal[g] ++;
        i ++;
    }
    // recorre el ultimo grupo
    while(i <= fin)
    {
        lista[i] ++;
        g = posGroup[i];
        if(lista[i] % 3 == 0)
        {
            mul3PorBlok[g] ++;
        }
        i ++;
    }

    return menor;
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
    {
        if((lista[i] + sumaGrupal[posGroup[i]]) % 3 == 0)
        {
            cont ++;
        }
        i ++;
    }
    // recorre los grupos intermedios
    while(posGroup[i] != posGroup[fin])
    {
        if(sumaGrupal[posGroup[i]] != 0)
        {
            mul3PorBlok[posGroup[i]] = 0;
            for(int j = valueIni[posGroup[i]]; j <= valueFin[posGroup[i]]; j++)
            {
                lista[j] += sumaGrupal[posGroup[i]];
                if(lista[j] % 3 == 0)
                {
                    mul3PorBlok[posGroup[i]] ++;
                }
            }
            sumaGrupal[posGroup[i]] = 0;
        }
        cont += mul3PorBlok[posGroup[i]];
        i = ini[ posGroup[i] + 1 ];
    }
    // recorre el ultimo grupo
    while(i <= fin)
    {
        if((lista[i] + sumaGrupal[posGroup[i]]) % 3 == 0)
        {
            cont ++;
        }
        i++;
    }
    return cont;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".in", "r", stdin);
    cin >> cases;
    for(int c = 1; c <= cases; c ++)
    {
        cin >> L >> Q;
        rootList = sqrt(L);
        for(int i = 0; i <= L; i++)
        {
            lista[i] = 0;
        }
        build();
        cout << "Case " << c << ":\n";
        for(int i = 1; i <= Q; i++)
        {
            int oper, a, b; cin >> oper >> a >> b;
            if(oper == 1)
            {
                cout << query(a, b) << "\n";
            }
            if(oper == 0)
            {
                update(a, b);
            }
            cin >> oper >> a >> b;
        }
    }
return 0;
}


/*You have an array with n elements which is indexed from 0 to n - 1. Initially all elements are zero.
Now you have to deal with two types of operations:
Increase the numbers between indices i and j (inclusive) by 1. This is represented by the command '0 i j'.
Answer how many numbers between indices i and j (inclusive) are divisible by 3. This is represented by the command '1 i j'.
Input:
      Input starts with an integer T (≤ 5), denoting the number of test cases.
      Each case starts with a line containing two integers n (1 ≤ n ≤ 105) and q (1 ≤ q ≤ 50000) denoting the number of queries.
      Each query will be either in the form '0 i j' or '1 i j' where i, j are integers and 0 ≤ i ≤ j < n.
Output:
      For each case, print the case number first. Then for each query in the form '1 i j', print the desired result.
