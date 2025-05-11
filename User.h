#pragma once
#include<iostream>
#include<string>
using namespace std;

class User {
protected:
	string username;
	string password;
public:
	User(string,string);
	virtual void login() = 0;
	virtual ~User();
};
