#include <iostream>
#include "895.hh"

int main()
{
    FreqStack fs;
    fs.push(7);
    fs.push(6);
    fs.push(2);
    fs.push(6);
    fs.push(3);
    fs.push(3);
    fs.pop();
    fs.push(2);
    fs.pop();
    fs.push(2);
    fs.pop();
    fs.push(5);
    fs.pop();
    fs.push(6);
    fs.pop();
    fs.pop();
    fs.pop();
    fs.pop();
    fs.pop();
    fs.pop();
}

