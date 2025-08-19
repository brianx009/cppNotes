#include<iostream>

using std::cout;
using std::endl;
using std::flush;

//basic program that will allow us to visualize how a reference of a varaible works
int main(){

  int unitSales = 102;
  int& unitSalesRef = unitSales;     //we can not declare a reference without assigning it a value or else it will not work
                                     //wiht pointers we could decalre it and set it to null, we are not allowed to do this with references

  cout << "Original (unitSales): " << unitSales << endl << flush;
  cout << "Referecnce (unitSalesRef) : " << unitSalesRef << endl;     //reference to a int
                                                                      //note that unlike pointers where you could redeclare the pointer as another type, using references only allows us to to be of type int when we created it.

  cout << "-----Updating unitSales variable using reference-----" << endl;
  unitSalesRef = 266;

  cout << "Updated unitSales variable: " << unitSales << endl;
  cout << "Updated unitSalesRef variable: " << unitSalesRef << endl;
  
  return 0;
}
