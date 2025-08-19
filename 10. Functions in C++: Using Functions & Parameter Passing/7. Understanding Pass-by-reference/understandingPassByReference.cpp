#include<iostream>

using std::cout;
using std::endl;

//Example 1: This example is going to show how passing by reference will chnage the values of our variables not just inside of the functions we are calling, but also back inside of the main function when we get back inside of it.

void someFunction(int& intVar,
				 float& floatVar,
				 double& doubleVar,
				 char& charVar);

int main(){
  
  int intVar = 200;    // de
  float floatVar = 145.45f;
  double doubleVar = 128.2;
  char charVar = 'b';

  someFunction(intVar, floatVar, doubleVar, charVar);    // note that there is nothing in the way we are calling this function that implies that we are using references, the only way we know that we are using references is because of the signature up above that explicitly states we are using references

  cout << "intVar:" << intVar << endl;
  cout << "floatVar:" << floatVar << endl;
  cout << "doubleVar:" << doubleVar << endl;
  cout << "charVar:" << charVar << endl;
  
  return 0;
}

void someFunction(int& intVar, float& floatVar, double& doubleVar, char& charVar){

  cout << "Updating references to variables: " << endl;

  intVar += 200;        
  floatVar -= 20;
  doubleVar += 2;
  charVar = 'X';
}
