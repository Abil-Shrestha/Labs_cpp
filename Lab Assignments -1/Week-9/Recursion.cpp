#include <iostream>
using namespace std;

int Fibonacci(int n) {
   
    if((n==1)||(n==0))
    {
        return(n);
    }
    else if(n<0){
       return -1;
    }
    else
    {
        return(Fibonacci(n-1)+Fibonacci(n-2));
    }
}

int main() {
   int startNum;
   cin >> startNum;  
   cout << "Fibonacci(" << startNum << ") is " << Fibonacci(startNum) << endl;
   return 0;
}
