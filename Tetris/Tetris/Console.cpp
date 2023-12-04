#include"Console.h"

bool Game::CheckGiftCode(string userCode) {
	bool check = false;
	for (auto i : giftCodes) {
		if (i == userCode)check = true;
	}
	if (check == true)return true;
	else { return false; }
}
string Game::SetGiftCode() {
	string code;
	cout << "Enter Code:";
	cin >> code;
	return code;
}
int Game::LaunchMenu() {
	int choice;
	cout << "Welcome to the game\n1. Login to the game\n2. Create new user\n0.Exit" << endl;
	cin >> choice;
	return choice;
}
//int Game::LoginMenu() {
//
//}
bool Game::LoginMenu(string nick, string pass) {
	system("cls");
	bool check = false;
	bool checkPass = false;
	bool confirm = false;
	while (!confirm)
	{
		cout << "Enter your nickname(Enter 0 to go back): "; cin >> nick;
		if (nick == "0")return false;
	
		else
		{
			for (int i = 0; i < user.size();i++) {

				if (user[i].GetNickName() == nick) {
					check = true;
					while (!checkPass)
					{
						cout << "Enter your password: "; cin >> pass;
						if (user[i].GetPassword() == pass) {

							return true;
						}
						else {
							cout << "Wrong password. \n1. Try again\n2. Change nickname" << endl;
							cin >> pass;
							if (pass == "1") { continue; }
							else {
								checkPass = true;
							}
						}
					}
				}
			}
			if (check == false) {
				system("cls");
				cout << "Here is no user with nickname: " << nick << "!" << endl;
				cout << "1. Try again\n2. Back" << endl;
				cin >> nick;
				if (nick == "1") { continue; }
				else {
					return false;

				}
			}
		}
	}
	
	
}
void Game::SaveUserToFile() {

	ofstream out("Users.txt");
	if (!out.is_open()) {
		cerr << "Error opening file for reading.\n";
		return;
	}else
	{
		for (int i = 0; i < user.size();i++) {
			out << user[i].GetNickName() << " " << user[i].GetPassword() << endl;
		}
		out.close();
	}

}

void Game::LoadUsersFromFile() {
	ifstream in("Users.txt");
	if (!in.is_open()) {
		cerr << "Error opening file for reading.\n";
		return;
	}
	user.clear();
	
	string nick, pass;
	while (in >> nick>> pass) {
		user.push_back(Player(nick, pass));
	}
	in.close();

}
bool Game::RegMenu(string nick, string pass) {
	system("cls");
	string GiftCode;
	cout << "Enter your gift code:";cin >> GiftCode;
	if (CheckGiftCode(GiftCode)) {
		
		cout << "Enter your nickname: "; cin >> nick;
		cout << "Enter your password: "; cin >> pass;
		user.push_back(Player(nick, pass));
		SaveUserToFile();

		return true;
	}
	else { return false; }
}
int Game::MainMenuLegitUser() {
	system("cls");
	int choice;
	cout << "1. Start the game\n2. Options\n3. Show Rules\n4. Check Highscores\n5. Change user\n0.Exit" << endl;
	cin >> choice;
	return choice;
}
int Game::MainMenuPirateUser() {
	system("cls");
	int choice;
	cout << "You Entered worng code but you can:\n1. Start beta game\n2. Try login again\n0.Exit" << endl;
	cin >> choice;
	return choice;
}
void Game::GameStart() {
	string nick;
	string pass;
	bool exitGame = false;
	bool back = false;
	LoadUsersFromFile();
	int choice = 0;
	while (!exitGame) {
		choice = LaunchMenu();
		switch (choice) {
		case 1:
			if (LoginMenu(nick, pass)) {
				back = false;
				while (!back)
				{
					switch (MainMenuLegitUser()) {
					case 1:
						system("cls");
						cout << "Game Started" << endl;
						system("pause");
						break;
					case 2:
						system("cls");
						cout << "Options menu:" << endl;
						system("pause");
						break;
					case 3:
						system("cls");
						cout << "You have to move, rotate falling shapes to fill the lines and get points.\nIf shape will touch top of board you are going to lose ." << endl;
						system("pause");
						break;
					case 4:
						system("cls");
						cout << "Highscores" << endl;
						system("pause");
						break;
					case 5:
						back = true;
						break;
					case 0:
						cout << "Bye!";
						back = true;
						exitGame = true;
						break;
					default:break;
					}
				}
			}
			
			break;
		case 2:
			
			if (RegMenu(nick, pass)) {
				back = false;
				while(!back)
				{
					switch (MainMenuLegitUser()) {
					case 1:
						system("cls");
						cout << "Game Started" << endl;
						system("pause");
						break;
					case 2:
						system("cls");
						cout << "Options menu:" << endl;
						system("pause");
						break;
					case 3:
						system("cls");
						cout << "You have to move, rotate falling shapes to fill the lines and get points.\nIf shape will touch top of board you are going to lose ." << endl;
						system("pause");
						break;
					case 4:
						system("cls");
						cout << "Highscores" << endl;
						system("pause");
						break;
					case 5:
						 back = true;
						break;
					case 0:
						cout << "Bye!";
						 back = true;
						exitGame = true;
						break;
					default:break;
					}
				}
			}
			else {
				switch (MainMenuPirateUser()) {
				case 1:system("cls");
					cout << "Demo started" << endl;
					system("pause");
					break;
				case 2:break;
				default:break;
				}
			}
			break;
		case 0:
			cout << "Bye" << endl;
			exitGame = true;
			break;
		default: cout << "Wrong menu point!" << endl;
			system("pause");
			break;
		}
	}
}
void Game::GameUserStart() {
	GameStart();
}
