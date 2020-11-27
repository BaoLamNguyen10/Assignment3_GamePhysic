#include "BulletPool.h"
#include <iostream>
#include <vector>

BulletPool::BulletPool(int size) {
	for (int i = 0; i < size; i++) {
		Bullet* bullet = new Bullet();
		inactive.push_back(bullet);
		all.push_back(bullet);
	}

	std::cout << "Bullet Pool create with the size " << size << std::endl;


}

Bullet* BulletPool::Spawn() {
	Bullet* bullet = NULL;
	if (inactive.size() > 0) {
		bullet = inactive.back();
		bullet->Reset();
		bullet->active = true;
		inactive.pop_back();
		active.push_back(bullet);
		std::cout << "Spawn." << std::endl;
	}
	else {
		std::cout << "Warning. Max bullet spawned." << std::endl;
	}

	return bullet;
}

void BulletPool::Despawn(Bullet* bullet) {
	bullet->active = false;
	inactive.push_back(bullet);

	for (std::vector<Bullet*>::iterator myiter = active.begin(); myiter != active.end(); myiter++) {
		if (*myiter == bullet) {
			active.erase(myiter);
			std::cout << "Despawn." << std::endl;
			return;
		}
	}
	
}