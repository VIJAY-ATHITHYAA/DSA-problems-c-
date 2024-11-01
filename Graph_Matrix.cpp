#include <vector>
#include <iostream>
using namespace std;

class Matrix{
  private:    
    int V;
    vector<vector<int>> vec;
  public:
    Matrix(int v){
        V = v;
        vec.resize(V,vector<int>(V,0));
    }
    void addEdge(int x,int y){
        vec[x][y] = 1;
        vec[y][x] = 1;
    }
    void DeleteEdge(int x,int y){
        vec[x][y] = 0;
        vec[y][x] = 0;
    }
    void Display(){
        cout<<"Adjacency List Below:\n   ";
        for(int i=0;i<V;i++)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
        for(int i=0;i<V;i++){
            cout<<i<<"  ";
            for(int j=0;j<V;j++){
                cout<<vec[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
  Matrix m(5);
  m.addEdge(1,0);
  m.addEdge(1,2);
  m.addEdge(2,3);
  m.addEdge(0,2);
  m.addEdge(4,2);
 
  m.Display(); 
  return 0;
  
}