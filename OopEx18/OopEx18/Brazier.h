#pragma once
#include "Cooking Devices.h"

class Brazier :public CookingDevice {
public:
	Brazier() = default;
	Brazier(Meal& meal, const bool isCooked, const int second) :CookingDevice(meal, isCooked, second)
	{

	}

	void cook() override {
		system("cls");
		cout << "The meal was sent to the brazier for cooking ";
		for (size_t i = 0; i < 3; i++)
		{
			Sleep(1000);
			cout << ". ";
		}
		cout << endl;
		CookingDevice::cook();
	}
};