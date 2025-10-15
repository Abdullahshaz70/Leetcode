#include<iostream>
using namespace std;

int fib(int n) {
        if(n<2) return n;
        int a = 0 , b = 1;
        for(int i = 2 ; i<=n ; i++){
            int next = a+b;
            a = b;
            b = next;
        }

        return b;
    }


    int main(){

        cout<<fib(10);

        return 0;
    }