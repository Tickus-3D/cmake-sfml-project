#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class World
{
	
private:
	struct WorldTime
	{
		int years = 0;
		int months = 0;
		int weeks = 0;
		int days = 0;
		int hours = 2; 
		int minutes = 0; 
		int seconds = 0;
	} worldTime;

public:
	void UpdateWorldTime();
	VertexArray DrawWorldGrid(RenderWindow& window, int rows, int cols);

	 string GetFormatedWorldTime();
};