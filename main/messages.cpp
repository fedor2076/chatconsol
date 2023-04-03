#include "messages.h"

const std::string& Message::getFrom() const
{
	return _from;
}

const std::string& Message::getTo() const
{
	return _to;
}

const std::string& Message::getText() const
{
	return _text;
}

void Message::setFrom()
{
}

void setFrom();
void setTo();
void setText();

