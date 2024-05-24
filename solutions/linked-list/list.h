#include  <bits/stdc++.h>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
};

class List {
	Node* head_;
	Node* tail_;
	int count_;

	public:
		List ();

		int size();
		void add_element(int);
		void add_element(int,int);
	    int get_element(int);
		void move_element(int,int);
		int search_element(int);
		void remove_element(int);
		void remove_element_by_position(int);
		void print_list();
};
