#include "users.h"

User::	User(std::string& name, std::string& Login, std::string& psw)
		:_name(name), _login(Login), _psw(psw) {}
const std::string& User::getLogin() const
{
	return _login;
};
const std::string& User::getPsw() const
{
	return _psw;
};
const std::string& User::getName() const
{
	return _name;
}
void User::setPsw(const std::string& psw)
{
}
void User::setName(const std::string& name)
{
	_name = name;
};
void  User::setLogin(const std::string& login)
{
	_login = login;
};


