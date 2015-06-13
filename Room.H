#ifndef _ROOM_H_
#define _ROOM_H_

#include <string>
#include <iostream>

using std::string;


class Room {
public:
	//********************************************************************
	//* Function name: Room
	//* Description: Constructor function
	//* Parameters: room_num, room_space - the number of the room and the space inside of it
	//* Return value: none
	//********************************************************************
	Room(int room_num, int room_space); /*Constructor*/


	//********************************************************************
	//* Function name: get_room_number
	//* Description: returns the number of the room
	//* Parameters: none - internal method
	//* Return value: int - the number of the room
	//********************************************************************
	int get_room_num() const; /*Gives the room number*/


	//********************************************************************
	//* Function name: get_occupied
	//* Description: returns the status of the room and wether it's occupied
	//* Parameters: none - internal method
	//* Return value: bool - true if it's occupied and false if not
	//********************************************************************
	bool get_occupied() const; /*Returns if there is somebody in the room*/


	//********************************************************************
	//* Function name: is_occupied
	//* Description: set the room as occupied
	//* Parameters: none - internal method
	//* Return value: void
	//********************************************************************
	void is_occupied(); /*There is now somebody in the room*/


	//********************************************************************
	//* Function name: not_occupied
	//* Description: set the function as not occupied
	//* Parameters: none
	//* Return value: void
	//********************************************************************
	void not_occupied(); /*There is no more somebody in this room*/


	//********************************************************************
	//* Function name: print_room
	//* Description: prints the information about the room
	//* Parameters: none
	//* Return value: void
	//********************************************************************
	void print_room() const; /*Print the room info*/

protected:
	int room_num_; /*Room number*/
	int room_space_; /*How many square meters*/
	bool occupied_; /*Are there people inside?*/
};

#endif
