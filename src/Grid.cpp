/*
 * Grid.cpp
 *
 *  Created on: 2020年1月27日
 *      Author: daniel
 */
#include "Grid.h"

bool Grid::isBlack() const
{
	return status_ == Status::Black;
}

bool Grid::isWhite() const
{
	return status_ == Status::White;
}

bool Grid::isEmpty() const
{
	return status_ == Status::Empty;
}

bool Grid::isOccupied() const
{
	return not isEmpty();
}

void Grid::setStatus(Status status)
{
	status_ = status;
}
