#pragma once
#include <iostream>
#include<string>
using namespace std;
class Player {

	string nickName;
	string password;
public:
	void CreateUserAcc(string nick, string pass);
	
	Player() :nickName("default"), password("default") {}
	Player(string nick, string pass) : nickName(nick), password(pass) {}
	Player(const Player& other) : nickName(other.nickName), password(other.password){}
	string GetNickName();
	string GetPassword();
	
	
};