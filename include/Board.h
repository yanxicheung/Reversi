#ifndef INCLUDE_BOARD_H_
#define INCLUDE_BOARD_H_
/*
	a b c d e f g h
	_ _ _ _ _ _ _ _  1
	_ _ _ _ _ _ _ _  2
	_ _ _ _ _ _ _ _  3
	_ _ _ W B _ _ _  4
	_ _ _ B W _ _ _  5
	_ _ _ _ _ _ _ _  6
	_ _ _ _ _ _ _ _  7
	_ _ _ _ _ _ _ _  8
*/
#include "Grid.h"
enum Position
{
	a1, b1, c1, d1, e1, f1, g1, h1,
	a2,	b2,	c2,	d2,	e2,	f2,	g2,	h2,
	a3,	b3,	c3,	d3,	e3,	f3,	g3,	h3,
	a4,	b4,	c4,	d4,	e4,	f4,	g4,	h4,
	a5,	b5,	c5,	d5,	e5,	f5,	g5,	h5,
	a6,	b6,	c6,	d6,	e6,	f6,	g6,	h6,
	a7,	b7,	c7,	d7,	e7,	f7,	g7,	h7,
	a8,	b8,	c8,	d8,	e8,	f8,	g8,	h8,
	MAX_POSITION_SIZE
};

struct Board
{
	Board();
	Grid at(Position p) const;
	void init();
	void place(Position p,Grid::Status status);
	void toogle(Position p);
	void print()const;
private:
	bool onBoard(Position p) const;
private:
	Grid grids[MAX_POSITION_SIZE];
};



#endif /* INCLUDE_BOARD_H_ */
