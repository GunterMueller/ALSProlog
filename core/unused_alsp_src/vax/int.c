/*
 *
 * int.c		-- interrupt helper functions for the Sun
 *	Copyright (c) 1989 Applied Logic Systems, Inc.
 *
 *
 * Author: Kevin A. Buettner
 * Creation: 5/24/89
 * Revision History:
 *
 */

#include "config.h"
#include "types.h"
#include "mtypes.h"
#include "wintcode.h"
#include "parser.h"


PWord int_get_goal_tokid(codeaddr)
    Code *codeaddr;	/* should point at the bra in the overflow entry */
{
    ntbl_entry *ent;

    /*
     * codeaddr-6 will put us at the overflow field.  We need to back up from
     * there in order to get to the name entry
     */

    ent = (ntbl_entry *) (((char *) (codeaddr-6)) - 
			      (int) ((ntbl_entry *) 0)->overflow);
    
    return (MMK_FUNCTOR(MFUNCTOR_TOKID(ent->tokid_arity),ent->nargs));
    
}


PWord int_get_module(codeaddr)
    Code *codeaddr;	/* should point at the bra in the overflow entry */
{
    ntbl_entry *ent;

    ent = (ntbl_entry *) (((char *) (codeaddr-6)) - 
			      (int) ((ntbl_entry *) 0)->overflow);
    
    return (MMK_SYM(ent->modid));
}
