#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//state
class State {
	string name;
	string capital;
	int area;
	int yearOfSubmission;
	int orderOfAdmission;

public:

	State() {
		name = '0';
		capital = '0';
		orderOfAdmission = yearOfSubmission = area = -1;
	}

	State(char name, char cap, int a, int y, int o) {
		this->name = name;
		this->capital = cap;
		this->area = a;
		this->yearOfSubmission = y;
		this->orderOfAdmission = o;
	}

	/*GET*/
	string getName() {
		return this->name;
	}
	string getCapital() {
		return this->capital;
	}
	int getArea() {
		return this->area;
	}
	int getYearOfSubmission() {
		return this->yearOfSubmission;
	}
	int getOrderOfAdmission() {
		return this->orderOfAdmission;
	}
	/*SET*/
	void setName(string name) {
		this->name = name;
	}
	void setCapital(string capital) {
		this->capital = capital;
	}
	void setArea(int area) {
		this->area = area;
	}
	void setYearOfSubmission(int year) {
		this->yearOfSubmission = year;
	}
	void setOrderOfAdmission(int year) {
		this->orderOfAdmission = year;
	}

	//overloading comparison operator
	bool operator==(State other)
	{
		if (this->name == other.getName())
			return true;
		return false;
	}

	bool operator!=(State other)
	{
		if (this->name != other.getName())
			return true;
		return false;
	}
};

ostream& operator<<(ostream& os, State& dt)
{
	os << dt.getCapital() << ' ' << dt.getCapital() << endl;
	return os;
}


//contains and manipulates state data
class StateData:public string {

	int size;
	State state;
	vector<State> statelist;

public:

	string getString(int i) {
		char str = (char)i+35;
		string str_1;
		stringstream ss;

		ss << str;
		ss >> str_1;

		return str_1;
	}

	StateData() {
		size = 0;
	}

	void createSomeStates() {
		
		for (int i = 0; i < 35; i++) {

			state.setName("stateName" + getString(i));
			state.setArea(i);
			state.setCapital("cap" + getString(i+20));
			state.setOrderOfAdmission(i);
			state.setYearOfSubmission(1885 + (i * 3));

			size++;
			statelist.push_back(state);

		}
	}

	void printStates() {

		for (int i = 0; i < statelist.size(); i++) {
			cout << "Name: " << statelist[i].getName() << endl;
			cout << "Area: " << statelist[i].getArea() << endl;
			cout << "Capital: " << statelist[i].getCapital() << endl;
			cout << "Order of Submission into Union: " << statelist[i].getOrderOfAdmission() << endl;
			cout << "Year of Submission: " << statelist[i].getYearOfSubmission() << endl;
			cout << endl;
		}

	}

};

//from class

template <class elemType>
class hashT
{
public:

	//overloading operators
	bool operator=(State &otherState) {

		if (this->name == otherState.getName()) {
			return true;
		}

		return false;
	}

	bool operator!=(State &otherState) {
		if (this->name == otherState.getName()) {
			return true;
		}

		return false;
	}

	void insert(int hashIndex, const elemType& rec);
	//Function to insert an item in the hash table. The first
	//parameter specifies the initial hash index of the item to 
	//be inserted. The item to be inserted is specified by the 
	//parameter rec.
	//Postcondition: If an empty position is found in the hash
	//   table, rec is inserted and the length is incremented by
	//   one; otherwise, an appropriate error message is
	//   displayed.

	void search(int& hashIndex, const elemType& rec, bool& found) const;
	//Function to determine whether the item specified by the
	//parameter rec is in the hash table. The parameter hashIndex
	//specifies the initial hash index of rec.
	//Postcondition: If rec is found, found is set to true and
	//   hashIndex specifies the position where rec is found;
	//   otherwise, found is set to false.

	bool isItemAtEqual(int hashIndex, const elemType& rec) const;
	//Function to determine whether the item specified by the
	//parameter rec is the same as the item in the hash table 
	//at position hashIndex.
	//Postcondition: Returns true if HTable[hashIndex] == rec;
	//   otherwise, returns false.

	void retrieve(int hashIndex, elemType& rec) const;
	//Function to retrieve the item at position hashIndex.
	//Postcondition: If the table has an item at position
	//   hashIndex, it is copied into rec.

	void remove(int hashIndex, const elemType& rec);
	//Function to remove an item from the hash table.
	//Postcondition: Given the initial hashIndex, if rec is found
	//   in the table it is removed; otherwise, an appropriate
	//   error message is displayed.

