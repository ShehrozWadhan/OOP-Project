#include<iostream>
#include<string>
#include<fstream>
#include"Administrator.h"
#include"Voter.h"
#include"Candidate.h"
using namespace std;






Administrator::Administrator(string na_me) :User(username, password)
{
	Admin_name = na_me;
	username = "Admin123";
	password = "Admin567@$#";
	cnd_Nat = NULL;
	cnd_Loc = NULL;
	vot_Nat = NULL;
	vot_Loc = NULL;
	count_Candidates_National = 0;
	count_Candidates_Local = 0;
	Voter_Count_National = 0;
	Voter_Count_Local = 0;
	Max_Cand_Nat = 0;
	Max_Cand_Loc = 0;
	ElectionFlag_National = false;
	ElectionFlag_Local = false;
}

int Administrator::getCount_Candidates_National() {
	return count_Candidates_National;
}

int Administrator::getCount_Candidates_Local() {
	return count_Candidates_Local;
}

int Administrator::getVoter_Count_National() {
	return Voter_Count_National;
}

int Administrator::getVoter_Count_Local() {
	return Voter_Count_Local;
}



void Administrator::login()
{
	string user, pass;
	cout << "\nEnter UserName : " << endl;
	cin >> user;
	cout << "\nEnter Password : " << endl;
	cin >> pass;
	if (username == user && password == pass)
	{
		cout << "\nCorrect Username And Password .. " << endl;
		bool admin_Flag = true;
		while (admin_Flag) {

			int choice_Admin;
			cout << "\n -------------------------------------ADMIN DASHBOARD------------------------------------------------------ " << endl;
			cout << endl << endl;
			cout << "\nCreate An Election(1) " << endl;
			cout << "Add A Candidate(2) " << endl;
			cout << "View Results(3) " << endl;
			cout << "All National Candidates Info(4) " << endl;
			cout << "All Local Candidates Info(5) " << endl;
			cout << "Created Elections (6) " << endl;
			cout << "Add A Voter(7) " << endl;
			cout << "Exit Admin Dashboard(8) " << endl;
			
			cin >> choice_Admin;

			if (choice_Admin == 1){
				createElection();
			}

			else if (choice_Admin == 2) {

				addCandidate();

			}


			else if (choice_Admin == 4) {
				AllCandidatesInfoNational();
			}

			else if (choice_Admin == 5) {
				AllCandidatesInfoLocal();
			}

			else if (choice_Admin == 6) {
				AllElectionsCreated();
			}

			else if (choice_Admin == 7) {
				addVoter();
			}

			else if (choice_Admin == 8) {
				cout << "\nExiting Admin Dashboard... " << endl;
				admin_Flag = false;
			}


		}
	}
	else {
		cout << "\nInvalid Username Or Password .. " << endl;
	}
}


void Administrator::createElection()
{

	bool flag = true;
	int choice;
	while (flag)
	{
		cout << "\nEnter 1 To Create A National Election.. " << endl;
		cout << "Enter 2 To Create A Local Election.. " << endl;
		cout << "Enter 3 To Exit This Window : " << endl;
		cin >> choice;
		if (choice == 1) {
			int no_Of_Cand_National;
			int no_Of_Vot_National;
			cout << "\nEnter The Number Of Candidates For National Election : " << endl;
			cin >> no_Of_Cand_National;
			cout << "\nEnter The Number Of Voters For National Election : " << endl;
			cin >> no_Of_Vot_National;
			cnd_Nat = new Candidate * [no_Of_Cand_National];
			vot_Nat = new Voter * [no_Of_Vot_National];
			ElectionFlag_National = true;
		}

		else if (choice == 2) {
			int no_Of_Cand_Local;
			int no_Of_Vot_Local;
			cout << "\nEnter The Number Of Candidates For Local Election : " << endl;
			cin >> no_Of_Cand_Local;
			cout << "\nEnter The Number Of Voters For Local Election : " << endl;
			cin >> no_Of_Vot_Local;
			cnd_Loc = new Candidate * [no_Of_Cand_Local];
			vot_Loc = new Voter * [no_Of_Vot_Local];
			ElectionFlag_Local = true;
		}

		else if (choice == 3) {
			cout << "\n Exiting This Window ... " << endl;
			flag = false;
		}


		else {
			cout << "Choose A Valid Option : " << endl;
		}




	}
}


