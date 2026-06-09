#include <iostream>
using namespace std;

#define MAX 10000

struct Book {
    char title[MAX];
    char author[MAX];
    int price;
};

int main() {
    Book b1 = {"Book 1", "Alex", 100}, b2 = {"Book 2", "John", 200};
    printf("%s is written by %s and is priced at %c.", b1.title, b1.author, b1.price);
    printf("%s is written by %s and is priced at %c.", b2.title, b2.author, b2.price);
}