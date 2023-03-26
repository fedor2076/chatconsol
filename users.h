#pragma once
#include <string>
class Users
{
public:
	Users(std::string& name, std::string& nick, std::string& psw);
		
	std::string  getNick();
	std::string  getPsw();
	void  setNick();
	void  setPsw();

private:

	std::string _name;
	std::string _nick;
	std::string _psw;


};