void Administrator::addCandidate() {

	cout << "\nIn Which Election Do You Want To Add Candidate : " << endl;
	cout << "National Election(1)  " << endl;
	cout << "Local Eletion(2)  " << endl;

	int choice_Of_Elec;
	cin >> choice_Of_Elec;

	if (choice_Of_Elec == 1) {
		if (ElectionFlag_National == false) {
			cout << "\nElection Is Not Yet Created " << endl;
		}
		else {
			string name, party_aff;
			cout << "\nEnter Name Of Candidate : " << endl;
			cin.ignore();
			getline(cin, name);
			cout << "\nEnter Party Of Candidate : " << endl;
			getline(cin, party_aff);

			Candidate* newCandidate = new Candidate();
			newCandidate->setName(name);
			newCandidate->setPartyAffiliation(party_aff);
			newCandidate->setNoOfVotes(0);
			cnd_Nat[count_Candidates_National] = newCandidate;
			count_Candidates_National++;

			cout << "\n--------------Added Candidate Details-------------" << endl;
			cout << "Candidate Name : " << newCandidate->getName() << endl;
			cout << "Candidate Party_Affiliation : " << newCandidate->getParty_Affiliation() << endl;

			ofstream finout("CandidateInfo_NationalElection.txt", ios::app);
			if (finout.is_open())
			{
				finout << "Candidate Name : " << newCandidate->getName() << endl;
				finout << "Candidate Party_Affiliation : " << newCandidate->getParty_Affiliation() << endl;
				finout << "Candidate Votes " << newCandidate->getNo_Of_Votes() << endl;
				finout << "----------------------------------------------------------------------------------------" << endl;
				finout << endl << endl;
			}
			else {
				cout << "Unable To Open File " << endl;
			}
		}
	}

	else if(choice_Of_Elec==2)
	{
		if (ElectionFlag_Local == false) {
			cout << "\nElection Is Not Yet Created " << endl;
		}
		else {
			string name, party_aff;
			cout << "\nEnter Name Of Candidate : " << endl;
			cin.ignore();
			getline(cin, name);
			cout << "\nEnter Party Of Candidate : " << endl;
			getline(cin, party_aff);

			Candidate* newCandidate = new Candidate();

			newCandidate->setName(name);
			newCandidate->setPartyAffiliation(party_aff);
			newCandidate->setNoOfVotes(0);
			cnd_Loc[count_Candidates_Local] = newCandidate;
			count_Candidates_Local++;

			cout << "\n--------------Added Candidate Details-------------" << endl;
			cout << "Candidate Name : " << newCandidate->getName() << endl;
			cout << "Candidate Party_Affiliation : " << newCandidate->getParty_Affiliation() << endl;

			ofstream finout("CandidateInfo_LocalElection.txt", ios::app);
			if (finout.is_open())
			{
				finout << "Candidate Name : " << newCandidate->getName() << endl;
				finout << "Candidate Party_Affiliation : " << newCandidate->getParty_Affiliation() << endl;
				finout << "Candidate Votes " << newCandidate->getNo_Of_Votes() << endl;
				finout << "----------------------------------------------------------------------------------------" << endl;
				finout << endl << endl;
			}
			else {
				cout << "Unable To Open File " << endl;
			}
		}
	}
	else {
		cout << "\nSelect A Valid Option ... " << endl;
	}
}


void Administrator::AllCandidatesInfoNational() {
	if (count_Candidates_National == 0) {
		cout << "\nNo Information Of National Candidates Available ... " << endl;
	}
	else {
		for (int i = 0; i < count_Candidates_National; i++) {
			cout << "Candidate Name : " << cnd_Nat[i]->getName() << endl;
			cout << "Candidate Party : " << cnd_Nat[i]->getParty_Affiliation() << endl;
			cout << "Candidate Votes : " << cnd_Nat[i]->getNo_Of_Votes() << endl;

		}
	}
}

void Administrator::AllCandidatesInfoLocal () {
	if (count_Candidates_Local == 0) {
		cout << "\nNo Information Of Local Candidates Available ... " << endl;
	}
	else {
		for (int i = 0; i < count_Candidates_Local; i++) {
			cout << "Candidate Name : " << cnd_Loc[i]->getName() << endl;
			cout << "Candidate Party : " << cnd_Loc[i]->getParty_Affiliation() << endl;
			cout << "Candidate Votes : " << cnd_Loc[i]->getNo_Of_Votes() << endl;
		}
	}
	
}

