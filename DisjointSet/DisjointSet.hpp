#pragma once
#include <vector>
#include "Node.hpp"

// CLRS 21.1 Disjoint Set
// CLRS 21.3 Disjoint Set Forest
template<typename E>
class DisjointSet
{
public:
  DisjointSet(int n) : Nodes(n), siz{n} {}
  int  get_size() const { return siz;};

  void make_nodes(int);
  void make_node(int);

  void merge_set(int, int); 
  void link_edg_between(E& a, E& b);
  void link_child_to_parent(E& c, E& p);
  E&   nod_with_idx(int);
  E&   find_representative(int);
private:
  std::vector<E> Nodes;
  const int siz;
};

template<typename E> void DisjointSet<E>::make_nodes(int n)
{
  // make n nodes
  for(int i=0; i< n; make_node(i++));
}

template<typename E> void DisjointSet<E>:: make_node(int i)
{ 
  // set parent, child pointer to itself
  // we'll identify each node using nod_idx
  E& node_i = nod_with_idx(i);
  node_i.set_parent_ptr_to(node_i); 
  node_i.set_child_ptr_to(node_i);  
  node_i.nod_idx = i; 
  node_i.total_edg_num = 0;
}

template<typename E> void DisjointSet<E>:: merge_set(int i, int j)
{ 
  E& x = find_representative(i);
  E& y = find_representative(j);
  if(x.is_same_with(y))   x.total_edg_num++;
  else                    link_edg_between(x, y); 
}

template<typename E> void DisjointSet<E>::link_edg_between(E& x, E& y)
{
  if(x.is_bigger_than(y))   link_child_to_parent(y, x);
  else                      link_child_to_parent(x, y);
};


template<typename E> void DisjointSet<E>::link_child_to_parent(E& c, E& p)
{
  c.set_parent_ptr_to(p);
  p.set_child_ptr_to(c);
  p.set_edg_number_to(p.total_edg_num + c.total_edg_num + 1);
}

template<typename E> E& DisjointSet<E>::find_representative(int i)
{
 int inital_idx = i;
 int updated_idx = i;
 while(!nod_with_idx(updated_idx).is_representative()) 
  updated_idx = find_representative(nod_with_idx(inital_idx).parent_ptr->nod_idx).nod_idx;
 nod_with_idx(inital_idx).set_parent_ptr_to(nod_with_idx(updated_idx));
 return nod_with_idx(updated_idx);
}

template<typename E> E& DisjointSet<E>::nod_with_idx(int i)
{
  return this->Nodes[i];
}
