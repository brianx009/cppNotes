#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

//Example 1: Shows that we have local variables created inside of main, and then inside the function someFunction, since we are passing by value, we are creating another instance of the values local to someFunction. So when we cout inside of int main, instead of getting the updated values, we get the old local unupdated values inside of int main. If running with GDB, you can step through the program and step into the function call and see that the function is updating the values inside of the function, but does not use these updated values.
//Running GDB:
//1) Compile program: c++ -g 'program_name'
//2) Run gdb on executable: lldb ./'executable_name'
//3) Set breakpoints: b 15
//4) Run Program in gdb: r
//5) Go through program line by line: n
//6: Step into function: s
//7: List variables: vo

// void someFunction(int, float, double, char);

// int main(){

//   int intVariable = 200;
//   float floatVariable = 3456.789;
//   double doubleVariable = 128.2;
//   char charVariable = 'A';

//   someFunction(intVariable, floatVariable, doubleVariable, charVariable);

//   cout << "Int Variable: " << intVariable << endl;
//   cout << "Float Variable: " << floatVariable << endl;
//   cout << "Double Variable: " << doubleVariable << endl;
//   cout << "Char Variable: " << charVariable << endl;
  
//   return 0;
// }

// void someFunction(int intVariable, float floatVariable, double doubleVariable, char charVariable){
//   cout << "Update local copies of variables" << endl;

//   intVariable += 200;
//   floatVariable -= 20;
//   doubleVariable *= 2;
//   charVariable = 'X';
// }

//Example 2: Showing how pass by value works with objects
void updateCountry(string countryName);
void makeCountryUpperCase(string countryName);

int main(){

  string countryName = "India";
  updateCountry(countryName);

  cout << "Country Name after updateCountryName call: " << countryName << endl;

  makeCountryUpperCase(countryName);

  cout << "Country Name after makeCountryUpperCase call: " << countryName << endl;
  
  return 0;
}

void updateCountry(string countryName)
{
  cout << "Inside of updateCountry function" << endl; 
  countryName = "California";
}

void makeCountryUpperCase(string countryName)
{
  cout << "Inside of makeCountryUpperCase function" << endl; 
  for (int i = 0; i < countryName.length(); ++i){
	countryName[i] = std::toupper(countryName[i]);
  }
}
