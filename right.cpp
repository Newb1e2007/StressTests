#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i < b; i++)

using namespace std;

void mergeSort(pair<char, int> arr[], pair<char, int> buffer[], int left, int right, int middle)
{
    int i = left;
    int j = middle + 1;
    int ind = left;
    while (i < middle + 1 && j < right + 1)
    {
        if (arr[i].second < arr[j].second)
        {
            buffer[ind] = arr[j];
            j++;
        }
        else
        {
            buffer[ind] = arr[i];
            i++;
        }
        ind++;
    }
    while (i < middle + 1)
    {
        buffer[ind] = arr[i];
        i++;
        ind++;
    }
    for (int k = left; k < right + 1; k++)
    {
        arr[k] = buffer[k];
    }

    return;
}

void sort(pair<char, int> arr[], pair<char, int> buffer[], int left, int right)
{
    int middle = (right - left) / 2 + left;
    if (left < right)
    {
        sort(arr, buffer, left, middle);
        sort(arr, buffer, middle + 1, right);
        mergeSort(arr, buffer, left, right, middle);
    }
    return;
}

int right(string &s, int arr[]) {
    //long long str_weight = 0;
    
    map<char, int> letter_count;
    pair<char, int> letter_weight[26];
    pair<char, int> buffer[26];
    for (int i = 0; i < 26; i++) {
        letter_weight[i] = make_pair(static_cast<char>(i + 97), arr[i]);
        buffer[i] = make_pair(static_cast<char>(i + 97), arr[i]);
    }
    for (int i = 0; i < s.length(); i++) {
        if (letter_count.count(s[i]) == 0){
            letter_count[s[i]] = 1;
        } else {
            letter_count[s[i]]++;
        }
    }
    sort(letter_weight, buffer, 0, 25);

    /*for (auto pair : letter_weight) {
        str_weight += pair.second*letter_count[pair.first]/2;
    }*/
    long long maxWeight = 0;
    int maxDiff = s.length() - 1;
    for (auto p = 0; p < 26 ; p++) {
        while (letter_count[p.first] > 1) {
            maxWeight += maxDiff * p.second;
            maxDiff -= 2;
        }
    }
    return maxWeight;
}

int main() {
    string s;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
    cout << right(s, arr);
    return 0;
}