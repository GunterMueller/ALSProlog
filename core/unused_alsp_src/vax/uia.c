/*
 * uia.c		-- uia routines
 *	Copyright (c) 1987 Applied Logic Systems, Inc.
 *
 * Author: Kevin A. Buettner
 * Creation: 6/25/87
 * Revision History:
 *
 */


#include "config.h"
#include "types.h"
#include "mtypes.h"
#include "winter.h"
#include "parser.h"

cmp_sym_uia(sym,uia)
   long sym;
   long uia;
{
   return !strcmp(TOKNAME(sym>>4), ((char *) wm_heapbase) + (uia>>4) + 4);
}


cmp_uia_uia(uia1,uia2)
   long uia1, uia2;
{
   return !strcmp( ((char *) wm_heapbase) + (uia1>>4) + 4,
		   ((char *) wm_heapbase) + (uia2>>4) + 4 );
}

cmp_obj_str(obj,str)
   long obj;
   char *str;
{
   int tp;
   tp = obj&0xf;
   if (tp == MTP_SYM)
      return !strcmp(TOKNAME(obj>>4), str);
   else if (tp == MTP_UIA) 
      return !strcmp( ((char *) wm_heapbase) + (obj>>4) +4, str);
   else 
      return 0;
}
