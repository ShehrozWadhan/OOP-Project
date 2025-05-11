#include<iostream>
#include<string>
#include"User.h"
#include"Administrator.h"
#include"Voter.h"
#include"Election.h"
#include"National_Election.h"
using namespace std;

int main()
{
	Administrator Admin("Junaid");
	Candidate C1();
	Voter VOter;
	

	int choice;
	bool flag = true;
	while (flag) {
	
		cout << "Enter As An Admin(1) " << endl;
		cout << "Enter As A Voter(2) " << endl;
		cout << "Exit The Program(3) " << endl;
		cin >> choice;
		

		if (choice == 1){
			Admin.login();

		}

		else if (choice == 2) {
			VOter.login();
		}

		else if (choice == 3){
			cout << "\nEnding Program... " << endl;
			flag = false;
		}
	}
}