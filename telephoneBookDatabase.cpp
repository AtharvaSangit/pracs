/*Assignment no = 1(Group A)
Title= Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client‘s telephone number. Make use of two collision handling techniques and compare them using number of comparisons required to find a set of telephone numbers.*/

/*----------ALGORITHM-------------------
1. START
2. counter =0
3. Selectoptionfrom display menu
    a) insert
    b) search
    c) display
4. Output
5. STOP
*/

#include <bits/stdc++.h>
using namespace std;
void Hash(int arr[], int HashTable[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        x = arr[i] % 10;
        // int *p = HashTable;
        if (HashTable[x] == 0)
        {
            HashTable[x] = arr[i];
        }
        else
        {
            while (HashTable[x] != 0)
            {
                x++;
            }
            HashTable[x] = arr[i];
        }
    }
}

int Search(int HashTable[], int no)
{
    for (int i = 0; i < 10; i++)
    {
        if (HashTable[i] == no)
        {
            return HashTable[i];
        }
    }
    return -1;
}

void Delete(int HashTable[], int no)
{
    int temp = Search(HashTable, no);
    if (temp != -1)
    {
        for (int i = temp; i < 10; i++)
        {
            HashTable[i] = HashTable[i++];
        }
    }
}

int main()
{
    int n;
    cout << "enter size\n";
    cin >> n;
    int arr[n];
    cout << "enter no.s\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int HashTable[10];
    for (int i = 0; i < 10; i++)
    {
        HashTable[i] = 0;
    }

    Hash(arr, HashTable, n);
    for (int i = 0; i < 10; i++)
    {
        cout << HashTable[i] << " ";
    }
    cout << endl;

    if (Search(HashTable, 4) == -1)
    {
        cout << "Not found";
    }
    else
    {
        cout << Search(HashTable, 4) << endl;
    }

    Delete(HashTable, 4);

    return 0;
}
