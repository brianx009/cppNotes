#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

//Example to show us that we are not allowed to modify const references, but we are able to get around this by modifyig the original name, which will modify the const reference
// int main(){

//   string name = "Brian";
//   const string& nameRef = name;

//   cout<< "Original Name: " << name << endl;

//   name = "Modifying const nameRef through name";     //this does not cause an error when copiling as we are modifying a non-const variable.
  
//   cout << "Updated Name: " << nameRef << endl;
  
//   return 0;
// }

//Example to show that we could avoid the behavior in the up above example by setting both name and nameRef as const. No more cheeky variable value changing when it is labeled as const.
// int main(){

//   const string name = "Brian";
//   const string& nameRef = name;

//   cout<< "Original Name: " << name << endl;

//   name = "Modifying const nameRef through name";     //this causes an error when copiling as we are attempting to modify a const reference.
  
//   cout << "Updated Name: " << nameRef << endl;
  
//   return 0;
// }

//From the first example we proved we could access/ modify a const reference through the original variable we are working with, but here we want to show that if we tried modifying a const variable through a not const reference,  it simply would not work.
// int main(){

//   const string name = "Brian";
//   string& nameRef = name;     //this fails when compiling as we are trying to bind a value of type const string to a value of type string -- this is invalid as it is attempting to drop the const qualifier

//   return 0;
// }


//Example is to show that we could make the example above work by using const_cast. By doing so we are able to modify nameRef and name regardless of name being const. Seeing const_cast is very useful as it'll let us know that whoever is writting this code is very intentionally trying to cast away the const-ness of a variable and return  variable that is of type string&
// int main(){
  
//   const string name = "Brian";
//   string& nameRef = const_cast<string&>(name);     // nameRef is not const, but it is assigned the const cast of name

//   cout << "Original Name: " << name << endl;

//   nameRef = "Updating Brian through nameRef with const_cast";

//   cout << "Updated  NameRef: " << nameRef << endl;
//   cout << "Updated Name: " << name << endl;

  
  
//   return 0;
// }

//Example to show that a const reference is the best thing ot use when we are iterating with a range based for loop as it'll guarantee that we are not modifying data that should stay constant
// int main(){
//   vector<string> cities {"New York", "Seattle", "Boston", "Austin"};

//   for (const auto& city : cities){      //using a range based for loop that is taking the CONST REFERENCE of a vector
//     city[0] = std::tolower(city[0]);     //fails because we can not modify const data
//     city[1] = std::toupper(city[1]);     //fails because we can not modify const data

//     cout << city << endl;
//   }

  
//   return 0;
// }

//Example to show that a const vector could still be modified by using const_cast -- NOT RECOMMENDED EVER (but very cool that we could hack away at things that we shouldn't be allowed to hehe)
int main(){
  const vector<string> cities {"New York", "Seattle", "Boston", "Austin"};     //Const vector

  auto& modifiableCities = const_cast<vector<string>&>(cities);     // const cast to remove constness
  
  for (auto& city : modifiableCities){      //using a range based for loop that is taking the CONST REFERENCE of a vector
    city[0] = std::tolower(city[0]);     //works because we removed constness
    city[1] = std::toupper(city[1]);     //works because we removed constness

    cout << city << endl;
  }

  
  return 0;
}





