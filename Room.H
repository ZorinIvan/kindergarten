#ifndef _ROOM_H_
#define _ROOM_H_

#include <string>
#include <iostream>

using std::string;


class Room {
public:
	Room(int room_num, int room_space); /*Constructor*/
	int get_room_num() const; /*Gives the room number*/
	bool get_occupied() const; /*Returns if there is somebody in the room*/
	void is_occupied(); /*There is now somebody in the room*/
	void not_occupied(); /*There is no more somebody in this room*/
	void print_room() const; /*Print the room info*/
protected:
	int room_num_; /*Room number*/
	int room_space_; /*How many square meters*/
	bool occupied_; /*Are there people inside?*/
};

#endif
