#include "Room.H"
#include "defs.H"
#include <iostream>

using std::cout;
using std::endl;
using std::boolalpha;

Room::Room(int room_num, int room_space) : room_num_(room_num), room_space_(room_space){}; /*Constructor*/

int Room::get_room_num() const /*returns room number*/
{
	return room_num_;
}

bool Room::get_occupied() const /*returns if the room is occupied*/
{
	return occupied_;
}

void Room::is_occupied() /*sets the room as occupied*/
{
	occupied_ = true;
	return;
}

void Room::not_occupied() /*sets the room as not occupied*/
{
	occupied_ = false;
	return;
}

void Room::print_room() const /*prints the room as asked*/
{
	cout << "Number : " << room_num_ << endl;
	cout << "Size : " << room_space_ << " square meters" << endl;
	cout << "Is Occupied : " << std::boolalpha << occupied_ << endl;
}