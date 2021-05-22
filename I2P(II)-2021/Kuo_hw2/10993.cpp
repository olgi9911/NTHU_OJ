#include <iostream>
#include <stdio.h>
#include <string>
#include "10993.h"
//#include "function.h"
using namespace std;

Polynomial::Polynomial(){
    greatestPower = 0;
    for(int i = 0; i < 51; i++) coefficients[i] = 0;
}

Polynomial::Polynomial(const int greatest, const int cof[51]){
    greatestPower = greatest;
    for(int i = 0; i < 51; i++) coefficients[i] = i > greatest ? 0 : cof[i];
}

Polynomial Polynomial::add(const Polynomial next) const{
    Polynomial temp;
    temp.greatestPower = max(greatestPower, next.greatestPower);
    for(int i = temp.greatestPower; i >= 0; i--)
        temp.coefficients[i] = coefficients[i] + next.coefficients[i];
    /*
    for(int i = temp.greatestPower; temp.coefficients[i] == 0; i--)
        temp.greatestPower --;
    */
    return temp;
}

Polynomial Polynomial::subtract(const Polynomial next) const{
    Polynomial temp;
    temp.greatestPower = max(greatestPower, next.greatestPower);
    for(int i = temp.greatestPower; i >= 0; i--)
        temp.coefficients[i] = coefficients[i] - next.coefficients[i];
    
    /*for(int i = temp.greatestPower; temp.coefficients[i] == 0; i--)
        temp.greatestPower --;
    */
    return temp;
}

Polynomial Polynomial::multiplication(const Polynomial next) const{
    Polynomial temp;
    temp.greatestPower = greatestPower + next.greatestPower;
    for(int i = 0; i <= greatestPower; i++){
        for(int j = 0; j <= next.greatestPower; j++){
            temp.coefficients[i+j] += coefficients[i] * next.coefficients[j];
        }
    }
    /*for(int i = temp.greatestPower; temp.coefficients[i] == 0; i--)
        temp.greatestPower--;
    */
    return temp;
}

void Polynomial::output() const{
    for(int i = greatestPower; i >= 0; i--){
        cout << coefficients[i];
        if(i != 0) cout << ' ';
    }
}

int main()
{
    int greatestPower1, greatestPower2;
    int coefficient1[51], coefficient2[51];
    Polynomial ans;

    cin>>greatestPower1;
    for(int i = greatestPower1 ; i >= 0; i--)
    {
        cin>>coefficient1[i];
    }
    cin>>greatestPower2;
    for(int i = greatestPower2 ; i >= 0 ; i--)
    {
        cin>>coefficient2[i];
    }
    Polynomial a(greatestPower1, coefficient1), b(greatestPower2, coefficient2) ;

    ans = a.add( b );
    ans.output();
    cout << endl;

    ans = a.subtract( b );
    ans.output();
    cout << endl;

    ans = a.multiplication( b );
    ans.output();
    cout << endl;

} // end main
