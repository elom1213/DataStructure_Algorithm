#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "DisjointSet.hpp"

using namespace std;

void print_set(DisjointSet<Node>&);

// CLRS 21.1 Disjoint Set
// CLRS 21.3 Disjoint Set Forest
int main() {
  vector<int> col{};
  vector<vector<int>> T{};
  string s1, s2;

//====================================================
// set total node num
type_node_num:
  cout << "type number of nodes => ";
  cin >> s1 ;

  int total_node_num;
  if((total_node_num = stoi(s1))<=0)
  {
    cout << "you must put intger. try again\n";
    s1.clear();
    goto type_node_num;
  } 

//====================================================
// set total edge num
type_edge_num:
  cout << "type number of edges => ";
  cin >> s2 ;
  
  int total_edge_num;
  if((total_edge_num = stoi(s2))<=0)
  {
    cout << "you must put intger. try again\n";
    s2.clear();
    goto type_edge_num;
  } 

//====================================================
/*
    0 ----- 2      4
    |            /
    |          /
    1       3

    if we want to make graph looks like that
    we have to type
    total node num => 5
    total edge num => 3
    edge processed => 0 1
                      0 2
                      3 4
    then we'll get the result looks like output.txt
*/

  DisjointSet<Node> myset(total_node_num);
  myset.make_nodes(total_node_num);

  print_set(myset);

  cout << "\nput node number between 0 to " << myset.get_size()-1 << '\n';
  for(int i=1; i<=total_edge_num; ++i)
  {
put_edge:
    cout << i << " : put edge ( a b ) => ";
    cin >> ws;
    getline(cin, s2);
    stringstream ss{s2};    
    while(ss >> s1 >> skipws)
    {
      int input = stoi(s1);

      if(input > myset.get_size()) 
      {
        cout << "put node number between 0 to " << myset.get_size() << '\n';
        goto put_edge;
      }
      
     col.emplace_back(input);
    }
      
    cout << "    add edge ( "  ;
    for(auto r : col) cout << r << ' ';
    cout << ")\n";

    T.emplace_back(col);
    myset.merge_set(T[i-1][0], T[i-1][1]);
    col.clear();
    cout << '\n';
  }
  
  cout << '\n';
  print_set(myset);
}

void print_set(DisjointSet<Node>& s)
{ 
  int siz = s.get_size();
  for(int i=0; i<siz; ++i)
  {
    ostringstream oss;
    for(int j=0; j<siz; ++j) 
      if(s.find_representative(j).nod_idx == i) oss << j << ' ';

      if(!oss.str().empty())
      {
        cout << "\n{ " << oss.str() << "} #edge => " 
             << s.find_representative(i).total_edg_num ;
      }
      oss.clear();
  }
  cout << '\n';
}


