#pragma once
#include <iostream>
#include<conio.h>
#include <windows.h>
#include"User.h"
#include"Shapes.h"
#include"Menu.h"
#include<vector>
#include<string>
#include <conio.h>
#include <fstream>

using namespace std;


class Game {
	
	vector<Player> user;
	vector<string> giftCodes= { "Kelvin", "LogicPower", "CPP_OOP","TestCode" };
   
	bool CheckGiftCode(string userCode);
	int LaunchMenu();
	int MainMenuLegitUser();
	int MainMenuPirateUser();
	bool RegMenu(string nick, string pass);
	void SaveUserToFile();
	void LoadUsersFromFile();
	bool LoginMenu(string nick,string pass);
	void GameStart();
	void CreateAcc();

public:
	string SetGiftCode();
	void GameUserStart();
	
};

