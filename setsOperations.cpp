
#include <iostream>
#include <iomanip>

using namespace std;


class sets {
	int* arr;
	bool filled;
	int size;
	int curr;
public:
	// friends functions to access the objects outside the class
	friend sets findingUnion(sets& a, sets& b);
	friend sets findingIntersection(sets& a, sets& b);
	friend sets aMinusB(sets& a, sets& b);
	// constructor
	sets() {
		filled = false;
		arr = nullptr;
		size = 0;
		curr = 0;
	}
	// allocates the memory 
	void memoryAllocation(int size) {
		this->size = size;
		arr = new int[size];
		cout << endl;
	}
	// returns if the set is populated or not
	bool isPopulated() {
		return filled;
	}
	// populates the sets
	void populate() {
		for (int x = 0; x < size; x++) {
			cout << "Entry no " << x + 1 << " : ";
			cin >> arr[x];
			curr++;
		}
		cout << "THE SET HAS BEEN POPULATED" << endl;
		cout << endl;
		filled = true;
	}
	// free the space of the sets
	void freeSpace() {
		filled = false;
		size = 0;
		delete[]arr;
		arr = nullptr;
	}
	// returns the length
	int getLength() {
		return size;
	}
	// pushes the element into the set
	void push(int number) {
		arr[curr++] = number;
	}

	// prints the set
	void print() {
		for (int x = 0; x < curr; x++) {
			cout << " " << arr[x] << " ";
		}
	}

	// bubblesort to sort the set
	void sort() {
		for (int x = 0; x < curr; x++) {
			for (int y = 0; y < curr - x - 1; y++) {
				if (arr[y] > arr[y + 1]) {
					swap(arr[y], arr[y + 1]);
				}
			}
		}
	}
	// returns if the is empty or not
	bool isEmpty() {
		return (curr == 0);
	}
};

// searches the element in the set
bool search(int number, int arr[],int size) {
	for (int x = 0; x < size; x++) {
		if (number == arr[x]) {
			return false;
		}
	}
	return true;
}

// returns the union of the sets
sets findingUnion(sets& a, sets& b) {
	sets s;
	int size1 = a.getLength();
	int size2 = b.getLength();
	s.memoryAllocation(size1 + size2);

	for (int x = 0; x < size1; x++) {
			s.push(a.arr[x]);
		
	}
	for (int x = 0; x < size2; x++) {
		if (search(b.arr[x], a.arr, a.size)) {
			s.push(b.arr[x]);
		}
	}
	return s;

}

// returns the interSection of the sets
sets findingIntersection(sets& a, sets& b) {
	sets s;
	int size1 = a.getLength();
	int size2 = b.getLength();
	int approxSize = min(size1, size2);
	s.memoryAllocation(approxSize);
	for (int x = 0; x < size2; x++) {
		if (!search(b.arr[x], a.arr, size1)) {
			s.push(b.arr[x]);
		}
	}
	
	if (s.isEmpty()) {
		return s;
	}
	else {
		s.filled = true;
		return s;
	}
	
}

// this is menu of the program
void menu() {
	cout << endl << endl;
	cout << "        0. Free Space " << endl;
	cout << "        1. Create Sets" << endl;
	cout << "        2. Find Union Of Two Sets" << endl;
	cout << "        3. Find InterSection Of Two Sets" << endl;
	cout << "        4. Print Sets" << endl;
	cout << "        5. A - B" << endl;
	cout << "        6. B - A" << endl;
	cout << "        7. Total Numbers Of Relations" << endl;
	cout << "        8. Check Reflexivity" << endl;
	cout << "        9. Check Symmetry" << endl;
	cout << "        10. Check Anti-Symmetry" << endl;

	cout << "        11. Exit" << endl;
	
	cout << endl << endl;
}

// prints both sets
void printBoth(sets& a, sets& b) {
	if (a.isPopulated()) {
		cout << "SET A : ";
		a.print();
	}
	cout << endl;
	if (b.isPopulated()) {
		cout << "SET B : ";
		b.print();
	}
}

// returns A - B 
sets aMinusB(sets& a, sets& b) {
	sets s;
	s.memoryAllocation(a.size);
	for (int x = 0; x < a.size; x++) {
		if (search(a.arr[x], b.arr, b.size)) {
			s.push(a.arr[x]);
		}
	}
	if (!s.isEmpty()) {
		s.filled = true;
		return s;
	}
	return s;
}



// ordered pair has two data members 
struct orderPair {
	int leftData;
	int rightData;
	orderPair() {
		leftData = -1;
		rightData = -1;
	}
	orderPair(int val1, int val2) {
		leftData = val1;
		rightData = val2;
	}
};

// search over the array to find the element
bool searchOverArray(int arr[], int size, int number) {
	for (int x = 0; x < size; x++) {
		if (arr[x] == number) {
			return false;
		}
	}
	return true;
}

