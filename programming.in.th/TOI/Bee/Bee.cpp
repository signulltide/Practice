#include <iostream>
#include <vector>
using namespace std;

vector<int> worker, soldier;

void Queen(int year, int terminate, int request), Worker(int year, int terminate, int request), Soldier(int year, int terminate, int request);

void Queen(int year, int terminate, int request) {
    if (year == terminate) return;
    //printf("[%d] Queen Offspring\n", year);
    Queen(year + 1, terminate, request);
    Worker(year + 1, terminate, request);
}

void Worker(int year, int terminate, int request) {
    worker[request]++;
    //printf("[%d] New Worker\n", year);
    if (year == terminate) return;
    //printf("[%d] Worker Offspring\n", year);
    worker[request]--;
    Worker(year + 1, terminate, request);
    Soldier(year + 1, terminate, request);
}

void Soldier(int year, int terminate, int request) {
    soldier[request]++;
    //printf("[%d] New Soldier\n", year);
    if (year == terminate) return;
    //printf("[%d] Soldier Offspring\n", year);
    soldier[request]--;
    Worker(year + 1, terminate, request);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int input = 0, i;
    vector<int> requests;
    while (true) {
        cin >> input;
        if (input != -1) {
            requests.push_back(input);
            worker.push_back(0); soldier.push_back(0);
        } else {
            break;
        }
    }
    for (i=0; i<requests.size(); i++) {
        Queen(0, requests.at(i), i);
        Worker(0, requests.at(i), i);
        //cout << "-------------------------\n";
    }
    for (i=0; i<requests.size(); i++) {
        cout << worker.at(i) << " " << worker.at(i) + soldier.at(i) + 1 << endl;
    }
}
