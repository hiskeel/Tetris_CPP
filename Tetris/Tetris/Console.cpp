#include"Console.h"
void Game::Gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
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
							
							if (_getch() == '1') { continue; }
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
				cout << "1. Try again\nElse Back" << endl;
				
				if (_getch() == '1') { continue; }
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
		for (int i = 0; i < user.size();i++) {
			if(nick == user[i].GetNickName()){}
		}
		cout << "Enter your password: "; cin >> pass;
		user.push_back(Player(nick, pass));
		SaveUserToFile();

		return true;
	}
	else { return false; }
}
int Game::MainMenuLegitUser() {
	system("cls");
	int choice = 1, run, x = 1;
	bool running = true;

	Gotoxy(2, 0); cout << "Your menu items:";
	Gotoxy(0, 1); cout << "->";

	while (running)
	{
		Gotoxy(2, 1);  cout << "1. Start the game";
		Gotoxy(2, 2);  cout << "2. Options";
		Gotoxy(2, 3);  cout << "3. Show Rules";
		Gotoxy(2, 4);  cout << "4. Check Highscores";
		Gotoxy(2, 5);  cout << "5. Change user";
		Gotoxy(2, 6);  cout << "0.Exit";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN)) //down button pressed
		{
			Gotoxy(0, x); cout << "  ";
			x < 6 ? x++ : x = 1;
			Gotoxy(0, x); cout << "->";
			choice < 5 ? choice++ : choice = 0;
			continue;

		}

		if (GetAsyncKeyState(VK_UP)) //up button pressed
		{
			Gotoxy(0, x); cout << "  ";
			x > 1 ? x-- : x = 6;
			Gotoxy(0, x); cout << "->";
			choice > 0 ? choice-- : choice = 5;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed
			return choice;
		}
	}
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
	Matrix matrix;
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
						
						matrix.ShowBoard();
						matrix.DrawShape(matrix.InitShape());

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


