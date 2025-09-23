#include <iostream>
#include <string>

using std::cout;
using std::endl;

//Example 1: Example is made to show how c++ makes certain conversions that might not be what we want. For example, we are passing an int into the printValue function that is supposed to accept a double as a parameter. We could assume that this is possible because there is something under the hood that creates a temp variable that holds a refernce of the converted integer to a double. Conversion from int --> const double&. Alternatively, we see that when we try using squareValue, this does not work as we are attempting to go from a int --> double&. This gives us insight as to what c++ considers okay to convert, it only accepts it if it is going from int --> const double&

void printValue(const double& num);
double& squareValue(double& num);     //Return type is of a reference to a double. Input param is also a reference.

int main(){

  int intVar = 555;

  printValue(intVar);     // here we will see the conversion occur because it is a conversion from int --> const double&

  double result = squareValue(intVar);     // this will not work and we get an error. Conversion from int --> double&
  cout << result << endl;
  
  return 0;
}

void printValue(const double& num){
  cout << "___Number is: " << num << "___" << endl;
}

double& squareValue(double& num){
  num *= num;
  
  return num;
}
