#include<iostream>
#include<vector>
#include<queue>

#define customPair pair <int, pair <int,int> >
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int> > arr)
{
	vector<int> result;
	priority_queue< customPair, vector<customPair>, greater<customPair>> pq;
	for(int i=0; i<arr.size(); i++)
	{
		pq.push({{arr[i][0]},{i,0}});
	}
	while(!pq.empty())
	{
		customPair curr = pq.top();
		pq.pop();
		int y = curr.second.second;
		int x = curr.second.first;
		result.push_back(curr.first);
		if(y+1 < arr[x].size())
		{
			pq.push({{arr[x][y+1]},{x,y+1}});
		}
		return result;
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> arr;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	vector<int> op = mergeKSortedArrays(arr);
	for(auto x : op)
	{
		cout<<x<<" ";
	}
	return 0;
}
