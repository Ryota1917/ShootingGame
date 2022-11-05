#pragma once
#include"Drawer.h"

class HPBarDrawer :public Drawer {
public:
	HPBarDrawer(class ShipActor* owner, int order = 100);
	void Draw(SDL_Renderer* renderer)override;

private:
	ShipActor* mShip;
};
