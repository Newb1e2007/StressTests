#include "gen_test.h"

using namespace std;

random_device rd;
mt19937 gen(rd());

string generateRandomString(int n) {
    // Создаем генератор случайных чисел
    uniform_int_distribution<int> dis('a', 'z'); // Диапазон букв от 'a' до 'z'

    // Генерируем случайные буквы и добавляем их к строке
    string result;
    for (int i = 0; i < n; ++i) {
        char randomChar = static_cast<char>(dis(gen));
        result += randomChar + ' ';
    }

    return result;
}

int *generateRandomArray(int (&result)[], int length) {
    uniform_int_distribution<int> dis(0, numeric_limits<int>::max());

    // Генерируем случайные числа и добавляем их в массив
    //int result[length];
    for (int i = 0; i < length; ++i) {
        result[i] = dis(gen);
    }

    return result;
}

void generate_tests(int n) {
    uniform_int_distribution<int> dis(0, 100000);
    freopen("tests.txt", "w", stdout);
    int size;
    string s;
    int arr[26];
    
    for (int i = 0; i < n; i++) {
        size = dis(gen);
        s = generateRandomString(size);
        generateRandomArray(arr, 26);

        cout << s << "\n";
        for (int j = 0; j < 26; j++) {
            cout << arr[i];
        }
        cout << "\n";
    }
    return;
}