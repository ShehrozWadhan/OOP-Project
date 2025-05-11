#include<iostream>
#include"Election.h"
#include"National_Election.h"
using namespace std;


National_Election::National_Election() {
	Name_Of_Election = "";
}

string National_Election::getName_Of_Election() {
	return Name_Of_Election;
}

void National_Election::setName_Of_Election(string nam) {
	Name_Of_Election = nam;
}

void National_Election::startElection() {
	Start_End_Election_Flag_National = true;
	cout << "\nNational Election Started ... " << endl;
}

void National_Election::endElection() {
	Start_End_Election_Flag_Local = false;
	cout << "\nNational Election Ended ... " << endl;
}