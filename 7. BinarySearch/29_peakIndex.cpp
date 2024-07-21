#include <iostream>

using namespace std;

int main()
{

    int arr[5] = {3, 5, 3, 2, 0};

    int start = 0, end = 4, mid;
    
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])
        {
            end = mid - 1;
        }
        else if (arr[mid] < arr[mid + 1] && arr[mid] > arr[mid - 1])
        {
            start = mid + 1;
        }
        else
        {
            cout << mid;
        }
    }

    return 0;
}