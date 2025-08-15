// #include<iostream>  // Basic import for input output
// To get relief of importing a lot of things, just use 
#include<bits/stdc++.h>

using namespace std;


int main(){
  // std::cout << "Hello Striver!" << "\n";
  // std::cout << "Hello Striver 2" << std::endl;
  
  // To remove std:: we can use using namespace std on top of the code!
  
  cout << "Hello again!"<<endl;

  // Integer
  int x, y;
  cin >> x >> y;
  cout << "The value of x is: " << x << " and y is: " << y << endl;

  // Integer has a limited range for storing values, typically -2,147,483,648 to 2,147,483,647 beyond that we need to use long long int
  long x = 121212121;

  long long y = 121212121212121212;
  cout << "The value of x is: " << x << " and y is: " << y << endl;


  // Next data-type is float and double
  // Float - single precision (typically 7 decimal digits)
  float a = 5.75;
  cout << "The value of a is: " << a << endl;

  // Double - double precision (typically 15 decimal digits)
  double b = 19.99;
  cout << "The value of b is: " << b << endl;

  // String and getline
  
  // We can not give space in string when we use cin
  string name;
  cout << "Enter your name: ";
  getline(cin, name);
  cout << "Hello, " << name << "!" << endl;

  // Character - It is initialized in single quotes
  char test = 'H';
  char initial;
  cout << "Enter your initial: ";
  cin >> initial;
  cout << "Your initial is: " << initial << endl;

  return 0;
}