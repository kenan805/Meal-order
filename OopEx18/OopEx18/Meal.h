#pragma once
#include "Recipe.h"

class Meal {
protected:
	size_t _id;
	RecipetItem** ingredients = nullptr;
	int count = NULL;
	string name = "";
public:
	Meal() = default;
	Meal(const size_t id,const string& name)
	{
		setId(id);
		setName(name);
	}

	RecipetItem** getIngredients()const {
		return ingredients;
	}
	int getCount()const {
		return count;
	}
	string getName()const {
		return name;
	}
	size_t getId()const {
		return _id;
	}

	void setId(const size_t id) {
		if (id < 0) throw InvalidArgumentException("The id can't be negative", __LINE__, "Ex18.cpp", __TIME__);
		_id = id;
	}
	void setIngredients(RecipetItem** ingredients) {
		if (ingredients == nullptr) throw NullException("Ingredients is Null", __LINE__, "Ex18.cpp", __TIME__);
		this->ingredients = ingredients;
	}
	void setCount(const int count) {
		if (count < 0) throw InvalidArgumentException("Count of ingredients can't be negative.", __LINE__, "Ex18.cpp", __TIME__);
		this->count = count;
	}
	void setName(const string& name) {
		if (name.empty()) throw NullException("Name is Null", __LINE__, "Ex18.cpp", __TIME__);
		this->name = name;
	}

	void addIngredient(Ingredient* ingredient, int amount) {
		if (ingredient == nullptr) throw NullException("Ingredient is Null", __LINE__, "Ex18.cpp", __TIME__);
		else if (amount <= 0) throw SystemException("The amount must be above zero.", __LINE__, "Ex18.cpp", __TIME__);
		auto new_ingredients = new RecipetItem * [count + 1];

		for (size_t i = 0; i < count; i++)
		{
			new_ingredients[i] = ingredients[i];
		}

		auto new_recipe_item = new RecipetItem(*ingredient, amount);
		new_ingredients[count] = new_recipe_item;

		delete[] ingredients;
		ingredients = new_ingredients;
		new_ingredients == nullptr;
		count++;

	}

	virtual void taste() {
		cout << "\nMmm... Very deliciouss..." << endl;
	}

	virtual void printRecipe() = 0 {
		cout << "v v v v v v v Recipe info v v v v v v v" << endl;
		for (size_t i = 0; i < count; i++)
		{
			cout << "Ingredients --> " << i + 1  << endl;
			getIngredients()[i]->getIngredient().showIngredient();
			cout << "Amount: " << getIngredients()[i]->getAmount() << endl;
			cout << endl;
		}
	}

	virtual ~Meal() = 0 {

	}
};