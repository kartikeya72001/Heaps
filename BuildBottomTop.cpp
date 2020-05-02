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
void  Display(vector<int> &heap)
{
    for(int i=0;i<heap.size();i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}
void BuildHeap(vector<int> &heap)
{
    for(int i = heap.size()-1;i>=0;i--)
    {
        Downheapify(heap,i);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> heap;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        heap.push_back(x);
    }
    BuildHeap(heap);
    Display(heap);
    return 0;
}
