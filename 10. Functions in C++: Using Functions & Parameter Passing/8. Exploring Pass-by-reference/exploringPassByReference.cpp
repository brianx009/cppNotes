#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

// Example 1: Purpose of example is to show how we could use our custom objects and also pass them by reference. This helps show us that not only will the function call update the name inside of the function, but it will also update it in our main function because of the pass by reference with &

// struct Person{
//   string name;

//   Person(string n): name(n) {}    // constructor that will set .name to the string that is passed in when constructing the Person object.
// };

// void updateName(Person& person);

// int main(){

//   Person person("OldBrian");     //object called person with the name member variable being set to OldBrian

//   cout << "Person's name before functions call: " << person.name << endl;

//   updateName(person);     //calling updateName that passes in a reference to our person obj

//   cout << "Person's name after functions call: " << person.name << endl;     // prints out NewBrian as our funciton call was pass by reference

  
//   return 0;
// }

// void updateName(Person& person){
  
//   cout << "Inside of function updateName" << endl;
  
//   person.name = "NewBrian";     // updating our person obj to NewBrian
// }

// Example 2: Sometimes we might be using library functions where we might not be aware of whether or not they are using references, so this example below is a way we could check if a library function is of reference type or not because otherwise we might pass in a variable whos value we do not want changed and end up with a obj/ value that is now changed/ updated

struct Person{
  string name;

  Person(string n): name(n) {}    // constructor that will set .name to the string that is passed in when constructing the Person object.
};

void updateName(const Person& person);    //if we are the ones creating the function, we could make this explict by passing in a const reference instead of a regular referemce

int main(){

  Person person("OldBrian");     //object called person with the name member variable being set to OldBrian

  cout << "Person's name before functions call: " << person.name << endl;

  updateName(person);     //calling updateName that passes in a reference to our person obj

  cout << "Person's name after functions call: " << person.name << endl;     // prints out NewBrian as our funciton call was pass by reference

  
  return 0;
}

void updateName(const Person& person){
  
  cout << "Inside of function updateName" << endl;
  
  person.name = "NewBrian";     // this should now give us an error as we are not allowed to change the value of our const param -- we are only allowed to read from it. -- we have now made this explicitly known that we are not looking to modify our referenced parameter.
}