// search over the ordered pairs to see if that pairs exits or not
bool searchOverPairs(orderPair array[], int size, int number) {
	bool found = false;
	for (int x = 0; x < size; x++) {
		if (number == array[x].leftData && array[x].rightData == number) {
			found = true;
		}
	}
	return found;
}

// searching of the symmetry that if the image is found or not
bool searchOfSymmetry(orderPair arr[], int size, orderPair* p1) {
	for (int x = 0; x < size; x++) {
		if (p1->leftData == arr[x].leftData && p1->rightData == arr[x].rightData) {
			return true;
		}
	}
	return false;
}

// class to create ordered pairs
class Relation {
	orderPair* arr;
	int size;
	int* array;
	int arr_size;
	int curr;
	int* solutionArray;
public:
	// constructor
	Relation(int size) {
		this->size = size;
		arr = new orderPair[size];
		arr_size = size * 2;
		array = new int[arr_size];
		curr = 0;
		solutionArray = nullptr;
	}
	// allocating memory to the solution array
	void solArray(int size) {
		solutionArray = new int[size];
	}
	// populating the ordered pairs
	void populate() {
		for (int x = 0; x < size; x++) {
			cin >> arr[x].leftData;
			cin >> arr[x].rightData;
			cout << "( " << arr[x].leftData << " , " << arr[x].rightData << " ) " << endl;
		}
	}
	// pushing the data into the array of distinct members
	void push(int val) {
		array[curr++] = val;
	}
	// checking all the members of the orderd pairs to see if the already exists in the distnct array or not
	void distinct() {
		for (int x = 0; x < size; x++) {
			int left = arr[x].leftData;
			int right = arr[x].rightData;
			if (searchOverArray(array, curr, left)) {
				push(left);
			}
			if (searchOverArray(array, curr, right)) {
				push(right);
			}
		}
	}
	// printing distinct for seeing the working purposes
	void printDistinct() {
		for (int x = 0; x < curr; x++) {
			cout << array[x] << " ";
		}
	}
	// checks the reflextivity and populates the solutiona array
	void findingReflexivity() {
		solArray(curr);
		for (int x = 0; x < curr; x++) {
			if (searchOverPairs(arr, size, array[x])) {
				solutionArray[x] = 1;
			}
			else {
				solutionArray[x] = 0;
			}
		}
	}
	// returns if the pairs are reflexive or not
	void solutionGiven() {
		for (int x = 0; x < curr; x++) {
			if (solutionArray[x] == 0) {
				cout << endl;
				cout << "IT IS NOT REFLXIVE....." << endl;
				return;
			}
		}
		cout << endl;
		cout << "IT IS REFLEXIVE......" << endl;
	}

	// populates the solution array based on the symmetry
	void symmetry() {
		solArray(size);
		for (int x = 0; x < size; x++) {
			int left = arr[x].leftData;
			int right = arr[x].rightData;
			orderPair *n = new orderPair(right, left);
			if (searchOfSymmetry(arr, size, n)) {
				solutionArray[x] = 1;
			}
			else {
				solutionArray[x] = 0;
			}
		}
	}
	// returns the result if that pairs are symmetric or not
	void isSymmetry() {
		for (int x = 0; x < size; x++) {
			if (solutionArray[x] == 0) {
				cout << "IT IS NOT SYMMETRIC" << endl;
				return;
			}
		}
		cout << "IT IS SYMMETRIC" << endl;
	}
	// returns if the pairs are anti symmetric
	bool AntiSymmetric() {
		bool isAntiSymmetric = true;
		for (int x = 0; x < size; x++) {

			int left = arr[x].leftData;
			int right = arr[x].rightData;
			if (left == right) {
				continue;
			}
			orderPair* n = new orderPair(right, left);
			if (searchOfSymmetry(arr, size, n)) {
				isAntiSymmetric = false;
			}
		}
		return isAntiSymmetric;
	}

};










