#include<iostream>
#include<vector>
using namespace std;
void  Display(vector<int> &heap)
{
    for(int i=0;i<heap.size();i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}
void Downheapifyhelper(vector<int> &heap, int idx, int heapsize)
{
    int left = 2*idx+1;
    int right = 2*idx+2;
    if(left >= heap.size() && right >= heapsize)
    {
        return;
    }
    int largest = idx;
    if(left < heapsize && heap[left] > heap[largest])
        largest = left;
    if(right < heapsize && heap[right] > heap[largest])
        largest = right;
    if(largest == idx)
        return;
    swap(heap[idx],heap[largest]);
    Downheapifyhelper(heap,largest,heapsize);
}
void Downheapify(vector<int> &heap, int idx)
{
    int left = 2*idx+1;
    int right = 2*idx+2;
    if(left >= heap.size() && right >= heap.size())
    {
        return;
    }
    int largest = idx;
    if(left < heap.size() && heap[left] > heap[largest])
        largest = left;
    if(right < heap.size() && heap[right] > heap[largest])
        largest = right;
    if(largest == idx)
        return;
    swap(heap[idx],heap[largest]);
    Downheapify(heap,largest);
}
void BuildHeap(vector<int> &heap)
{
    for(int i = heap.size()-1;i>=0;i--)
    {
        Downheapify(heap,i);
    }
}
void heapSort(vector<int> &heap)
{
    int heapsize = heap.size();
    BuildHeap(heap);
    for(int i = heap.size()-1;i>=0;i--)
    {
        swap(heap[0],heap[i]);
        heapsize--;
        Downheapifyhelper(heap,0,heapsize);
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    heapSort(arr);
    Display(arr);
    return 0;
}
