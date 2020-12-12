#include "list.h"

List::List()
{
	count_ = 0;
	head_ = NULL;
	tail_ = NULL;
}

int List::size()
{
	return count_;
}

void List::add_element(int value)
{
	Node* node = new Node();
	node->data = value;
	node->next = NULL;
	if (count_ == 0)
	{
		head_ = node;
		tail_ = head_;
	}
	else
	{
		tail_->next = node;
		tail_ = node;
	}
	count_+=1;
}

void List::add_element(int value, int position)
{	
	Node* node = new Node();
	node->data = value;

	if (position >= count_-1)
	{
		add_element(value);
		return;
	}
	else if (position <= 0)
	{
		node->next = head_;
		head_ = node;
		count_+=1;
		return;
	}
	
	Node* prev = head_;
	for (int i=1; i < position; i++)
		prev = prev->next;
	
	node->next = prev->next;
	prev->next = node;
	count_+=1;
}

int List::get_element(int position)
{
	if (position >= count_-1)
		return tail_->data;
	else if (position <= 0)
		return head_->data;

	Node* curr = head_;
	for (int i=0; i < position; i++)
		curr = curr->next;

	return curr->data;
}

void List::move_element(int curr_pos, int next_pos)
{	
	if (curr_pos == next_pos)
		return;

	int value = get_element(curr_pos);
	remove_element_by_position(curr_pos);
	add_element(value,next_pos);
}

int List::search_element(int value)
{
	if (count_==0)
		return -1;

	Node* curr = head_;
	for (int i=0; i<count_; i++)
	{
		if (curr->data == value)
			return i;
		curr = curr->next;
	}
	return -1;
}

void List::remove_element(int value)
{
	if (count_==0)
		return;
	
	if (head_->data == value)
	{
		Node* temp = head_;
		head_ = head_->next;
		count_-=1;
		delete temp;
		remove_element(value);
		return;
	}

	Node* prev = head_;
	for (int i=1; i<count_; i++)
	{	
		Node* curr;
		curr = prev->next;
		if (curr->data == value)
		{	
			prev->next = curr->next;
			count_-=1;
			i-=1;
			delete curr;
			continue;
		}
		prev = prev->next;
	}
	tail_=prev;
}

void List::remove_element_by_position(int position)
{	
	if (position < 0 || position >= count_)
		return;

	Node* prev;
	Node* curr = head_;	
	if (position == 0)
		head_ = curr->next;
	else
	{
		for (int i=0; i < position; i++)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr->next == NULL) //Removing last position
		{
			prev->next = NULL;
			tail_= prev;
		}
		else
			prev->next = curr->next;
		
	}
	delete curr;
	count_-=1;
}

void List::print_list()
{	
	if (count_ == 0)
		return;

	Node* curr_node = head_;
	for (int i=0; i<count_; i++)
	{
		cout << curr_node->data << "\n";
		curr_node = curr_node->next;
	}
}
