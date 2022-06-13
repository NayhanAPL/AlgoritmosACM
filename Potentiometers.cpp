#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int lista[maxn], sumPorBlok[maxn];
int valueIni[maxn], valueFin[maxn], posGroup[maxn];
int rootList, L;

void update(int pos, int val){
    int g = posGroup[pos];
    lista[pos] = val;
    sumPorBlok[g] = 0;
    for(int i = valueIni[g]; i <= valueFin[g]; i++)
    {
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
    {
        suma += lista[i]; i ++;
    }
    // recorre los grupos intermedios
    while(posGroup[i] != posGroup[fin])
    {
        suma += sumPorBlok[ posGroup[i] ];
        i = valueIni[ posGroup[i] + 1 ];
    }
    // recorre el ultimo grupo
    while(i <= fin)
    {
        suma += lista[i]; i++;
    }
    return suma;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int cases = 1;
    cin >> L;
    while(L != 0)
    {
        rootList = sqrt(L);
        for(int i = 1; i <= L; i++)
        {
            cin >> lista[i];
        }
        build();
        cout << "Case " << cases << ":\n";
        int a, b;
        string oper; cin >> oper;
        while(oper != "END")
        {
            cin >> a >> b;
            if(oper == "M"){cout << query(a, b) << "\n";}
            if(oper == "S")
            {
                update(a, b);
            }
            cin >> oper;
        }
        cin >> L;
        cases ++;
    }
    return 0;
}


/*A potentiometer, or potmeter for short, is an electronic device with a variable electric resistance. It
has two terminals and some kind of control mechanism (often a dial, a wheel or a slide) with which the
resistance between the terminals can be adjusted from zero (no resistance) to some maximum value.
Resistance is measured in Ohms, and when two or more resistors are connected in series (one after the
other, in a row), the total resistance of the array is the sum of the resistances of the individual resistors.
In this problem we will consider an array of N potmeters, numbered 1 to N from left to right. The
left terminal of some potmeter numbered x is connected to the right terminal of potmeter x − 1, and
its right terminal to the left terminal of potmeter x + 1. The left terminal of potmeter 1 and the right
terminal of potmeter N are not connected.
Initially all the potmeters are set to some value between 0 and 1000 Ohms. Then we can do two
things:
      • Set one of the potmeters to another value.
      • Measure the resistance between two terminals anywhere in the array.
Input:
      The input consists less than 3 cases. Each case starts with N , the number of potmeters in the array,
      on a line by itself. N can be as large as 200000. Each of next N lines contains one numbers between 0
      and 1000, the initial resistances of the potmeters in the order 1 to N . Then follow a number of actions,
      each on a line by itself. The number of actions can be as many as 200000. There are three types of
action:
      • “S x r” - set potmeter x to r Ohms. x is a valid potmeter number and r is between 0 and 1000.
      • “M x y” - measure the resistance between the left terminal of potmeter x and the right terminal
      of potmeter y. Both numbers will be valid and x is smaller than or equal to y.
      • “END” - end of this case. Appears only once at the end of a list of actions.
      A case with N = 0 signals the end of the input and it should not be processed.
Output:
      For each case in the input produce a line ‘Case n:’, where n is the case number, starting from 1.
      For each measurement in the input, output a line containing one number: the measured resistance
      in Ohms. The actions should be applied to the array of potmeters in the order given in the input.
      Print a blank line between cases.
      Warning: Input Data is pretty big (∼ 8 MB) so use faster IO.
