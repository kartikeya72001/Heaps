#include<iostream>
#include<vector>
using namespace std;
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
void DeletePeak(vector<int> &heap)
{
    swap(heap[0], heap[heap.size()-1]);
    heap.pop_back();
    Downheapify(heap, 0);
}
void upheapify(vector<int> &heap, int idx)
{
    if(idx == 0)
        return;
    int parentId = (idx-1)/2;
    if(heap[parentId] < heap[idx])
    {
        int temp = heap[parentId];
        heap[parentId] = heap[idx];
        heap[idx] = temp;
        upheapify(heap,parentId);
    }
    else    return;
}
void Insert(vector<int> &heap, int key)
{
    heap.push_back(key);
    upheapify(heap, heap.size()-1);
    return;
}
void  Display(vector<int> &heap)
{
    for(int i=0;i<heap.size();i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> heap;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        Insert(heap,x);
    }
    Display(heap);
    DeletePeak(heap);
    Display(heap);
    return 0;
}
