/* 
OSC - OpenSoundControl networking objects

Copyright (c)2006 Thomas Grill (gr@grrrr.org)
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "license.txt," in this distribution.  

$LastChangedRevision: 1771 $
$LastChangedDate: 2007-10-18 07:45:04 -0400 (Thu, 18 Oct 2007) $
$LastChangedBy: thomas $
*/

#ifndef __OSC_H
#define __OSC_H

#define FLEXT_ATTRIBUTES 1

#include <flext.h>

//send
#include "osc/OscOutboundPacketStream.h"
//receive
#include "osc/OscReceivedElements.h"
#include "osc/OscPacketListener.h"
// protocol
#include "ip/UdpSocket.h"

#include <stdexcept>
#include <string>


namespace OSC {

typedef const t_symbol *Symbol;

static const osc::uint64 _2_32 = (osc::uint64)1<<32;

static osc::uint64 GetTimetag(double time = flext::GetOSTime())
{
    return (osc::uint64)(time*_2_32);
}

static void SetTimetag(t_atom *at,osc::uint64 time = GetTimetag())
{
    flext::SetFloat(at[0],float(time>>32));
    flext::SetFloat(at[1],float(time&(_2_32-1))/_2_32);
}

} // namespace

#endif
