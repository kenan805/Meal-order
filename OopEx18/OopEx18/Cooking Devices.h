#pragma once
#include<Windows.h>
#include "Meal.h"

class CookingDevice {
protected:
	Meal* meal = NULL;
	bool isCooked = NULL;
	int second = NULL;
public:
	CookingDevice() = default;
	CookingDevice(Meal& meal, const bool isCooked, const int second)
	{
		setMeal(meal);
		setIsCooked(isCooked);
		setSecond(second);
	}

	Meal* getMeal()const {
		return meal;
	}
	bool getIsCooked()const {
		return isCooked;
	}
	int getSecond()const {
		return second;
	}

	void setMeal(Meal& meal) {
		if (&meal == NULL) throw NullException("Meal is Null", __LINE__, "Ex18.cpp", __TIME__);
		this->meal = &meal;
	}
	void setIsCooked(const bool isCooked) {
		this->isCooked = isCooked;
	}
	void setSecond(const int second) {
		if (second < 0) throw InvalidArgumentException("Second can't be negative.", __LINE__, "Ex18.cpp", __TIME__);
		this->second = second;
	}

	virtual void cook() = 0 {
		cout << "\nThe meal will be ready in " << getSecond() << " seconds." << endl;
		Sleep(5000);
		setIsCooked(true);
		cout << "\nThe meal is ready, bon appetit." << endl;
		Sleep(1000);
	}
};