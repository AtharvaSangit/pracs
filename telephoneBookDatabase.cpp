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

#include <iostream>
using namespace std;
class HashTable
{
public:
    int index;
    long int mobile;
};
class Hashing
{
    HashTable h[10];

public:
    Hashing()
    {
        for (int i = 0; i < 10; i++)
        {
            h[i].index = i;
            h[i].mobile = -1;
        }
    }
    void display();
    void insert();
    void search();
    int LinearProbing(int);
};

int Hashing::LinearProbing(int collision_position)
{
    for (int i = collision_position; i < 10; i++)
    {
        if (h[i].mobile == -1)
            return i;

        if (i == 9)
            i = -1;
    }
}

void Hashing::display()
{
    for (int i = 0; i < 10; i++)
    {
        cout << h[i].index;
        cout << "  " << h[i].mobile;
        cout << endl;
    }
}
void Hashing::insert()
{
    long int key;
    int position;
    cout << "\nEnter mobile number to insert in to hash table : ";
    cin >> key;
    position = key % 10;

    cout << "\nPosition = " << position;

    if (h[position].mobile == -1)
    {
        h[position].mobile = key;
    }
    else
    {
        int temp_position;
        temp_position = LinearProbing(position);
        h[temp_position].mobile = key;
    }
}

void Hashing::search()
{
    long int key;
    int position;
    cout << "\nEnter mobile number to search in the hash table : ";
    cin >> key;
    position = key % 10;

    if (h[position].mobile == key)
    {
        cout << "\nGiven mobile number is found in the hash table ";
    }
    else
    {
        cout << "\nGiven mobile number is NOT found in the hash table ";
    }
}
int main()
{
    Hashing H;
    int ch;
    do
    {
        cout << "\n Menu";
        cout << "\n 1. insert";
        cout << "\n 2.display";
        cout << "\n 3.search";
        cout << "\n 4. exit";
        cout << "\n Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1: // insert
            H.insert();
            break;
        case 2: // display
            H.display();
            break;

        case 3: // display
            H.search();
            break;

        default:
            cout << "\nWrong choice :";
            break;
        }

    } while (ch != 5);
    H.display();
}
/*Output=
 Menu
 1. insert
 2.display
 3.search
 4. exit
 Enter your choice : 1

Enter mobile number to insert in to hash table : 678
Position = 8
  Enter your choice : 1

Enter mobile number to insert in to hash table : 546
Position = 6
 Enter your choice : 2
0  -1
1  -1
2  -1
3  -1
4  -1
5  -1
6  546
7  -1
8  678
9  -1
Enter your choice : 3
Enter mobile number to search in the hash table : 678
Given mobile number is found in the hash table
Enter your choice : 978
Wrong choice :*/
