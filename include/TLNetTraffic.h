//---------------------------------------------------------------------------

#ifndef TLNetTrafficH
#define TLNetTrafficH
#include "TLState.h"
#include <memory>
#include <iostream>
//---------------------------------------------------------------------------
class TLNetTraffic
{
	private:
		TLState* _state;
		//	std::shared_ptr<TLState> _state;
	public:
		TLNetTraffic();
		~TLNetTraffic();
		void setState ( TLState* state );
		void Handle();
};
#endif
