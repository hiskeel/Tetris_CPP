#include"User.h"



void Player::CreateUserAcc(string nick, string pass) {
	nickName = nick;
	password = pass;
	
}
string Player::GetNickName() {
	return nickName;
}
string Player::GetPassword() {
	return password;
}




