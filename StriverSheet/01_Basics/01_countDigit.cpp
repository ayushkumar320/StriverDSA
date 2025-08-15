#include<iostream>
using namespace std;

class Solution {
public:
    int countDigit(int n) {
        int numOfDigit = 0;
        while(n){
            n = n/10;
            numOfDigit++;
        }
        return numOfDigit;
    }  
};