//---------------------------------------------------------------------------


#pragma hdrstop

#include "TLGreen.h"
#include "TLYellow.h"

//---------------------------------------------------------------------------
TLGreen::TLGreen(TLNetTraffic* context): _context(context) {};

void TLGreen::Handle()
{
	printf("Green Light\n");
	_context->setState( new TLYellow(_context) );
}
TLGreen::~TLGreen() {
	if(_context) {
		delete _context;
	}
};
#pragma package(smart_init)
