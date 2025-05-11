#pragma once
#include<iostream>
#include"Election.h"

using namespace std;

class National_Election :public Election {
	
private:
	string Name_Of_Election;

public:
	National_Election();
	void setName_Of_Election(string);
	void startElection();
	void endElection();
	string getName_Of_Election();

};
