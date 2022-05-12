#include <math.h>
#include <stdlib.h>
#include "Customer.h"

/* Generates random double variable. With set number of digits before and after the decimal point.
 * 
 * arguments: const rsize_t numberOfCharectersBeforePoint - number of digits before the decimal point.
 *            const rsize_t numberOfCharectersAfterPoint  - number of digits after the decimal point.
 * 
 * return type: double
 */
double Customer::GenerateRandomDouble(const rsize_t numberOfCharectersBeforePoint, const rsize_t numberOfCharectersAfterPoint)
{
	double number = 0.0; //Double number that will be returned.
	rsize_t countAfter = 1u; // Tell in which position after decimal point chareter is.
	rsize_t countBefore = 0u; // Tell in which position before decimal point chareter is.
	double temp = 0.0; // Randow generated number. 

	while ((countAfter < (numberOfCharectersAfterPoint + 1u)) || (countBefore < numberOfCharectersBeforePoint))
	{
		temp = static_cast<double>(rand() % 9);

		// Add charecters before decimal point.
		if (countBefore < numberOfCharectersBeforePoint)
		{
			// Add next charecter to the number.
			number += temp * static_cast<double>(pow(static_cast < double>(10), static_cast<double>(countBefore)));
			countBefore++;
		}
		else // Add charecters after decimal point.
		{
			// Add next charecter to the number.
			number += temp / static_cast<double>(pow(static_cast<double>(10), static_cast<double>(countAfter)));
			countAfter++;
		}
	}

	return number;
}

/* Calculats the wanted change.
 *
 * arguments: none
 *
 * return type: void
 */
void Customer::CalculetWantedChange()
{
	wantedChange = GenerateRandomDouble(2u, 1u);
}

/* Gets the wanted change from the customer.
 *
 * arguments: none
 *
 * return type: double
 */
double Customer::GetWantedChange()
{
	CalculetWantedChange();
	return wantedChange;
}