#include "Cashier.h"

/* Sets number of 10 Stotinki coins.
 *
 * arguments: none
 *
 * return type: void
 */
void Cashier::SetNumberOf_10_StotinkiCoins(const size_t number)
{
	value_10_Stotinki = number;
}

/* Sets number of 20 Stotinki coins.
 *
 * arguments: none
 *
 * return type: void
 */
void Cashier::SetNumberOf_20_StotinkiCoins(const size_t number)
{
	value_20_Stotinki = number;
}

/* Sets number of 50 Stotinki coins.
 *
 * arguments: none
 *
 * return type: void
 */
void Cashier::SetNumberOf_50_StotinkiCoins(const size_t number)
{
	value_50_Stotinki = number;
}

/* Sets number of 1 Leva coins.
 *
 * arguments: none
 *
 * return type: void
 */
void Cashier::SetNumberOf_1_LevaCoins(const size_t number)
{
	value_1_Leva = number;
}

/* Sets number of 2 Leva coins.
 *
 * arguments: none
 *
 * return type: void
 */
void Cashier::SetNumberOf_2_LevaCoins(const size_t number)
{
	value_2_Leva = number;
}

/* Sets number of 5 Leva banknotes.
 *
 * arguments: none
 *
 * return type: void
 */
void Cashier::SetNumberOf_5_LevaBanknotes(const size_t number)
{
	value_5_Leva = number;
}

/* Sets number of 10 Leva banknotes.
 *
 * arguments: none
 *
 * return type: void
 */
void Cashier::SetNumberOf_10_LevaBanknotes(const size_t number)
{
	value_10_Leva = number;
}

/* Sets number of 20 Leva banknotes.
 *
 * arguments: none
 *
 * return type: void
 */
void Cashier::SetNumberOf_20_LevaBanknotes(const size_t number)
{
	value_20_Leva = number;
}

/* Sets number of 50 Leva banknotes.
 *
 * arguments: none
 *
 * return type: void
 */
void Cashier::SetNumberOf_50_LevaBanknotes(const size_t number)
{
	value_50_Leva = number;
}

/* Sets number of 100 Leva banknotes.
 *
 * arguments: none
 *
 * return type: void
 */
void Cashier::SetNumberOf_100_LevaBanknotes(const size_t number)
{
	value_100_Leva = number;
}

/* Gets the full amount of money in the cash register.
 *
 * arguments: none
 *
 * return type: double
 */
double Cashier::GetMoney()
{
	money = static_cast<double>((value_100_Leva * 100u) + (value_50_Leva * 50u) + (value_20_Leva * 20u) + (value_10_Leva * 10u)
		+ (value_2_Leva * 2u) + (value_1_Leva * 1u) + (value_50_Stotinki * 0.5) + (value_20_Stotinki * 0.2) + (value_10_Stotinki * 0.1));
	return money;
}

/* Calculates the needed change to return to the customer.
 *
 * arguments: const double neededChange - change that is needed to be returned.
 *
 * return type: bool
 */
bool Cashier::IsChangeReady(const double neededChange)
{
	bool isReady = false;         // Returns the state of the opperation.
	bool isReturned = false;      // Returns the state of the given try to return the given currency.
	double change = neededChange; // Saves neededChange to the local variable.

	// Check if in the cash register are enoght money.
	if (neededChange < money)
	{
		do
		{
			isReturned = CalculateValue(change, value_100_Leva, 100);
			isReturned = CalculateValue(change, value_50_Leva, 50);
			isReturned = CalculateValue(change, value_20_Leva, 20);
			isReturned = CalculateValue(change, value_10_Leva, 10);
			isReturned = CalculateValue(change, value_5_Leva, 5);
			isReturned = CalculateValue(change, value_2_Leva, 2);
			isReturned = CalculateValue(change, value_1_Leva, 1);
			isReturned = CalculateValue(change, value_50_Stotinki, 0.5);
			isReturned = CalculateValue(change, value_20_Stotinki, 0.2);
			isReturned = CalculateValue(change, value_10_Stotinki, 0.1);
		} while (false == isReturned);

		isReady = true;
	}

	return isReady;
}

/* Calculates banknote or coin to be returned.
 *
 * arguments: double &change   - change that is needed to be returned.
 *            size_t &currency - currency in which to be returned.
 *            size_t value     - value of the currency which is wanted to be returned.
 *
 * return type: bool
 */
bool Cashier::CalculateValue(double& change, size_t& currency, double value)
{
	bool isAbleToReturn = false;

	// Check if there coints or bancknotes from giver value.
	if (0u < currency)
	{
		// Check if the needed change is higher than the wanted to return currency.
		if ((change + 0.05) > value)
		{
			change -= value;

			// This is needed because of not presiiton double values.
			if (0.09 > change)
			{
				change = 0.0;
			}

			currency--;
			isAbleToReturn = true;
		}
		else
		{
			isAbleToReturn = false;
		}
	}
	else
	{
		isAbleToReturn = false;
	}

	return isAbleToReturn;
}