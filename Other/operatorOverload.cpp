#include <iostream>
using namespace std;

struct Number
{
    int value;

    Number(int v)
    {
        value = v;
    }

    // Overload + operator
    Number operator+(const Number &n)
    {
        return Number(value + n.value);
    }

    void display()
    {
        cout << value << endl;
    }
};

int main() {

}