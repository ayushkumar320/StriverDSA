# Basic
- when a function calss itself until a specified condition is met
```cpp
void f(){
    print('hello')
    f()
main(){
    f() // this function call himself infinte time
    return 0
// hello will be printed infinte time
}
}
```
- StackOverflow-> runninng of the memory
- Base condition -> cond use to control recursion
example
```cpp
cut = 0
void f(){
    if(cut ==4) // control the flow of recurssion
        return;
    print(cut)
    cut++
    f()
}
main(){
    f()
}
```
- BackTracking -> first recursion is completed the code is executed