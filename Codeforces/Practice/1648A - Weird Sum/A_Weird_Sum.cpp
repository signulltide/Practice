#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll rowCount, colCount, sum = 0, input;
    cin >> rowCount >> colCount;
    unordered_map<ll, vector<ll>> rows, cols;

    for (ll i=0; i<rowCount; i++) {
        for (ll j=0; j<colCount; j++) {
            cin >> input;
            rows[input].push_back(i);
            cols[input].push_back(j);
        }
    }

    for (auto &[color, row] : rows) {
        for (ll i=0; i<row.size(); i++) {
            sum += row[i] * ((2 * i) - row.size() + 1);
        }
    }

    for (auto &[color, col] : cols) {
        sort(col.begin(), col.end());
        for (ll i=0; i<col.size(); i++) {
            sum += col[i] * ((2 * i) - col.size() + 1);
        }
    }

    cout << sum;
}

// int main() {
//     ios_base::sync_with_stdio(0); cin.tie(0);

//     ll rowCount, colCount, sum = 0, input;
//     cin >> rowCount >> colCount;
//     vector<vector<ll>> grid(rowCount, vector<ll>(colCount));
//     unordered_map<ll, ll> lastPoint, existing, lastIncrement;

//     for (ll i=0; i<rowCount; i++) {
//         for (ll j=0; j<colCount; j++) {
//             cin >> grid[i][j];
//             ll current = grid[i][j];
//             if (existing[current] == 0) {
//                 lastPoint[current] = i*colCount + j;
//                 existing[current] = 1;
//                 lastIncrement[current] = 0;
//                 continue;
//             }
//             ll li = lastPoint[current]/colCount, lj = lastPoint[current]%colCount;
//             ll newDist = abs(i - li) + abs(j - lj);
//             cout << "[" << current << "] " << li << " " << lj << " = " << i << " " << j << " : " << newDist << endl;
//             sum += newDist * existing[current] + lastIncrement[current];
//             cout << "+ " << newDist * existing[current] + lastIncrement[current] << '\n';
//             lastIncrement[current] += newDist * existing[current];
//             lastPoint[current] = i*colCount + j;
//             existing[current]++;
//         }
//     }

//     cout << sum;
// }