	void print() const;
	//Function to output the data.

	hashT(int size = 101);
	//constructor
	//Postcondition: Create the arrays HTTable and indexStatusList;
	//   initialize the array indexStatusList to 0; length = 0;
	//   HTSize = size; and the default array size is 101.

	~hashT();
	//destructor
	//Postcondition: Array HTable and indexStatusList are deleted.
	int hashFunc(string name)
	{
		int i, sum;
		int len;
		i = 0;
		sum = 0;
		len = name.length();

		for (int k = 0; k < 15 - len; k++)
		{
			name = name + ' ';//increase name to 15;
		}

		for (int k = 0; k < 5; k++)
		{
			sum = sum + ((int)name[i]) * 128 * 128 + ((int)name[i + 1])
				* 128 + (int)name[i + 2];
			i += 3;
		}

		return sum%HTSize;

	}
private:
	elemType *HTable;   //pointer to the hash table
	int *indexStatusList;  //pointer to the array indicating the
						   //status of a position in the hash table
	int length;    //number of items in the hash table
	int HTSize;    //maximum size of the hash table
};

template <class elemType>
void hashT<elemType>::insert(int hashIndex, const elemType& rec)
{
	int pCount;
	int inc;

	pCount = 0;
	inc = 1;

	while (indexStatusList[hashIndex] == 1
		&& HTable[hashIndex] != rec
		&& pCount < HTSize / 2)
	{
		pCount++;
		hashIndex = (hashIndex + inc) % HTSize;
		inc = inc + 2;
		cout << "\nCOLLISION\n";
	}


	if (indexStatusList[hashIndex] != 1)
	{
		HTable[hashIndex] = rec;
		indexStatusList[hashIndex] = 1;
		length++;
	}
	else
		if (HTable[hashIndex] == rec)
			cerr << "Error: No duplicates are allowed." << endl;
		else
			cerr << "Error: The table is full. "
			<< "Unable to resolve the collision." << endl;
}

template <class elemType>
void hashT<elemType>::search(int& hashIndex, const elemType& rec, bool& found) const
{
	cout << "See Programming Exercise 7 at the end of Chapter 9." << endl;
}

template <class elemType>
bool hashT<elemType>::isItemAtEqual(int hashIndex, const elemType& rec) const
{
	cout << "See Programming Exercise 7 at the end of Chapter 9." << endl;
}

template <class elemType>
void hashT<elemType>::retrieve(int hashIndex, elemType& rec) const
{
	cout << "See Programming Exercise 7 at the end of Chapter 9." << endl;
}

template <class elemType>
void hashT<elemType>::remove(int hashIndex, const elemType& rec)
{
	cout << "See Programming Exercise 7 at the end of Chapter 9." << endl;
}

template <class elemType>
void hashT<elemType>::print() const
{
	for (int i = 0; i < this->HTSize; i++)
	{
		if (indexStatusList[i] == 1)
		{
			cout << HTable[i];
		}
	}
}

template <class elemType>
hashT<elemType>::hashT(int size)
{
	HTSize = size;
	HTable = new elemType[HTSize];   //pointer to the hash table
	indexStatusList = new int[HTSize];  //pointer to the array indicating the
	length = 0;    //number of items in the hash table

	for (int i = 0; i < HTSize; i++)
	{
		indexStatusList[i] = 0;
	}
}

template <class elemType>
hashT<elemType>::~hashT()
{
	delete HTable;
	delete indexStatusList;
}

int main() {

	
	State am;
	State be;
	State dep;

	am.setName("Washington");
	am.setCapital("Olympia");
	am.setArea(50);
	am.setOrderOfAdmission(39);
	am.setYearOfSubmission(1890);

	be.setName("Arkansas");
	be.setCapital("Little Rock");
	be.setArea(50);
	be.setOrderOfAdmission(39);
	be.setYearOfSubmission(1890);

	dep.setName("Mississippi");
	dep.setCapital("Jackson");
	dep.setArea(50);
	dep.setOrderOfAdmission(39);
	dep.setYearOfSubmission(1890);

	hashT<State> hTable(3);

	hTable.insert(hTable.hashFunc(am.getName()), am);
	hTable.insert(hTable.hashFunc(be.getName()), be);
	hTable.insert(hTable.hashFunc(dep.getName()), dep);

	hTable.print();

	system("pause");
	return 0;
}