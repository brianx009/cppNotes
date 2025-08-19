#include<iostream>

using std::cout;
using std::endl;
using std::string;

//Example 1: Showing how we can define functions, and then use them in our main()
// void printHello(){    //void function
//   cout << "Hello!" << endl;
// }

// void printGoodbye(){    //void function that returns nothing as it is a void function -- completely acceptable.
//   cout << "Goodbye!" << endl;

//   return;
// }

// void printGreeting(string name){     //void function that takes in a parameter name
//   cout << "Howdy, " << name << "!" << endl;
// }

// string getGreeting(string name){    //function with return type of string -- if param and string in return were of different types, we would see a complier error
//   return "How do you do, " + name + " ?";
// }

// int main(){

//   cout << "-----Invoking printHello-----" << endl;
//   printHello();
  
//   cout << "-----Invoking printGoodbye-----" << endl;
//   printGoodbye();

//   cout << "-----Invoking printGreeting-----" << endl;
//   printGreeting("Brian");

//   cout << "-----Invoking getGreeting-----" << endl;
//   string greeting = getGreeting("Brian");     //notice here, when we return something, we need to store it somewhere before we use it.
//   cout << greeting << endl;    //stored in greeting variable, and then used cout to print to console.
  
//   return 0;
// }

//Example 2: shows how we can not have the definitions of our functions after the invoking of our function
// int main(){

//   cout << "-----Invoking printHello-----" << endl;
//   printHello();
  
//   cout << "-----Invoking printGoodbye-----" << endl;
//   printGoodbye();

//   cout << "-----Invoking printGreeting-----" << endl;
//   printGreeting("Brian");

//   cout << "-----Invoking getGreeting-----" << endl;
//   string greeting = getGreeting("Brian");     //notice here, when we return something, we need to store it somewhere before we use it.
//   cout << greeting << endl;    //stored in greeting variable, and then used cout to print to console.
  
//   return 0;
// }

// void printHello(){    //void function
//   cout << "Hello!" << endl;
// }

// void printGoodbye(){    //void function that returns nothing as it is a void function -- completely acceptable.
//   cout << "Goodbye!" << endl;

//   return;
// }

// void printGreeting(string name){     //void function that takes in a parameter name
//   cout << "Howdy, " << name << "!" << endl;
// }

// string getGreeting(string name){    //function with return type of string -- if param and string in return were of different types, we would see a complier error
//   return "How do you do, " + name + " ?";
// }

//Example 3: Showing we can have our definitions of our functions after the invoking only if there is a declaration before the invoking. Acceptable orders go: Declaration -> Invoking -> Definition, Definition -> Invoking

void printHello();    //Declarations/ Signatures of functions
void printGoodbye();
void printGreeting(string name);    //using the actual parameter name for the signature
string getGreeting(string);    //showing that we don't have to pass the parameter name -- optional.

int main(){

  cout << "-----Invoking printHello-----" << endl;
  printHello();
  
  cout << "-----Invoking printGoodbye-----" << endl;
  printGoodbye();

  cout << "-----Invoking printGreeting-----" << endl;
  printGreeting("Brian");

  cout << "-----Invoking getGreeting-----" << endl;
  string greeting = getGreeting("Brian");     //notice here, when we return something, we need to store it somewhere before we use it.
  cout << greeting << endl;    //stored in greeting variable, and then used cout to print to console.
  
  return 0;
}

void printHello(){    //void function
  cout << "Hello!" << endl;
}

void printGoodbye(){    //void function that returns nothing as it is a void function -- completely acceptable.
  cout << "Goodbye!" << endl;

  return;
}

void printGreeting(string name){     //void function that takes in a parameter name
  cout << "Howdy, " << name << "!" << endl;
}

string getGreeting(string name){    //function with return type of string -- if param and string in return were of different types, we would see a complier error
  return "How do you do, " + name + " ?";
}
