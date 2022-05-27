/*Assignment no =10(Group E)
Title=Read the marks obtained by students of second year in an online examination of particular subject. Find out maximum and minimum marks obtained in that subject. Use heap data structure. Analyze the algorithm.*/

#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &a, int n, int i)
{

    int currIdx = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[currIdx])
    {
        currIdx = l;
    }
    if (r < n && a[r] > a[currIdx])
    {
        currIdx = r;
    }
    if (currIdx != i)
    {
        swap(a[i], a[currIdx]);
        heapify(a, n, currIdx);
    }
}

void heapSort(vector<int> &a)
{
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main()
{

    int n;
    cout << "Enter no. of students:" << endl;
    cin >> n;

    vector<int> a(n);
    cout << "Enter marks:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    heapSort(a);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " " << endl;
    }
    cout << "maxMarks: " << a[0] << endl;
    cout << "maxMarks: " << a[n - 1] << endl;

    return 0;
}
