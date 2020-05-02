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
    else    return;
}
void  Display(vector<int> &heap)
{
    for(int i=0;i<heap.size();i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    return;
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
        upheapify(heap,i);
    }
    Display(heap);
    return 0;
}
