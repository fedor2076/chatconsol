#pragma once
#include "users.h"
class Message
{
public:
	Message(std::string& from, std::string& to, std::string& text) {};

	const std::string& getFrom() const;
	const std::string& getTo() const;
	const std::string& getText() const;
	void setFrom();
	void setTo();
	void setText();

private:
	std::string _text;
	std::string _from;
	std::string _to;
};