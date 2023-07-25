/* 
OSC - OpenSoundControl networking objects

Copyright (c)2006-2007 Thomas Grill (gr@grrrr.org)
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "license.txt," in this distribution.  

$LastChangedRevision: 1776 $
$LastChangedDate: 2007-12-31 10:17:00 -0500 (Mon, 31 Dec 2007) $
$LastChangedBy: thomas $
*/

#include "osc.h"

#define OSC_VERSION "0.0.7"

namespace OSC {

static void main()
{
	flext::post("----------------------------------------");
	flext::post("osc - OpenSoundControl objects");
    flext::post("version " OSC_VERSION " (c)2006-2007 Thomas Grill");
#ifdef FLEXT_DEBUG
    flext::post("");
    flext::post("DEBUG BUILD - " __DATE__ " " __TIME__);
#endif
	flext::post("----------------------------------------");

	// call the objects' setup routines
    FLEXT_SETUP(Now);
    FLEXT_SETUP(UdpRecv);
    FLEXT_SETUP(UdpSend);
    FLEXT_SETUP(Route);
}

} // namespace

// setup the library
FLEXT_LIB_SETUP(osc,OSC::main)
