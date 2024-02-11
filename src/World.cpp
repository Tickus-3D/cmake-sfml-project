#include "World.h"
#include "SFML/System.hpp"

void World::UpdateWorldTime()
{
	worldTime.seconds += 1;
	if (worldTime.seconds == 60)
	{
		worldTime.minutes++;
		worldTime.seconds = 0;
		if (worldTime.minutes == 60)
		{
			worldTime.hours++;
			worldTime.minutes = 0;
		}
		else if (worldTime.hours == 24)
		{
			worldTime.days++;
			worldTime.hours = 0;
		}
	}

}

VertexArray World::DrawWorldGrid(RenderWindow& window, int rows, int cols)
{
	int numLines = rows + cols - 2;
	VertexArray grid(Lines, 2 * numLines);
	Vector2 size = window.getView().getSize();
	float rowH = size.y / rows;
	float colW = size.x / cols;

	float startHeight = size.y / 2;
	float startWidth = size.x / 2;

	// Row Separation
	for (int i = 0; i < rows - 1; i++)
	{
		int r = i + 1;
		float rowY = startHeight + rowH * r;
		grid[static_cast<size_t>(i) * 2].position = { 0, rowY };
		grid[static_cast<size_t>(i) * 2 + 1].position = { size.x, rowY };
	}

	// Column Separation
	for (int i = rows - 1; i < numLines; i++)
	{
		int c = i - rows + 2;
		float colX = startWidth + colW * c;
		grid[static_cast<size_t>(i) * 2].position = { colX, 0 };
		grid[static_cast<size_t>(i) * 2 + 1].position = { colX, size.y };
	}

	return grid;
}

string World::GetFormatedWorldTime()
{

	string formattedTime = ("Days = " + to_string(worldTime.days)
							+ " : Hours = " + to_string(worldTime.hours) 
							+ " : Minutes = " + to_string(worldTime.minutes)
							+ " : Seconds = " + to_string(worldTime.seconds) );

	return formattedTime;
}


