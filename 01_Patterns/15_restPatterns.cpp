#include<bits/stdc++.h>
using namespace std;

void print15(int n){
  for(int i = 0; i < n; i++){
    for(char ch = 'A'; ch <= 'A' + n-1-i; ch++){
      cout << ch << " ";
    }
    cout << endl;
  }
}

void print16(int n){
  char c = 'A';
  for(int i = 0; i < n; i++){
    for(int j = 0; j < i+1; j++){
      cout << c << " ";
    }
    c++;
    cout << endl;
  }
}

void print17(int n){
  for(int i = 0; i < n; i++){
    // space
    for(int j = 0; j < n-1-i; j++){
      cout << " ";
    }
    // character
    char ch = 'A';
    int breakpoint = (2*i+1)/2;
    for(int j = 0; j <2*i+1; j++){
      cout << ch;
      if(j <= breakpoint){
        ch++;
      } else {
        ch--;
      }
    }

    // space
    for(int j = 0; j < n-1-i; j++){
      cout << " ";
    }
    cout << endl;
  }
}

void print18(int n){
  for(int i = 0; i < n; i++){
    for(char ch = 'E' - i; ch <= 'E'; ch++){
      cout << ch;
    }
    cout << endl;
  }
}

void print19(int n) {
  
  int initialSpace = 0;
  for(int i = 0; i < n; i++){
    // stars
    for(int j = 1; j <= n-i; j++){
      cout << '*';
    }

    // sapce

    for(int j = 0; j < initialSpace; j++){
      cout << ' ';
    }

    // stars
    for(int j = 1; j <= n-i; j++){
      cout << '*';
    }
    initialSpace+=2;
    cout << endl;
  }  
  int space = 2*n-2;
  for(int i = 1; i <=n; i++){
    // stars
    for(int j = 1; j <= i; j++){
      cout << '*';
    }

    // space

    for(int j = 0; j < space; j++){
      cout << ' ';
    }

    // stars
    for(int j = 1; j <= i; j++){
      cout << '*';
    }
    space-=2;
    cout << endl;

  }
  
}

void print20(int n){
  int spaces = 2*n-2;
  for(int i = 1; i <= 2*n-1; i++){
    int stars = i;
    if(i > n) stars = 2*n-i;

    // stars

    for(int j = 1; j <= stars; j++){
      cout << '*';
    }

    // space

    for(int j = 1; j <= spaces; j++){
      cout << ' ';
    }

    // stars
    for(int j = 1; j <= stars; j++){
      cout << '*';
    }
    cout << endl;
    if (i < n) spaces -= 2;
    else spaces += 2;
  }
  
}

void print21(int n){
  // Printing a square with * on its boundary
  for(int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if(i == 0 || j == 0 || i == n-1 || j == n-1){
        cout << '*';
      } else {
        cout << ' ';
      }
    }
    cout << endl;
  }
}

void print22(int n){
  for(int i = 0; i < 2*n-1; i++){
    for (int j = 0; j < 2*n-1; j++){
      int top = i;
      int left = j;
      int right = (2*n-2) - j;
      int down = (2*n-2) - i;
      cout << (n - min(min(top,down), min(left, right)));
    }
    cout << endl;
  }
}

int main(){
  print22(5);
  return 0;
}