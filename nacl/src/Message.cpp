#include "Message.h"

Message::Message():type(INIT)
{
    
}

Message::Message(const pp::Var& var_message):type(INIT)
{
        // Ignore the message if it is not a string.
        if (!var_message.is_string())
            return;

        // Get the string message
        std::string message = var_message.AsString();
		// The fist octet is type of message
		SetType(message[0]);
		// Next octets are data of message
		if (message.size()>1)
			data = &message.c_str()[1];
}

void Message::SetType(char c)
{
	if(c>='A' && c<='Z')
		c -= 'A'-'a';
	
	switch((int)c)
	{
		case LOG:
			type = LOG;
			break;
		case SETTING:
			type = SETTING;
			break;
		case DATA:
			type = DATA;
			break;
        case RUN:
            type = RUN;
            break;
		default:
			type = ERROR;
	}
}