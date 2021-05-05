#pragma once
#include "Cooking Devices.h"

class Oven :public CookingDevice {
public:
	Oven() = default;
	Oven(Meal& meal, const bool isCooked, const int second) :CookingDevice(meal, isCooked, second)
	{

	}

	void cook() override {
		system("cls");
		cout << "The meal was sent to the oven for cooking ";
		for (size_t i = 0; i < 3; i++)
		{
			Sleep(1000);
			cout << ". ";
		}
		cout << endl;
		CookingDevice::cook();
	}
};