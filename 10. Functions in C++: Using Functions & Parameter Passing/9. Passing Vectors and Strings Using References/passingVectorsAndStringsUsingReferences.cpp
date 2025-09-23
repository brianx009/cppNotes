#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

//Example 1: Example is used to show how we can make a function very intentionally not make copies of objects and how we can reference them in order to save on space and time for our application. Passing in a "const" argument, we are ensuring that whoever uses the function will not be able to 1) Modify the original values and 2) ensures that the application will not spend time making copies of large vectors when it does not have to
// struct Person {

//   string name;
  
//   Person(string n) : name(n) {}
// };

// void printNames(const vector<Person>& personVector);    // it is important that we are making this a const reference to a container of people because if not then when our function is invoked, it would be a pass by value that creates a copy of the persons vector -- which in turn means our program is taking a huge performance hit -- we would have to construct the vector, copies of the different objects would have to be constructed, and then their constructors would also have to be invoked, and then when they exit the function call -- all of their destructors would be called


// int main(){
//   vector<Person> personVector{Person("Brian1"), Person("Brian2"), Person("Brian3")};    //using braced initializer to populate our vector

//   printNames(personVector);    //invoking printNames as a REFERENCE

//   return 0;
// }

// void printNames(const vector<Person>& personVector){    //

//   for(const Person& person : personVector){    //range based for loop that also passes a const reference -- use of the const reference is the
// 	                                           //correct way to do this as we we are ensuring that person is not created by value -- we are not
// 	                                           //creating a copy of each element of the vector, that would be very time consuming.
// 	cout << person.name << endl;
//   }
  
//   //  for(int i = 0; i < personVector.size(); ++i){    //regular for loop that seems to get the same behavior as above.
//   //  	cout << personVector[i].name << endl;    //we are accessing the original vector, not creating a copy -- this is okay
//   //  }

//   //                                                    //even better version if we decide not to use range-based for loop

//   //  for(std::size_t = 0; i < personVector.size(); ++i){    //use of std::size_t because .size() returns  a std::size_t and if at any point the
//   // 	                                                      //and if we had enough values in the vector, it could overflow int (unlikely to happen
//   // 	                                                      // in practice but this can lead to undefined behavior/ warning in real life apps.)

//   // 	 const Person& person = personVector[i];    // here we are ensuring that no copies are being made -- we get the same expected behavior
//   // 	 cout << person.name << endl;               //as the range- based for loop
//   // }
// }


//Example 2: This just shows how we could print out strings -- nothing too impressive
// void formatAndPrint(string& firstName, string& lastName, string& city);

// int main(){

//   string fName = "Brian";
//   string lName = "Saldana";
//   string city = "Brian's City";

//   formatAndPrint(fName, lName, city);
  
//   return 0;
// }

// void formatAndPrint(string& firstName, string& lastName, string& city){

//   string formattedString = "*First Name: " + firstName + "*\n" +     // to line up strings perfectly you can use setw from #include <iomanip>
// 	"*Last Name: " + lastName + "*\n" + "*City: " + city + "*\n";

//   cout << formattedString << endl;;
  
// }

//Example 3: Building on example 2, we show that when we try to pass in string literals into the function directly, we get an error message when attempting to compile -- why is this ? This is because our function is attempting to take a reference of something that is being passed in as a literal -- it will however work if we change the functions reference parameters to const reference parameters -- this is because by definition a string literal should be immutable.
// void formatAndPrint(string& firstName, string& lastName, string& city);

// int main(){

//   // string fName = "Brian";
//   // string lName = "Saldana";
//   // string city = "Brian's City";

//   formatAndPrint("Brian", "Saldana", "Brian's City");
  
//   return 0;
// }

// void formatAndPrint(string& firstName, string& lastName, string& city){

//   string formattedString = "*First Name: " + firstName + "*\n" +     // to line up strings perfectly you can use setw from #include <iomanip>
// 	"*Last Name: " + lastName + "*\n" + "*City: " + city + "*\n";

//   cout << formattedString << endl;;
  
// }

//Example 4: Changing reference string to const reference string in function -- and despite us having the desired output to the console, we have to note that under the hood we might be having a behavior that is not wanted. What do we mean by that? -- because we are passing in string literals, c++ has to create a temporary variable with the strig literal values that we are passing in,then it is making a const reference to that temporary string object that was created. The whole point of wanting to use "const references" is so we dont make copies or create anything extra, but here we are creating extra temp objects.
// void formatAndPrint(const string& firstName, const string& lastName, const string& city);

// int main(){

//   // string fName = "Brian";
//   // string lName = "Saldana";
//   // string city = "Brian's City";

//   formatAndPrint("Brian", "Saldana", "Brian's City");
  
//   return 0;
// }

// void formatAndPrint(const string& firstName, const string& lastName, const string& city){

//   string formattedString = "*First Name: " + firstName + "*\n" +     // to line up strings perfectly you can use setw from #include <iomanip>
// 	"*Last Name: " + lastName + "*\n" + "*City: " + city + "*\n";

//   cout << formattedString << endl;;
  
// }

//Example 5: Building off of Example 4, there is a solution C++ 17 has implemented that helps us not create temporary objects -- std::string_view -- this is a new type that is exactly identical to a string, except it is entirely const ! -- keep note that although it is very similar to a string, it is missing some overloaded operators (we can not use the + operator to concatonate strings). So the work around is to stream it directly to cout with <<.
void formatAndPrint(std::string_view firstName, std::string_view lastName, std::string_view city);

int main(){
  // string fName = "Brian";
  // string lName = "Saldana";
  // string city = "Brian's City";

  formatAndPrint("Brian", "Saldana", "Brian's City");
  
  return 0;
}

void formatAndPrint(std::string_view firstName, std::string_view lastName, std::string_view city){

  cout << "*First Name: " << firstName << "*\n" <<
	"*Last Name: " << lastName << "*\n" << "*City: " << city << "*\n";
  
>>>>>>> Stashed changes
}
