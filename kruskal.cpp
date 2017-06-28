#include <iostream>
#include <vector> //vectors...
#include <algorithm> //sort()
#include <fstream> //read from file
using namespace std;
int parents[100];


ifstream read ("graph.txt"); //read from text file

//Disjoint Sets
int find(int x)
{
	if (parents[x]==x)
		{
			return x;
		}
		return find(parents[x]);
}

void unite(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	parents[fx] = fy;
}

int main()
{
	//parent initialization
	for(int i=0;i<100;i++)
		{
			parents[i]=i;
		}

int no,ne,a,b,w; //number of nodes,number of edges,nodefrom,nodeto,weight.

vector<pair<int,pair<int,int> > > edges;
read>>no>>ne; //read number of nodes and edges first
for (int i=0;i<ne;i++) //repeat for each edge
{
	read>>a>>b>>w; //get fromnode, tonode,weight. 
	edges.push_back(make_pair(w,make_pair(a,b))); //push in vector
}
int mst_edges=0;
int mst_nextindex=0;
sort(edges.begin(),edges.end());

while((mst_edges <=no-1) || (mst_nextindex<no)) //processing until the number of nodes-1
{
a=edges[mst_nextindex].second.first;
b=edges[mst_nextindex].second.second;
w=edges[mst_nextindex].first;
//while not on same tree
//otherwise will create cycles
if (find(a)!=find(b))
{
	unite(a,b);
	cout<<a<<" "<<b<<" "<<w<<endl;
	mst_edges++;
}
mst_nextindex++;
}
}
