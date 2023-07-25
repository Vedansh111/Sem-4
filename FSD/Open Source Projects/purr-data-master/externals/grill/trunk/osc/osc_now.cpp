/* 
OSC - OpenSoundControl networking objects

Copyright (c)2006-2007 Thomas Grill (gr@grrrr.org)
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "license.txt," in this distribution.  

$LastChangedRevision: 1771 $
$LastChangedDate: 2007-10-18 07:45:04 -0400 (Thu, 18 Oct 2007) $
$LastChangedBy: thomas $
*/

#include "osc.h"

namespace OSC {

#undef FLEXT_ATTRIBUTES
#define FLEXT_ATTRIBUTES 0

class Now
    : public flext_base
{
    FLEXT_HEADER_S(Now,flext_base,Setup)

public:
    Now()
    {
        AddInAnything();
        AddOutList();
    }

    void m_bang()
    {
        t_atom at[2];
        SetTimetag(at);
        ToOutList(0,2,at);
    }

protected:
    FLEXT_CALLBACK(m_bang)

    static void Setup(t_classid c)
    {
        FLEXT_CADDMETHOD(c,0,m_bang);
    }
};

FLEXT_LIB("osc.now, osc",Now)

} // namespace
