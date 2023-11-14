#include <iostream>
#include <vector>

using namespace std;
struct Student
{
    int id;

    Student(int _id = 0) : id(_id) {}

    void change_id(int new_id)
    {
        id = new_id;
    }
};
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void foo(vector<int> &arr, int n)
{
    arr[0] = 45;
    arr[n - 1] = 67;
}
void foo1(int *arr, int n) // int *arr = int arr[]
{
    arr[0] = 48;
    arr[n - 1] = 65;
}
int bigger(int &a, int &b)
{
    return a > b ? a : b;
}
int main()
{
    Student pen(7);
    Student *ptr1 = &pen;
    Student guin(6);
    swap(&pen.id, &guin.id);
    // cout << ptr1->id << " " << guin.id;
    int a[5] = {1, 3, 4, 5, 6};
    vector<int> arr123 = {1, 3, 4, 5, 6};
    foo(arr123, 4);

    std::cout << arr123[0] << " " << arr123[1] << " " << arr123[2] << " " << arr123[3] << std::endl; // 45 1 2 67
    foo1(a, 4);
    cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << std::endl;
    int a1 = 12, b = 34;
    std::cout << bigger(a1, b) << " " << b << std::endl;
}