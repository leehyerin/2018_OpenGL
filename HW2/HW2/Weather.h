#pragma once
#include "MyHeader.h"

class Weather
{
	vector<MyVec> vParticles;
	bool m_isFalling;
	WeatherType m_type;
public:
	Weather();
	~Weather();

	inline void ToggleFalling() { m_isFalling = !m_isFalling; }
	void Falling();
	bool CheckCollsionbyFloor(int);
	void CreateParticles();
	void Draw();

	void ToggleWeather();
};

