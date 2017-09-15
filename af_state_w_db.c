#include "af.h"

int 
af_state_w_db(int messageType, EC_UTILS* utils, EQX_MSG *emsg, AF_INSTANCE *instance, char* err)
{	
	if(messageType==MY_AF_EVENT_DB){
		SFLOG_DEBUG("In state wait db");
		instance->command = MY_AF_SEND_IDLE;
		(void) ec_log_write (utils, "LOGNAME", "Any word");

		strcpy(emsg->diag, "in state wait db");
		
		return MY_AF_STATE_IDLE;
	}
	return MY_AF_STATE_IDLE;
}
