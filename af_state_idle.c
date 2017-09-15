#include "af.h"

int 
af_state_idle(int messageType, EC_UTILS* utils, EQX_MSG *emsg, AF_INSTANCE *instance, char* err)
{	
	SFLOG_DEBUG("In state idle================");
	SFLOG_DEBUG("type= %s",emsg->raw[0].type);
	SFLOG_DEBUG("type= %d",messageType);
	if(messageType==MY_AF_EVENT_CLIENT){
		instance->command = MY_AF_SEND_DB;
		(void) ec_log_write (utils, "LOGNAME", "Any word");

		strcpy(emsg->diag, "in state idle");
		
		return MY_AF_STATE_W_DB;
	}
	else if (messageType==MY_AF_EVENT_DB2){
		SFLOG_DEBUG("==================================Method2==============================================");
		instance->command = MY_AF_SEND_DB2;
		//return MY_AF_STATE_IDLE;
	}
	
	return MY_AF_STATE_IDLE;
}

