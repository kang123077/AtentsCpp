#include "Dragon.h"
#include "Slime.h"
#include "Golem.h"
#include "Ogre.h"
#include "Goblin.h"
#include "LizardMan.h"

int main() {
	Dragon dragonA("dragonA", 100, 40, 20);
	Dragon dragonB("dragonB", 120, 45, 22);

	Slime slaimA("slaimA", 20, 10, 8, 20);
	Slime slaimB("slaimB", 25, 12, 10, 22);

	Golem golemA("golemA", 80, 35, 30);
	Golem golemB("golemB", 90, 40, 35);

	Ogre ogreA("ogreA", 50, 30, 20, 18);
	Ogre ogreB("ogreB", 55, 32, 18, 17);

	Goblin goblinA("goblinA", 40, 20, 18, 10);
	Goblin goblinB("goblinB", 38, 18, 20, 12);

	LizardMan lizardManA("lizardManA", 40, 20, 18, 10);



	dragonA.Attack(dragonB);

	slaimA.Attack(slaimB);

	dragonB.Attack(slaimB);
	dragonB.Attack(slaimB);

	slaimB.Attack(dragonA);

	golemA.Attack(dragonB);

	dragonB.Attack(golemA);


	dragonB.Attack(ogreB);

	golemA.Attack(goblinB);

	dragonB.Attack(lizardManA);


	return 0;
}