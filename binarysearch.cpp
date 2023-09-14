#include <iostream>
#include <vector>
using namespace std;
int binarySearchLastOcc (int a[], int n, int target)
{
    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;
    int ans = -1;
    while(start <= end)
    {
        if(a[mid] == target)
        {
            ans = mid;
            start = mid + 1;
        }
        else if(a[mid] > target)
        {
            end = mid - 1;
        }
        else if(a[mid] < target)
        {
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}
int binarySearchFirstOcc (int a[], int n, int target)
{
    int start = 0 ;
    int end = n-1 ;
    int mid = (start + end) / 2;
    int index = -1;
    while(start <= end)
    {
        if(a[mid] == target)
        {
            index = mid;
            end = mid - 1;
        }
        else if(a[mid] < target)
        {
            start = mid + 1;
        }
        else if(target < a[mid])
        {
            end = mid - 1;
        }
        mid = (start + end)/2;
        
    }
    return index;
}
int binarySearchTotalElements (int a[], int n, int target)
{
    int firstOcc = binarySearchFirstOcc(a, n, target);
    int lastOcc = binarySearchLastOcc(a, n, target);
    if(lastOcc != -1)
        return (lastOcc - firstOcc + 1);
    else
        return -1;
}
int binarySearch(int a[], int n, int target)
{
    int start = 0 ;
    int end = n-1 ;
    int mid = start + ( end - start )/2;
    while(start <= end)
    {
        if(a[mid] == target)
        {
            return mid;
        }
        else if(a[mid] < target)
        {
            start = mid + 1;
        }
        else if(target < a[mid])
        {
            end = mid - 1;
        }
        mid = start + ( end - start )/2;
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter size of array : " ;
    cin >> n;
    int arr[n];
    cout << "Enter array : " << endl;
    for ( int i = 0 ; i < n ; i++ )
        cin >> arr[i];
    cout << "Enter the target : ";
    int target;
    cin >> target;
    cout << endl;
    //normal searching
    int ansIndex = binarySearch(arr, n, target);
    if(ansIndex == -1) 
        cout << "Element not found!" << endl;
    else
        cout << "Index at which element is present : " << ansIndex << endl;
    //first index
    int ansIndexFirst = binarySearchFirstOcc(arr, n, target);
    if(ansIndexFirst != -1) cout << "First Index at which element is present : " << ansIndexFirst << endl;
    else
        cout << "Element not found!" << endl;
    //last index
    int ansIndexLast = binarySearchLastOcc(arr, n, target);
    if(ansIndexFirst != -1) cout << "Last Index at which element is present : " << ansIndexLast << endl;
    else
        cout << "Element not found!" << endl;
    //total number of elements
    int ansTotalElements = binarySearchTotalElements(arr, n, target);
    if(ansTotalElements != -1)
        cout << "Total elements of " << target << " are : " << ansTotalElements << endl;
    else
        cout << "0 element is present!" << endl;
    return 0;
}