int main()
{
	sets a;
	sets b;
	while (true) {
		menu();					// it is the menu function
		int option = 0;
		cout << "Enter Choice => ";
		cin >> option;
		if (cin.fail()) {				// in case of input failure
			cin.clear();
			cin.ignore();
			system("CLS");
			continue;
		}
		if (option == 0) {
			if (a.isPopulated()) {				// free the space of all the sets to create new sets
				a.freeSpace();
				b.freeSpace();
				cout << "You Can Create New Sets Now..." << endl;
			}
		}
		else if (option == 1) 
		{
			int size = 0;
			if (!a.isPopulated()) {				// checking if the set is already populated
				cout << "Enter The Size Of Set A : ";
				cin >> size;
				a.memoryAllocation(size);		// allocating memory to the set A
				a.populate();					// populating sets
			}
			else if (!b.isPopulated()) {		
				cout << "Enter The Size Of Set B : ";
				cin >> size;
				b.memoryAllocation(size);		// similarily for set B
				b.populate();					
			}
			else {
				cout << "Not Enough Space... Please Free The Existing Space....." << endl;    // alert to empty the existing space to create new 
			}

		}
		else if (option == 2) {
			if (!a.isPopulated() || !b.isPopulated()) {			// before union check if sets are populated
				cout << "Populate First!!" << endl;
				cout << endl;
				system("pause");
				system("CLS");
				continue;
			}
			sets unionSet;
			unionSet = findingUnion(a, b);		// findingUnion returns the set of union 
			unionSet.sort();					// sorting of unions for better experience
			cout << "THE UNION IS => ";
			unionSet.print();					// printing the sets (union).
		}
		else if (option == 3) {
			if (!a.isPopulated() || !b.isPopulated()) {
				cout << "Populate First!!" << endl;
				cout << endl;
				system("pause");
				system("CLS");
				continue;
			}
			sets intersectionSet;
			intersectionSet = findingIntersection(a, b);    // returns the interSection of the set
			intersectionSet.sort();							// similarily sort the set
			if (!intersectionSet.isPopulated()) {			// if the set has no common elements 
				cout << "No Common Elements Found" << endl;
				continue;
			}
			cout << "THE INTERSECTION IS => ";
			intersectionSet.print();					// prints the interSection
		}
		else if (option == 4) {
			if (!a.isPopulated()) {
				cout << "Populate First!!" << endl;
				cout << endl;
				system("pause");
				system("CLS");
				continue;
			}
			printBoth(a,b);				// printing both sets
		}
		else if (option == 5) {
			if (!a.isPopulated() || !b.isPopulated()) {
				cout << "Populate First!!" << endl;
				cout << endl;
				system("pause");
				system("CLS");
				continue;
			}
			cout << "FINDING A - B" << endl;
			sets AB = aMinusB(a, b);  // returns A - B
			if (AB.isPopulated()) {   // cheching if set a is the subset or not
				cout << " A - B : ";
				AB.print();
			}
			else {
				cout << "A is a subset of B" << endl;
			}
		}
		else if (option == 6) {
			if (!a.isPopulated() || !b.isPopulated()) {
				cout << "Populate First!!" << endl;
				cout << endl;
				system("pause");
				system("CLS");
				continue;
			}
			cout << "FINDING B - A" << endl;
			sets BA = aMinusB(b, a);				// returns B - A parameters opposition
			if (BA.isPopulated()) {					// cheching if it is not the subset
				cout << " B - A : ";
				BA.print();
			}
			else {
				cout << "B is a subset of A" << endl;
			}
		}
		else if (option == 7) {
			if (!a.isPopulated() || !b.isPopulated()) {
				cout << "Populate First!!" << endl;
				cout << endl;
				system("pause");
				system("CLS");
				continue;
			}
			int size1 = a.getLength();
			int size2 = b.getLength();
			
			cout << "NUMBER OF REALATIONS => "<<setprecision(20)<< pow(2, size1 * size2) << endl;  // finding total numbers of relations
			cout << endl;

		}
		else if (option == 8) {
			cout << "Finding Reflexivity......." << endl;
			int pairs;
			cout << "ENTER THE NUMBER OF ORDERED PAIRS => ";
			cin >> pairs;
			Relation r1(pairs);				// creating ordered Pairs 
			cout << "ENTER PAIRS : " << endl;
			r1.populate();          // populating the sets
			r1.distinct();			// finding distinct element to find their images. let a is a dintinct element ( to find (a,a) later.) 
			r1.findingReflexivity();   // finding the sets (a,a) based on the distinct elements.
			r1.solutionGiven();				// returns the solution
		}
		else if (option == 9) {
			cout << "Finding Symmetry...." << endl;
			int symmetricPairs;
			cout << "ENTER THE NUMBER OF ORDERED PAIRS => ";
			cin >> symmetricPairs;
			Relation r1(symmetricPairs);    // create the ordered pairs
			cout << "ENTER PAIRS : " << endl;
			r1.populate();				//populate the ordered pairs
			r1.symmetry();				//storing the result in the solution array (if the mirror image has found or not).
			r1.isSymmetry();			// providing result
		}
		else if (option == 10) {
			cout << "Finding Anti-Symmetry......" << endl;
			int antiSymmetric;
			cout << "ENTER THE NUMBER OF ORDERED PAIRS => ";
			
			cin >> antiSymmetric;
			cout << "ENTER PAIRS : " << endl;
			Relation r1(antiSymmetric);
			r1.populate();     // populates the ordered pairs
			if (r1.AntiSymmetric()) {    // checks if the ordered pairs are anti symmetric
				cout << "YES, IT IS ANTI-SYMMETRIC....." << endl;
			}
			else {
				cout << "IT IS NOT ANTI SYMMETRIC" << endl;
			}

		}
		else if (option == 11) {                    // exiting the program
			cout << "EXITING......";
			system("pause");
			break;
		}
		else {
			cout << "INVALID INPUT..." << endl;
		}
		cout << endl;
		system("pause");
		system("CLS");
	}
	return 0;
}