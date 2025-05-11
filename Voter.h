#pragma once
#include<iostream>
#include<string>
#include"User.h"
#include"Administrator.h"


class Voter:public User{
private:
	string name;
	
	
public:
	Voter();
	void login();
	void setUsername(string);
	void setPassword(string);
	void setName(string);
	string getUsername();
	string getPassword();
	string getName();
	//void viewElections();
	//void castVote();
	//void checkVoteStatus();
	// ~Voter();
};