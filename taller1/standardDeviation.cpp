/*Calcular la desviación estándar de los primeros números impares enteros positivos.*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long int n;
    double root, deviation;

    while(cin>>n && n != 0){
        root = ((double)n*((double)n + 1))/(double)3;
        deviation = sqrt(root);

        cout<<fixed<<setprecision(6)<<deviation<<endl;
    }

    return 0;
}