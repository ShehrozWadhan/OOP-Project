#include<iostream>
#include<string>
#include "Candidate.h"

using namespace std;



Candidate::Candidate() {
	name = "";
	party_Affiliation = "";
	no_Of_Votes = 0;
}

string Candidate::getName(){
	return name;
}

string Candidate::getParty_Affiliation(){
	return party_Affiliation;
}

int Candidate::getNo_Of_Votes() {
	return no_Of_Votes;
}

void Candidate::setName(string na){
	name = na;
}

void Candidate::setPartyAffiliation(string paf) {
	party_Affiliation = paf;
}

void Candidate::setNoOfVotes(int i)
{
	i = 0;
}

void Candidate::getCandidateinfo()
{
	cout << "Name Of Candidate : " << getName() << endl;
	cout << "Party Affiliation Of Candidate : " << getParty_Affiliation() << endl;
	cout << "No. Of Votes Of Candidate : " << getNo_Of_Votes() << endl;
}




