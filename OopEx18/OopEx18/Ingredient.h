#pragma once
#include "Exceptions.h"
using namespace std;

class Ingredient {
protected:
	size_t id;
	string name = "";
	double fats = NULL;
	double protein = NULL;
	double carbohydrates = NULL;
	int kcal = NULL;
public:
	Ingredient() = default;
	Ingredient(const size_t id, const string& name, const double fats, const double protein, const double carbohydrates, const int kcal)
	{
		setId(id);
		setName(name);
		setFats(fats);
		setProtein(protein);
		setCarbohydrates(carbohydrates);
		setKcal(kcal);
	}


	size_t getId()const {
		return id;
	}
	string getName()const {
		return name;
	}
	double getFats()const {
		return fats;
	}
	double getProtein()const {
		return protein;
	}
	double getCarbohydrates()const {
		return carbohydrates;
	}
	int getKcal()const {
		return kcal;
	}

	void setId(const size_t id) {
		if (id < 0) throw InvalidArgumentException("The id can't be negative", __LINE__, "Ex18.cpp", __TIME__);
		this->id = id;
	}
	void setName(const string& name) {
		if (name.empty()) throw NullException("Name is Null", __LINE__, "Ex18.cpp", __TIME__);
		this->name = name;
	}
	void setFats(const double fats) {
		if (fats < 0 ) throw InvalidArgumentException("The amount of fat can't be negative", __LINE__, "Ex18.cpp", __TIME__);
		this->fats = fats;
	}
	void setProtein(const double protein) {
		if (protein < 0) throw InvalidArgumentException("The amount of protein can't be negative", __LINE__, "Ex18.cpp", __TIME__);
		this->protein = protein;
	}
	void setCarbohydrates(const double carbohydrates) {
		if (carbohydrates < 0) throw InvalidArgumentException("The amount of carbohydrates can't be negative", __LINE__, "Ex18.cpp", __TIME__);
		this->carbohydrates = carbohydrates;
	}
	void setKcal(const double kcal) {
		if (kcal < 0) throw InvalidArgumentException("The amount of kcal can't be negative", __LINE__, "Ex18.cpp", __TIME__);
		this->kcal = kcal;
	}

	virtual void showIngredient() = 0 {
		cout << "Name: " << getName() << endl;
		cout << "Degree of fats: " << getFats() << endl;
		cout << "The amount of protein: " << getProtein() << endl;
		cout << "The amount of carbohydrates: " << getCarbohydrates() << endl;
		cout << "The amount of kcal: " << getKcal() << endl;
	}

	virtual ~Ingredient() = 0
	{

	}
};
