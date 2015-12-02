#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
/**
 * Definition for undirected graph.
 */ struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if(node==NULL) return NULL;
        queue<UndirectedGraphNode *> que;
        map<int,UndirectedGraphNode *> mark;
        que.push(node);
        UndirectedGraphNode *res=NULL;
        while(!que.empty())
        {
            auto temp=que.front();
            que.pop();
            UndirectedGraphNode *copy=new UndirectedGraphNode(-1);
            if(mark.find(temp->label)!=mark.end())
            {
                 copy=mark[temp->label];
            }
            else
            {
                copy->label=temp->label;
                if(res==NULL)
                   res=copy;
                mark.insert({copy->label,copy});
            }
            for(auto item:temp->neighbors)
            {
                if(mark.find(item->label)!=mark.end())
                {
                 copy->neighbors.push_back(mark[item->label]);
                }
                else
                {
                   que.push(item);
                   UndirectedGraphNode *nei=new UndirectedGraphNode(item->label);
                   copy->neighbors.push_back(nei);
                   mark.insert({nei->label,nei});
                }
            }
        }
        return res;
    }
};
void showgraph(UndirectedGraphNode* node)
{
     queue<UndirectedGraphNode *> que;
     set<int> mark;
     que.push(node);
     mark.insert(node->label);
     while(!que.empty())
     {
            auto temp=que.front();
            que.pop();
            cout<<temp->label<<",";
            for(auto item:temp->neighbors)
            {
                cout<<item->label<<",";
                if(mark.find(item->label)!=mark.end())
                   continue;
                que.push(item);
                mark.insert(item->label);
            }
            cout<<"#"<<endl;
      }
}
int main()
{
    //{0,1,5#1,2,5#2,3#3,4,4#4,5,5#5}
    UndirectedGraphNode* Node0=new UndirectedGraphNode(0);
    UndirectedGraphNode* Node1=new UndirectedGraphNode(1);
    UndirectedGraphNode* Node2=new UndirectedGraphNode(2);
    UndirectedGraphNode* Node5=new UndirectedGraphNode(5);
    UndirectedGraphNode* Node4=new UndirectedGraphNode(4);
    UndirectedGraphNode* Node3=new UndirectedGraphNode(3);

    Node0->neighbors.push_back(Node1);
    Node0->neighbors.push_back(Node5);
    Node1->neighbors.push_back(Node2);
    Node1->neighbors.push_back(Node5);
    Node2->neighbors.push_back(Node3);
    Node3->neighbors.push_back(Node4);
    Node3->neighbors.push_back(Node4);
    Node4->neighbors.push_back(Node5);
    Node4->neighbors.push_back(Node5);
    Solution solve;
    auto newnode=solve.cloneGraph(Node0);
    newnode->label=2;
    showgraph(Node0);
    return 0;
}