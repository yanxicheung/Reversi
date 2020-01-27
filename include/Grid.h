/*
 * Grid.h
 *
 *  Created on: 2020年1月27日
 *      Author: daniel
 */

#ifndef INCLUDE_GRID_H_
#define INCLUDE_GRID_H_

struct Grid
{
	enum Status{Black,White,Empty};

	Grid():status_(Empty){}
	void setStatus(Status status);
	bool isBlack()const;
	bool isWhite()const;
	bool isEmpty()const;
	bool isOccupied()const;
private:
	Status status_;
};

#endif /* INCLUDE_GRID_H_ */
