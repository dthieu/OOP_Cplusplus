#pragma once
#include "Animal.h"

class Cow : public Animal
{
public:
	void Talk();
	void ChoAn(float kg);
	void Move(Point2D P); // Di chuyển con vật tới vị trí có tọa độ P(x2,y2)
};

