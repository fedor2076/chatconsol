#include "user.h"

User::	User(const std::string& name,const std::string& Login, const std::string& psw)
		:_name(name), _login(Login), _psw(psw) {}
const std::string& User::getName() const
{
	return _name;
}
const std::string& User::getLogin() const
{
	return _login;
};
const std::string& User::getPsw() const
{
	return _psw;
};
void User::setName(const std::string& name)
{
	_name = name;
};
void  User::setLogin(const std::string& login)
{
	_login = login;
};
void User::setPsw(const std::string& psw)
{
	_psw = psw;
};


