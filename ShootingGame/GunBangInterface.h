#pragma once

class GunBangInterFace {
public:
	virtual ~GunBangInterFace() {};

	virtual bool Bang(float deltaTime) { return false; };
};