void Administrator::AllElectionsCreated() {
	if (ElectionFlag_National == true && ElectionFlag_Local==true) {
		cout << "\nNational Election Available " << endl;
		cout << "Local Election Available " << endl;
	}
	else if (ElectionFlag_National == true && ElectionFlag_Local == false) {
		cout << "\nNational Election Available " << endl;
		cout << "Local Election Not Available " << endl;
	}

	else if (ElectionFlag_National == false && ElectionFlag_Local == true) {
		cout << "\nNational Election Not Available " << endl;
		cout << "Local Election Available " << endl;
	}

	else if (ElectionFlag_National == false && ElectionFlag_Local == false) {
		cout << "\nNational Election Not Available " << endl;
		cout << "Local Election Not Available " << endl;
	}
	
}

void Administrator::addVoter() {
	string Voter_Name,Voter_Username,Voter_Password;
	int Voter_Age;
	cout << "\nEnter Name Of Voter : " << endl;
	getline(cin, Voter_Name);
	cout << "\nEnter Username Of Voter : " << endl;
	getline(cin, Voter_Username);
	cout << "\nEnter Password Of Voter : " << endl;
	getline(cin, Voter_Password);
	cout << "\nEnter Age Of Voter : " << endl;
	cin >> Voter_Age;
	if (Voter_Age >= 18) {
		int choice_vot;
		cout << "\nIn Which Election Do You Want To Add This Voter ? " << endl;
		cout << "National(1) " << endl;
		cout << "Local(2) " << endl;

		cin >> choice_vot;
		if (choice_vot == 1) {
			if (ElectionFlag_National == false) {
				cout << "\nElection Is Not Yet Created " << endl;
			}
			else {
				Voter* newVoter = new Voter();
				newVoter->setName(Voter_Name);
				newVoter->setUsername(Voter_Username);
				newVoter->setPassword(Voter_Password);
				vot_Nat[Voter_Count_National] = newVoter;
				Voter_Count_National++;

				cout << "\n--------------Added Voter Details-------------" << endl;
				cout << "Voter Name : " << newVoter->getName() << endl;
				cout << "Voter Username : " << newVoter->getUsername() << endl;
				cout << "Voter Password : " << newVoter->getPassword() << endl;

				ofstream finout("VoterInfo_NationalElection.txt", ios::app);
				if (finout.is_open())
				{
					finout << "Voter Name : " << newVoter->getName() << endl;
					finout << "Voter Username : " << newVoter->getUsername() << endl;
					finout << "Voter Password : " << newVoter->getPassword() << endl;
					finout << "----------------------------------------------------------------------------------------" << endl;
					finout << endl << endl;
				}
				else {
					cout << "Unable To Open File " << endl;
				}

			}

		}
		else if (choice_vot == 2) {
			
			if (ElectionFlag_Local == false) {
				cout << "\nElection Is Not Yet Created " << endl;
			}
			else {
				Voter* newVoter = new Voter();
				newVoter->setName(Voter_Name);
				newVoter->setUsername(Voter_Username);
				newVoter->setPassword(Voter_Password);
				vot_Loc[Voter_Count_Local] = newVoter;
				Voter_Count_Local++;

				cout << "\n--------------Added Voter Details-------------" << endl;
				cout << "Voter Name : " << newVoter->getName() << endl;
				cout << "Voter Username : " << newVoter->getUsername() << endl;
				cout << "Voter Password : " << newVoter->getPassword() << endl;

				ofstream finout("VoterInfo_LocalElection.txt", ios::app);
				if (finout.is_open())
				{
					finout << "Voter Name : " << newVoter->getName() << endl;
					finout << "Voter Username : " << newVoter->getUsername() << endl;
					finout << "Voter Password : " << newVoter->getPassword() << endl;
					finout << "----------------------------------------------------------------------------------------" << endl;
					finout << endl << endl;
				}
				else {
					cout << "Unable To Open File " << endl;
				}
			}
			
		}
		
	}
	else {
		cout << "\nNot Eligible Because Age Is Under 18 ... " << endl;
	}

}





























































































































































































































































































































































































































































































