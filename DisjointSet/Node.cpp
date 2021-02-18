#include "Node.hpp"

bool Node::is_bigger_than(Node& x) const
{
  return this->total_edg_num > x.total_edg_num ? true : false;
}

bool Node::is_same_with(Node& x) const
{
  return this == &x ? true : false;
}

bool Node::is_representative() const
{
  return this == parent_ptr ? true : false;
}

void Node::set_edg_number_to(int&& x)
{
  this->total_edg_num = x;
}

void Node::set_parent_ptr_to(Node& x)
{
  this->parent_ptr = x.parent_ptr;
}

void Node::set_child_ptr_to(Node& x)
{
  this->child_ptr = x.child_ptr;
}
