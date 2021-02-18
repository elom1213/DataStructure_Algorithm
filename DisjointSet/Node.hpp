#pragma once

struct Node
{
  Node* parent_ptr;
  Node* child_ptr;
  int nod_idx; // identifier
  int total_edg_num;

  Node() : nod_idx{-1}, 
           parent_ptr{this}, 
           child_ptr{this} {}

  bool is_bigger_than(Node&) const;
  bool is_same_with(Node&) const;
  bool is_representative() const;
  void set_edg_number_to(int&&);
  void set_parent_ptr_to(Node&);
  void set_child_ptr_to(Node&);
};
