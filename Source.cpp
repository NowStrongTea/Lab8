#include <iostream>
#include <fstream>
#include <time.h>
#include <conio.h>

// The function fills the array with random non-repeating numbers
void filRanArrInt(int *inputArray, int length)
{
	//==================================================
	std::ofstream outputFile("Log file.txt");
	//==================================================
	int i = 1;
	bool fill = true;
	srand(time(NULL)); // Key for randomizer
	int tmp = rand() % length + 1; // Create a variable and assign it a random value
	inputArray[0] = tmp; // We fill the zero element of the array with a random number (there will be no repetitions of the number, since there is only one element)
	while (i < length)
	{
		fill = true;
		tmp = rand() % length + 1; // Assign a variable a random value from 1 to length inclusive
		for (int j = 0; j != i; j++)
		{
			if (inputArray[j] == tmp) // If the random value is equal to the value of the element in the array, randomize the new value
			{
				fill = false;
				break; // Exit the loop
			}
		}
		if (fill) // If the random number is not in the array
		{
			inputArray[i] = tmp;
			i++; // Increment i
		}
	}
	//==================================================
	if (outputFile.is_open())
	{
		for (int i = 0; i < length; i++)
		{
			outputFile << inputArray[i] << ' ';
		}
		outputFile.close();
	}
}

int main()
{
	int* arrayInt = nullptr;
	int lengthArrayInt = 0;
	std::cout << "Enter a natural number N: ";
	std::cin >> lengthArrayInt;
	arrayInt = new int[lengthArrayInt]; // Allocate dynamic memory for an Int array of size lengthArrayInt
	filRanArrInt(arrayInt, lengthArrayInt);
	for (int i = 0; i < lengthArrayInt; i++)
	{
		char x = _getch();
		std::cout << arrayInt[i] << ' ';
	}
	std::cout << '\n';
	delete[] arrayInt; // Clearing allocated memory
	arrayInt = nullptr; // Cleaning up the link
	return 0;
}