/*********************************************************************************
** Program name: Project 5 (Main File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Main file for Project 5.
**
*********************************************************************************/

#include "game.hpp"
#include "comroom.hpp"
#include "engine.hpp"
#include "engineering.hpp"
#include "entrance.hpp"
#include "hallway.hpp"
#include "intersection.hpp"
#include "maintenance.hpp"
#include <random>
#include <time.h>

int main()
{
	srand(time(NULL));
	Entrance* ent = new Entrance();
	Hallway* h = new Hallway;
	Intersection* i = new Intersection();
	Maintenance* m = new Maintenance();
	Engine* eng = new Engine();
	ComRoom* c = new ComRoom();
	Engineering* engr = new Engineering();

	c->setWest(i);
	c->setItem("engine lockout key");

	eng->setEast(i);

	engr->setSouth(i);
	engr->setItem("tool kit");

	ent->setNorth(h);
	ent->setItem("jacket");

	h->setNorth(i);
	h->setSouth(ent);
	h->setWest(m);

	i->setSouth(h);
	i->setWest(eng);
	i->setEast(c);
	i->setNorth(engr);

	m->setEast(h);
	m->setItem("patch kit");

	
	

	Game* g = new Game(ent);

	g->startup();

	delete g;
	delete ent;
	delete h;
	delete i;

	return 0;
}