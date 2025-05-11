#pragma once
#include<iostream>
#include"Administrator.h"
using namespace std;

class Election {
protected:
	Administrator* Adminptr;
	bool Start_End_Election_Flag_National;
	bool Start_End_Election_Flag_Local;
	int Choice_Start_End_Election;

public:
	Election();
	virtual void startElection()=0;
	virtual void endElection()=0;
};