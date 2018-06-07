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
	bool operator=(State &otherState) {

		if (this->name == otherState.getName()) {
			return true;
		}

		return false;
	}

};

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

class HashT {

};

int main() {

	StateData data;

	data.createSomeStates();

	data.printStates();

	system("pause");
	return 0;
}