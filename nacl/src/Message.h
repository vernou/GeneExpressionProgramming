#ifndef MESSAGE_H
#define MESSAGE_H

#include "ppapi/cpp/var.h"

class Message
{
public:
	enum Type
	{
		INIT = 0,
		LOG = 'l',
		SETTING = 's',
		DATA = 'd',
        RUN = 'r',
		ERROR = 'e'
	};

public:
    Message();
	Message(const pp::Var& var_message);
	
	void SetType(char c);
	
public:
	Type type;
    std::string data;
};

#endif // MESSAGE_H
