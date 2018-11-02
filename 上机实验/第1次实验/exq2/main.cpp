/*
 * Filename:main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-27
 */
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    double a;
    double x0;
    double sum=0;

    cin>>n>>x0;
    for(int i=0;i<=n;i++){
        cin>>a;
        sum += a * pow(x0, i);
    }
    cout<<sum<<endl;
    return 0;
}