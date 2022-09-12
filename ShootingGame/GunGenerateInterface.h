#pragma once

class GunGenerateInterface {
public:
	virtual ~GunGenerateInterface() {};

	virtual void Generate(class GunComponent* gun) {};
};