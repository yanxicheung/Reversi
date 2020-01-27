#include "Grid.h"
#include "gtest/gtest.h"

struct GridTest:testing::Test
{
	virtual void TearDown()
	{
		grid.setStatus(Grid::Empty);
	}
protected:
	Grid grid;
};

TEST_F(GridTest,should_init_grid_with_empty)
{
	ASSERT_TRUE(grid.isEmpty());
}

TEST_F(GridTest,should_init_grid_without_occupied)
{
	ASSERT_TRUE(not grid.isOccupied());
}

TEST_F(GridTest,should_is_occupied_when_grid_status_set_black)
{
	grid.setStatus(Grid::Black);
	ASSERT_TRUE(grid.isOccupied());
}

TEST_F(GridTest,should_is_not_occupied_when_grid_status_set_empty)
{
	grid.setStatus(Grid::Empty);
	ASSERT_TRUE(not grid.isOccupied());
}

TEST_F(GridTest,should_is_occupied_when_grid_status_set_white)
{
	grid.setStatus(Grid::White);
	ASSERT_TRUE(grid.isOccupied());
}
