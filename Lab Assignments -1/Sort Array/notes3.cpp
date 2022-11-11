#include <iostream>
using namespace std;
int* sort (int N1, int N2, int N3);
int* sort (int N1, int N2, int N3){
	int max = 0, min = 0, middle = 0;
	int* myArray = (int*) malloc (3 * sizeof(int));
	if (N1 >= N2 && N1>= N3){
		max = N1;
		if(N2 >= N3){
			middle = N2;
			min = N3;
		}
		else{
			middle = N3;
			min = N2;
		}
	}
	if (N2 >= N1 && N2 >= N3){
		max = N2;
		if(N1 >= N3){
			middle = N1;
			min = N3;
		}
		else{
			middle = N3;
			min = N1;
		}
	}
	if(N3 >= N2 && N3 >=N1){
		max = N3;
		if (N1 >= N2){
			middle = N1;
			min = N2;
		}
		else{
			middle = N2;
			min = N1;
		}
	}
	myArray[0] = min;
	myArray[1] = middle;
	myArray[2] = max;
	return myArray;
}
int main(){
	int N1, N2, N3;
	cout<< "Please enter three integers: ";
	cin>> N1 >> N2 >> N3;
	int* myArray = sort(N1,N2,N3);//call the function
	cout<< "My Array is: [ " <<myArray[0] <<", "<<myArray[1] << ", "<<myArray[2]<<" ]"<<endl;
	int average = 0;
	average = (N1 + N2 + N3) / 3;
	cout<<"Your average is: "<<average<<endl;
}



