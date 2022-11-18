// Abil Shrestha
    void recursePrint(int n) 
    {
    if (n != 0){
    // Line 1
        cout<< "Hip\n"; //Line 2
        recursePrint(n - 1); // 3
        }
        else
        cout<< "Horray!"; // 4
    }
    /*
    a) What is the base case?
    The base case is 
    cout<<”Horray!”;
    b) What is the recursive case?
    The recursive case is 
    {
    
    cout<< "Hip\n"; //Line 2
    
    recursePrint(n - 1); // 3
    c) How many times is recursePrint called if the line:
    recursePrint(4);
    is in the main program?
    recursePrint is called 4 times meaning hip will be printed 4 times and then 
    horray
    }
    */

    /* Print a pyramid using recursive functions like this: */
 
    #include <iostream>
    void printPyramid(int i,int rows);
    using namespace std;
    void printPyramid(int i,int rows) {
    
    if(i>rows) // base case
    
    return;
    
    for(int space=1; space<=rows-i; ++space)
    
    {
    
    cout<<" "; //spaces
    
    }
    
    for (int j = 1; j <= i; j++) {
    
    printf("%4d", i); //making sure the spacing is good
    
    }
    
    cout<<endl;
    
    printPyramid(i+1,rows); //recursion is happening here 
    
    }
    int main()
    {
    
    int n;
    
    cout<<"up to which number do u want to print the pyramid?";
    
    cin>>n;
    
    printPyramid(1,n); //function call
    
    return 0;
    }