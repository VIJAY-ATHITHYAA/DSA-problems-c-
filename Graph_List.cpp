#include <iostream>
#include <list>
#include <queue>

using namespace std;
//by using matrics;
class Graph{
    int V;
    list<int> *l;
    int *visted;
      int *Visted;
    public:
        Graph(int v){
            visted = new int[v];
            Visted = new int[v];
            V = v;
            l = new list<int>[V];
        }
        void addEdge(int x,int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }
        void printList(){
            for(int i=0;i<V;i++){
                cout<<"Vertex "<<i<<"->";
                    for(int x:l[i]){
                   cout<<x<<",";
                }
                cout<<endl;
            }
        }
        void DeleteEdge(int x,int y){
            l[x].remove(y);
            l[y].remove(x);
        }
        //Depth first Search...
        void Dfs(int v){
            visted[v] = 1;
            cout<<v<<" ";
            for(int x:l[v]){
                if(visted[x]!=1)
                   Dfs(x);
            }
        }
        //Breath First Search...
        void Bfs(int v){
            queue<int> q;
            q.push(v);
            while(!q.empty()){
                int val = q.front();
                q.pop();
                cout<<val<<" ";
                Visted[val] = 1;
                for(int x:l[val]){
                    if(Visted[x]!=1)
                       q.push(x);
                }
            }
        }
        //Connected Components in graph...
        int Connected_Com(){
            int count =0;
            for(int i=0;i<V;i++){
                visted[i] = 0;
            }
            for(int i=0;i<V;i++){
                if(visted[i]==0)
                 {
                     Dfs(i);
                     count++;
                 }
              }
              return count;
        }
};

int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(3,4);
    int c = g.Connected_Com();
    cout<<"Connected Components = "<<c;
    return 0;
}
