// Name: Tyler Gauntlett
// Date: 11/8/2015
// Course: COP 3502

#include <stdio.h>
#include <stdlib.h>

void quickArmy(int* army, int low, int high);
int partitionArmy(int* unsortedArmy, int low, int high);
int countDefWins(int* atkAry, int* defAry, int armySize);
int* unsortedArmy(int armySize);


int main() {

	// Definiting variables.
	int i, cases, armySize, defWinCount;

	// Take in num of cases.
	scanf("%d", &cases);

	// Loop for number of cases specified in the input.
	while (cases > 0){

		scanf("%d", &armySize);

		// Fills both arrays with input values.
		int* atkArmy = unsortedArmy(armySize);
		int* defArmy = unsortedArmy(armySize);

		// Sort both arrays.
		quickArmy(atkArmy, 0, armySize - 1);
		quickArmy(defArmy, 0, armySize - 1);

		// Count increments if defArmy[i+1] > atkArmy[i]
		defWinCount = countDefWins(atkArmy, defArmy, armySize);

		printf("%d\n", defWinCount);

		// Free this after returning the sorted arrays.
		free(atkArmy);
		free(defArmy);

		cases--;
	}

	return 0;
}


int partitionArmy(int* army, int low, int high){

	// Setting the pivot point equal to the index of the last element.
	int pivot = army[high];
	// Set the swap variable to the lowest value in the array.
	int lastSwap = low;
	int temp, i;

	// Moves from the begining to the end of the array.
	// If the value is less than the pivot value, move it to the left.
	for (i = low; i < high; i++){

		// Stores the index of i into temp before overwritting.
		if (army[i] <= pivot) {
			temp = army[i];
			army[i] = army[lastSwap];
			army[lastSwap] = temp;
			lastSwap++;
		}

	}

	// Stores the index of i into temp before overwritting.
	temp = army[high];
	army[high] = army[lastSwap];
	army[lastSwap] = temp;

	return lastSwap;


}

void quickArmy(int* army, int low, int high){
	
	if (low < high){

		// Creates a partituion that will be used to recursively call.
		int part = partitionArmy(army, low, high);
		
		// Recurively breakdown an array into an first and second half.
		// Space is left for part itself.
		quickArmy(army, low, part - 1);
		quickArmy(army, part + 1, high);

	}

}


// Take the input and stores it in an array as it is receieved.
int* unsortedArmy(int armySize){

	int i;
	int* unsortedArmyAry = malloc(sizeof(int)*armySize);

	for (i = 0; i < armySize; i++){
		scanf("%d, ", &unsortedArmyAry[i]);
	}

	return unsortedArmyAry;
}

int countDefWins(int* atkAry, int* defAry, int armySize){

	int i = 0, j = 0, defWinCount = 0;
	
	// Stop when we're done with either list.
	while (i < armySize && j < armySize) {

		// Compares the index of atk and def. If def
		// is less or equal to atk, increment def index.
		if (defAry[i] <= atkAry[j]){
			i++;
		}

		// If def index is larger than atk, it adds to
		// the win count and moves both indexs forward.
		else{
			defWinCount++;
			j++;
			i++;
		}

	}

	return defWinCount;
}