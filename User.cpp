#include<iostream>
#include<string>
#include"User.h"
using namespace std;

 User::User(string user_name="",string pass_word="") {
	 username = user_name;
	 password = pass_word;
}

 User::~User() {
 }