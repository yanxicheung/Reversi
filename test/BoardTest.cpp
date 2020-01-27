#include "Board.h"
#include "gtest/gtest.h"

struct BoardTest:testing::Test
{
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
	virtual void TearDown()
	{
		board.init();
	}

protected:
	Board board;
};

TEST_F(BoardTest,should_init_board_with_W_B_B_W_in_d4_d5_e4_e5_position)
{
	ASSERT_TRUE(board.at(d4).isWhite());
	ASSERT_TRUE(board.at(e5).isWhite());
	ASSERT_TRUE(board.at(e4).isBlack());
	ASSERT_TRUE(board.at(d5).isBlack());
}

TEST_F(BoardTest,should_get_right_grid_status_after_set_status_to_position)
{
	board.place(f5,Grid::Black);
	ASSERT_TRUE(board.at(f5).isBlack());

	board.place(f4,Grid::White);
	ASSERT_TRUE(board.at(f4).isWhite());
}


TEST_F(BoardTest,should_grid_status_is_empty_when_position_index_over_range)
{
	board.place((Position)100,Grid::Black);
	ASSERT_TRUE(board.at((Position)100).isEmpty());
}

TEST_F(BoardTest,should_print_board_when_call_print_method)
{
	board.print();
}

TEST_F(BoardTest,should_not_toogle_when_toogle_empty_grid)
{
	board.toogle(f1);
	ASSERT_TRUE(board.at(f1).isEmpty());
}

TEST_F(BoardTest,should_not_toogle_when_toogle_index_out_of_range)
{
	board.toogle((Position)100);
	ASSERT_TRUE(board.at((Position)100).isEmpty());
}

TEST_F(BoardTest,should_toogle_to_right_status_when_grid_is_not_empty)
{
	board.place(f5,Grid::Status::Black);
	ASSERT_TRUE(board.at(f5).isBlack());

	board.toogle(f5);
	ASSERT_TRUE(board.at(f5).isWhite());

	board.toogle(f5);
	ASSERT_TRUE(board.at(f5).isBlack());


	board.toogle(d4);
	ASSERT_TRUE(board.at(d4).isBlack());

	board.toogle(d5);
	ASSERT_TRUE(board.at(d5).isWhite());
}




