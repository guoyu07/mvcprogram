//---------------------------------------------------------------------------


#pragma hdrstop

#include "TLNetTraffic.h"
#include "TLRed.h"

//---------------------------------------------------------------------------

TLNetTraffic::TLNetTraffic()
{
	_state = new TLRed(this);
}

void TLNetTraffic::setState ( TLState* state )
{
	if (_state) {
		delete _state;
	}
	_state = state;
}

void TLNetTraffic::Handle ()
{
	_state->Handle();
}

TLNetTraffic::~TLNetTraffic()
{
	if (_state) {
		delete _state;
	}
}

#pragma package(smart_init)
