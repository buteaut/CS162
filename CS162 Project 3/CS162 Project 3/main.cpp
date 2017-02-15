#include "barbarian.hpp"
#include "harryPotter.hpp"
#include "vampire.hpp"
#include "blueMen.hpp"
#include "medusa.hpp"

int main()
{
	srand(time(NULL));

	Medusa* steve = new Medusa();
	BlueMen* joe = new BlueMen();

	for (int i = 0; i < 10; i++)
	{
		steve->attack(joe);
	}

	return 0;
}