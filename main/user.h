#pragma once
#include <string>
class User
{
public:
	User(const std::string& name, const std::string& login, const std::string& psw);
	
	const std::string& getName() const;
	const std::string&  getLogin()  const;
	const std::string& getPsw() const;
	
	void  setName(const std::string& name);
	void  setLogin(const std::string& login);
	void  setPsw(const std::string& psw);
	

private:

	std::string _name;
	std::string _login;
	std::string _psw;


};
