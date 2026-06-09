#include <iostream>
#include <vector>
using namespace std;

int temp;

class die {
    private:
        int top = 1, front = 2, left = 3, back = 5, right = 4, bottom = 6;
    public:
        void F() {
            temp = top;
            top = back;
            back = bottom;
            bottom = front;
            front = temp;
        }
        void B() {
            temp = top;
            top = front;
            front = bottom;
            bottom = back;
            back = temp;
        }
        void L() {
            temp = top;
            top = right;
            right = bottom;
            bottom = left;
            left = temp;
        }
        void R() {
            temp = top;
            top = left;
            left = bottom;
            bottom = right;
            right = temp;
        }
        void C() {
            temp = front;
            front = right;
            right = back;
            back = left;
            left = temp;
        }
        void D() {
            temp = front;
            front = left;
            left = back;
            back = right;
            right = temp;
        }
        int GetFront() {
            return front;
        }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int diceCount, i, j;
    string movement;
    vector<int> res;

    cin >> diceCount;
    for (i=0; i<diceCount; i++) {
        cin >> movement;
        die newDie;
        for (j=0; j<movement.length(); j++) {
            if (movement[j] == 'F') newDie.F();
            else if (movement[j] == 'B') newDie.B();
            else if (movement[j] == 'L') newDie.L();
            else if (movement[j] == 'R') newDie.R();
            else if (movement[j] == 'C') newDie.C();
            else if (movement[j] == 'D') newDie.D();
        }
        res.push_back(newDie.GetFront());
    }
    for (int r : res) {
        cout << r << " ";
    }
}