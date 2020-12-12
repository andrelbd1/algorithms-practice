#include  <bits/stdc++.h>
using namespace std;

#include "list.h"

int main(){
	List newlist;

	cout << "Loading list...\n";
	newlist.add_element(0);
	newlist.add_element(1);
	newlist.add_element(2);
	newlist.add_element(3);
	newlist.add_element(4);
	newlist.add_element(5);
	newlist.add_element(6);
	newlist.add_element(7);
	newlist.add_element(8);
	newlist.add_element(9);
	newlist.print_list();

	//cout << "\nPosition element 2:\n" << newlist.search_element(2) << "\n";
	
	//cout << "\nRemoving all 1 elements\n";
	//newlist.remove_element(1);
	//newlist.print_list();
	
	//cout << "\nRemoving element in position 1\n";
	//newlist.remove_element_by_position(7);
	//newlist.print_list();
	
	//cout << "\nRemoving all 4 elements\n";
	//newlist.remove_element(4);
	//newlist.print_list();

	//cout << "\nRemoving all 6 elements\n";
	//newlist.remove_element(6);
	//newlist.print_list();

	//cout << "\nAdding element 7\n";
	//newlist.add_element(7);
	//newlist.print_list();*/

	//cout << "\nAdding element 10 in position 6\n";
	//newlist.add_element(10,6);
	//newlist.print_list();
	
	//cout << "\nGet element in position 1\n" << newlist.get_element(7) << "\n";
	
	//cout << "\nMove element from 3 to 1\n";
	//newlist.move_element(3,1);
	//newlist.print_list();

	return 0;
}
