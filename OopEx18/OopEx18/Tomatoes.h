#pragma once
#include "Ingredient.h"

using namespace std;

class Tomatoes :public Ingredient {
	string _country;
	string _form;
public:
	Tomatoes(const size_t id, const string& name, const double fats, const double protein, const double carbohydrates, const int kcal, const string& country, const string& form) :Ingredient(id, name, fats, protein, carbohydrates, kcal) {
		setCountry(country);
		setForm(form);
	}

	string getCountry()const {
		return _country;
	}
	string getForm()const {
		return _form;
	}

	void setCountry(const string& country) {
		if (country.empty()) throw NullException("Cheese country is Null", __LINE__, "Ex18.cpp", __TIME__);
		_country = country;
	}
	void setForm(const string& form) {
		if (form.empty()) throw NullException("Form is Null", __LINE__, "Ex18.cpp", __TIME__);
		_form = form;
	}

	void showIngredient() override {
		Ingredient::showIngredient();
		cout << "Tomato country: " << getCountry() << endl;
		cout << "Tomato form: " << getForm() << endl;
	}

};