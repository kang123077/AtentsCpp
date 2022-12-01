#include "Dragon.h"
#include "Slaim.h"
#include "Golem.h"

int main() {
	Dragon dragonA("dragonA", 100, 40, 20);
	Dragon dragonB("dragonB", 120, 45, 22);

	Slaim slaimA("slaimA", 20, 10, 8, 20);
	Slaim slaimB("slaimB", 25, 12, 10, 22);

	Golem golemA("golemA", 80, 35, 30);
	Golem golemB("golemB", 90, 40, 35);


	dragonA.Attack(dragonB);

	slaimA.Attack(slaimB);

	dragonB.Attack(slaimB);

	slaimB.Attack(dragonA);

	golemA.Attack(dragonB);

	dragonB.Attack(golemA);


	return 0;
}