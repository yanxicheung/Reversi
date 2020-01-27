#include"Board.h"
#include <iostream>
using namespace std;
Board::Board()
{
	init();
}

void Board::init()
{
	for(int index = 0;index<MAX_POSITION_SIZE;++index)
	{
		grids[index].setStatus(Grid::Empty);
	}
	grids[d4].setStatus(Grid::White);
	grids[e5].setStatus(Grid::White);
	grids[e4].setStatus(Grid::Black);
	grids[d5].setStatus(Grid::Black);
}

Grid Board::at(Position p) const
{
	static Grid nullGrid;
	if(not onBoard(p))
	{
		return nullGrid;
	}
	return grids[p];
}

void Board::place(Position p, Grid::Status status)
{
	if(onBoard(p))
	{
		grids[p].setStatus(status);
	}
}

namespace
{
	char to_c(const Grid grid)
	{
		if(grid.isBlack())
			return 'B';
		else if(grid.isWhite())
			return 'W';
		else
			return '_';
	}
};
void Board::print() const
{
	cout<<"a b c d e f g h"<<endl;
	enum {MAX_SIZE_PER_LINE = 8};
	for(int index = 0;index < MAX_POSITION_SIZE;)
	{
		cout<<to_c(grids[index])<<' ';
		if(++index % MAX_SIZE_PER_LINE == 0)
			cout<<index/MAX_SIZE_PER_LINE<<endl;
	}
}

void Board::toogle(Position p)
{
	if(not onBoard(p))
		return;
	if(grids[p].isEmpty())
		return;
	if(grids[p].isBlack())
	{
		grids[p].setStatus(Grid::White);
	}
	else if(grids[p].isWhite())
	{
		grids[p].setStatus(Grid::Black);
	}
}

bool Board::onBoard(Position p) const
{
	return p>=a1 and p<=h8;
}
