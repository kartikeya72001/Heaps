#include<iostream>
#include<vector>
using namespace std;
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
    else
    {
        return;
    }
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
    return 0;
}
