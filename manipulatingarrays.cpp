#include <iostream>
using namespace std;

bool insert(int value, int intArray[], int &numberOfValidEntries, int size);
bool Delete(int value, int intArray[], int &numberOfValidEntries);
void print(int intArray[], int &numberOfValidEntreies);

int main() {
	char key = 'R';
	int intArray[10];
	int choice = 0;
	int input = 0;
	int numberOfValidEntries = 0;
	bool quit = false;
	do {
		//put menu here becasue it makes most sense to me
		cout << "==================MENU==================" << endl;
		cout << "1- Press 1 if you want to INSERT to the array." << endl;
		cout << "2- Press 2 if you want to DELETE from array." << endl;
		cout << "3- Press 3 if you want to print." << endl;
		cout << "4- Press 4 if you want to quit program." << endl;
		cout << "Your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "What number would you like to insert?: ";
			cin >> input;
			insert(input, intArray, numberOfValidEntries, 10);
			break;

		case 2:
			cout << "What number would you like to delete?: ";
			cin >> input;
			Delete(input, intArray, numberOfValidEntries);
			break;

		case 3:
			print(intArray, numberOfValidEntries);
			cout << endl;
			break;

		case 4:
			cout << "Goodbye." << endl;
			key = 'V'; //breaks out of do-while
			break;

		default:
			cout << "Not a valid choice. Please try again." << endl;
			system("pause");
			main();
			break;

		}
	} while (key == 'R');
	system("pause");
	return 0;
}

bool insert(int value, int intArray[], int & numberOfValidEntries, int size) {
	//if array at capacity
	if (numberOfValidEntries == size)
		return false;
	//if array empty
	if (numberOfValidEntries == 0) {
		intArray[0] = value;
		numberOfValidEntries += 1;
		return true;
	}
	// if value <= any of element in array
	for (int i = 0; i<numberOfValidEntries; i++)
	{
		if (value <= intArray[i]) {
			for (int j = numberOfValidEntries; j>i; j--) intArray[j] = intArray[j - 1];
			intArray[i] = value;
			numberOfValidEntries += 1;
			return true;
		}
	}
	//if value > all of elemnts in array
	intArray[numberOfValidEntries] = value;
	numberOfValidEntries += 1;
	return true;
}

bool Delete(int value, int intArray[], int &numberOfValidEntries) {
	int stuff = -1;
	//Search for value
	for (int i = 0; i<(numberOfValidEntries); i++) {
		if (intArray[i] == value) {
			stuff = i;
			break;
		}
	}
	if (stuff == -1) {
		return false;
	}
	//deleting and moving
	else {
		for (int i = stuff; i<(numberOfValidEntries)-1; i++) {
			intArray[i] = intArray[i + 1];
		}
		numberOfValidEntries = (numberOfValidEntries)-1;
		return true;
	}
}

void print(int intArray[], int &numberOfValidEntries) {
	if (numberOfValidEntries == 0) {
		cout << "Array is empty.";
	}
	else {
		cout << "Array: "; //makes everything clear
		for (int i = 0; i < numberOfValidEntries; i++) {
			cout << intArray[i] << " ";
		}
	}
}
