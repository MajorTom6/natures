#include "creature.h"

Creature::Creature(Window m, std::string s)
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
	x=y=500;

	//For the test resource
	xT=yT=300;
}

void Creature::Behavior()
{
  //Detection

  //Priorities

	//Action
	this->Action();
}

void Creature::Action()
{
	//if(isclose)
	//	eat//reproduce//etc;

	if(x==xT)
	{
		if(y<yT)
			y++;
		else
			y--;
	}
	else if(y==yT)
	{
		if(x<xT)
			x++;
		else
			x--;
	}
	else
	{
		srand(time(NULL));
		int z = rand()%1;
	}
}
