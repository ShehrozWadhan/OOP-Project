#pragma once
#include<iostream>
#include<string>
#include"Candidate.h"
#include"Voter.h"
#include"User.h"
using namespace std;

class Administrator : public User {
private:
	string Admin_name;
	Candidate** cnd_Nat;
	Candidate** cnd_Loc;
	Voter** vot_Nat;
	Voter** vot_Loc;
	int count_Candidates_National, count_Candidates_Local;
	int Max_Cand_Nat, Max_Cand_Loc;
	int Voter_Count_National, Voter_Count_Local;
	bool ElectionFlag_National;
	bool ElectionFlag_Local;
public:
	Administrator(string);
	void login();
	void createElection();
	void addCandidate();
	void addVoter();
	void AllCandidatesInfoNational();
	void AllCandidatesInfoLocal();
	void AllElectionsCreated();
	int getCount_Candidates_National();
	int getCount_Candidates_Local();
	int getVoter_Count_National();
	int getVoter_Count_Local();
	//void viewResults();
	//~Administrator();
};