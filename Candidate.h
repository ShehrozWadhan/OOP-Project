#pragma once
#include<iostream>
#include<string>
using namespace std;

class Candidate {
private:
	string name;
	string party_Affiliation;
	int no_Of_Votes;
public:
	Candidate();
	string getName();
	string getParty_Affiliation();
	int getNo_Of_Votes();
	void setName(string);
	void setPartyAffiliation(string);
	void setNoOfVotes(int);
	//void incrementVotes();
	void getCandidateinfo();
	//void getVoteCount();
};