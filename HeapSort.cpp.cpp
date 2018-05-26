#include<bits/stdc++.h>
using namespace std;
int heapSize;

void Max_Heapify(int* A, int i)
{

    int largest = i ;
    int l = 2 * i + 1;
    int r = 2 * i + 2;


    if(l <= heapSize && A[l] > A[largest])
    {
        largest = l ;
    }

    if(r <= heapSize && A[r] > A[largest])
    {
        largest = r;
    }

    if(largest != i)
    {
        swap(A[i], A[largest]);
        Max_Heapify(A, largest);
    }
}

void Build_Max_Heap(int* A,int n)
{
    heapSize = n - 1;
    int i;
    for(i = (n - 1) / 2; i >= 0; i--)
        Max_Heapify(A, i);
}

void HeapSort(int* A,int n)
{
    Build_Max_Heap(A,n);
    int i;
    for(i = 0; i<n-1 ; i++)
    {
        swap (A[0], A[heapSize]);
        heapSize--;
       Max_Heapify(A, 0);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    cout<<endl;
    int arr[n];
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    HeapSort(arr,n);
    int i;
    cout<<"After sorting : ";
    for(i = 0; i < n; i++)
    {
        cout<<" "<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
