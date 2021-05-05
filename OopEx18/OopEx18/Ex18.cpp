#include <iostream>
#include "Exceptions.h"
#include "Mushrooms.h"
#include "Meat.h"
#include "Spices.h"
#include "Cheese.h"
#include "Tomatoes.h"
#include "Pizza.h"
#include "Kebab.h"
#include "Dolma.h"
#include "Soup.h"
#include "Oven.h"
#include "Pot.h"
#include "Brazier.h"
using namespace std;

class System {
public:

	static void Menu() {
		try
		{
			size_t ingredient_count = 5;
			Mushrooms* mushroom = new Mushrooms(1, "Agaricus bisporus", 0.34, 3.09, 3.26, 93, "China");
			Meat* meat = new Meat(2, "Beef", 15, 26, 0, 250, "Cow");
			Spices* spices = new Spices(3, "Basil", 0.64, 3.15, 2.65, 94, "herb");
			Cheese* cheese = new Cheese(4, "Mozzarella", 22, 22.2, 2.2, 300, "Italy");
			Tomatoes* tomato = new Tomatoes(5, "Roma tomato", 0.2, 0.9, 3.9, 18, "Roma", "oblong");

			Ingredient** ingredients = new Ingredient * [ingredient_count] {
				mushroom, meat, spices, cheese, tomato
			};

			size_t meal_count = 4;
			Meal* pizza = new Pizza(1, "Neapolitan Pizza", "Large");
			Meal* kebab = new Kebab(2, "Lyulya kebab", "Medium well");
			Meal* dolma = new Dolma(3, "Leaf stuffing");
			Meal* soup = new Soup(4, "Chicken soup");

			Meal** meals = new Meal * [meal_count] {
				pizza, kebab, dolma, soup
			};

			size_t device_count = 3;
			CookingDevice* oven = new Oven(*pizza, true, 10);
			CookingDevice* pot = new Pot(*dolma, true, 20);
			CookingDevice* brazier = new Brazier(*kebab, true, 30);
			CookingDevice** devices = new CookingDevice * [device_count] { oven, brazier, pot };

			while (true)
			{
				size_t choiseMeal;
				cout << "Welcome. Which dish would you like to order?" << endl;
				cout << "1 --> Pizza" << endl;
				cout << "2 --> Kebab" << endl;
				cout << "3 --> Dolma" << endl;
				cout << "4 --> Soup" << endl;
				cout << "Make your choice --> ";
				cin >> choiseMeal;
				if (choiseMeal > meal_count) {
					cout << "The choice is wrong. Try again...";
					Sleep(1000);
					system("cls");
					continue;
				}
				for (size_t i = 0; i < meal_count; i++)
				{
					if (meals[i]->getId() == choiseMeal) {
						char choiseYesOrNo = NULL;
						while (choiseYesOrNo != 'n') {
							cout << "Meals of your choice --> " << meals[i]->getName() << endl;
							cout << "What ingredients do you want to add?" << endl;
							cout << "1 --> Mushrooms" << endl;
							cout << "2 --> Meat" << endl;
							cout << "3 --> Spices" << endl;
							cout << "4 --> Cheese" << endl;
							cout << "5 --> Tomato" << endl;
							cout << "Make your choice --> ";
							size_t choiseIngredient;
							cin >> choiseIngredient;
							if (choiseIngredient > ingredient_count) {
								cout << "The choice is wrong. Try again...";
								Sleep(1000);
								system("cls");
								continue;
							}
							size_t amount;
							for (size_t j = 0; j < ingredient_count; j++)
							{
								if (ingredients[j]->getId() == choiseIngredient) {
									cout << "Enter amount: ";
									cin >> amount;
									meals[i]->addIngredient(ingredients[j], amount);
									cout << "Ingredient added.Want to add another ingredient?(y/n) : ";
									cin >> choiseYesOrNo;
									if (choiseYesOrNo == 'y') {
										system("cls");
										continue;
									}
									else if (choiseYesOrNo == 'n') break;
									else {
										cout << "Incorrect choise, try again..." << endl;;
										Sleep(1000);
										continue;
									}
								}
							}
						}
						Meal* tempMeal;
						tempMeal = meals[i];
						for (size_t i = 0; i < device_count; i++)
						{
							if (devices[i]->getMeal() == tempMeal) {
								devices[i]->cook();
								tempMeal->taste();
								tempMeal->printRecipe();

								//Delete ingredients
								for (size_t i = 0; i < ingredient_count; i++)
								{
									delete[] ingredients[i];
								}
								delete[] ingredients;

								//Delete meals
								for (size_t i = 0; i < meal_count; i++)
								{
									delete[] meals[i];
								}
								delete[] meals;
								exit(0);
							}
						}


					}

				}
			}
		}
		catch (Exception& ex)
		{
			cout << "Exception occurred!";
			ex.PrintMsg();
		}




	}
};


int main()
{
	System::Menu();
}

