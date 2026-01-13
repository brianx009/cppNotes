#include<iostream>
#include<string>

using std::cout;
using std::string;
using std::endl;

///Example 1: This example is to show that strings are passed by value, just as the previous one was in Lesson 3. 
//We could see that we create a struct/class of a person, which we then make use of inside of int main as we create 
//a Person object with the name "Brian", then we call the function updateName that is meant to modify the object 
//person that we have created. It does so successfully inside of the function updateName, but when we go back into 
//int main, because it was passed by value, it will not update the original object, it will only modify it inside 
//of the function, resulting in the ./a.out to print out Brian twice instead of Brian and then updateName Brian. 
//Another very interesting thing to note is when you run this program in gdb, when you get to updateName function 
//inside of int main and then step into it, it takes us to the struct vs the updateName function. But if we think 
//about it, this further helps us understand that it is bieng passed by value and not reference. That function call 
//literally creates another Person object to work on, then updates the name. This is the behavior we would expect 
//from something that is being passed by value vs reference.

struct Person{
  string name;     //member variable
  
  Person(string n): name(n) {}
};

void updateName(Person person);     //signature for function updateName

int main(){
  Person person("Brian");     // Object person created and initializing name to string

  cout << "Persons name is: " << person.name << endl;     //becasue person is a object (not a pointer to a object), and name is a member variable (not a member function), we call it with the ._memberVariable_ notation

  updateName(person);     //calling updateName function by passing in person as a value, not a reference

  cout << "Persons name after updateName is: " << person.name << endl;     //prints out Brian again, BOOOOOO THAT STINKS
  
  return 0;
}

void updateName(Person person){
  person.name = "updateName Brian";     //this will only update the object inside of this function, not anywhere else.
}
