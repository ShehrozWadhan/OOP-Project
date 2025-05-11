#include<iostream>
#include<string>
#include"Voter.h"

Voter::Voter() :User(username, password) {
	name = "";
	username = "";
	password = "";
}

void Voter::setUsername(string user_name) {
	username = user_name;
}

void Voter::setPassword(string pass_word) {
	password = pass_word;
}

void Voter::setName(string na_me) {
	name = na_me;
}

string Voter::getUsername(){
	return username;
}

string Voter:: getPassword(){
	return password;
}

string Voter::getName() {
	return name;
}

void Voter::login()
{
	string vot_nam, vot_username, vot_pass;
	cout << "\nEnter Your Name : " << endl;
	getline(cin, vot_nam);
	cout << "\nEnter Your Username : " << endl;
	getline(cin, vot_username);
	cout << "\nEnter Your Password : " << endl;
	getline(cin, vot_pass);


	cout << "\nSelect Election Type Please ... " << endl;
	cout << "1. National " << endl;
	cout << "2. Local " << endl;
	int choiceOfElectionType;
	if (choiceOfElectionType == 1) {
		//for (int i = 0; i < Adminptr->getVoter_Count_National(); i++) {
			
		//}
	}

	else {
		cout << "\nIncorrect Details ... " << endl;
	}

}
