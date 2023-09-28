#include "fast.h"
#include "right.h"
#include "gen_test.h"
#include "checker.h"

using namespace std;

void solve(int n);

//int n = 0, tf = 0, tr = 0; // кол-во тестов,  кол-во времени в секндак для fast и right

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 0, tf = 0, tr = 0; // кол-во тестов,  кол-во времени в секндак для fast и right
    cin >> n;
    generate_tests(n);
    
    freopen("tests.txt", "r", stdin);
    freopen("differences.txt", "w", stdout);
    //freopen("right_out.txt", "w", stdout);

    srand(1);
    solve(n);
    return 0;
}

void solve(int n) {

    for (int i = 0; i < n; i++) {
        string inpS;
        cin >> inpS;
        int arr[26];
        for (int j = 0; j < 26; j++) {
            cin >> arr[i];
        }
        pair <string, int> fans = fast::fast(inpS, arr);
        long long weight1 = right::right(fans.first, arr);
        long long weight2 = right::right(inpS, arr);
        cout << "Тест " << i + 1 << " Fast: " << weight1 << " Right: " << weight2;
        //(weight1 != weight2) ? cout << " False; Time " << fans.second : cout << 
        if (weight1 != weight2) {
            cout << " False; Time " << fans.second << "\n";
        } else {
            cout << " True; Time " << fans.second << "\n";
        }
    }
    return;
}