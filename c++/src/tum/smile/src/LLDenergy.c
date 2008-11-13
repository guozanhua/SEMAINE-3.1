/*******************************************************************************
 * feaTUM, fast, efficient audio feature extractor by TUM
 * Copyright (C) 2008  Florian Eyben, Martin Woellmer
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *******************************************************************************/
 
 /*  IMPLEMENTATION of the feature extractor module LLDenergy
     See the corresponding header file (.h) for documentation!  */

#define MODULE "LLDenergy"
 
 // this file contains the function definitions and the private class data

#include <stdio.h>
#include <stdlib.h>
#include "featum_common.h"
#include "featum_util.h"       //( optional )
#include "feature-memory.h"
//#include "LLDenergy.h"
#include "LLDs.h"

#undef FUNCTION     // use undef only if you define it below for every function


// default constructor 
pLLDenergy LLDenergy_create( pLLDenergy obj )
#define FUNCTION "LLDenergy_create"
{_FUNCTION_ENTER_
  _FUNCTION_RETURN_( NULL );
}
#undef FUNCTION 


// custom configuration of extractor parameters
/*  this is only a template function:
int LLDenergy_configure( pLLDenergy obj )
#define FUNCTION "LLDenergy_create"
{_FUNCTION_ENTER_
  if (obj != NULL) {
     _FUNCTION_RETURN_( 1 );
  }
  _FUNCTION_RETURN_( 0 );
}
#undef FUNCTION 
*/


// setup names in feature memory object
/*
int LLDenergy_setupFtmem( int level, pFeatureMemory mem )
#define FUNCTION "LLDenergy_setupNames"
{_FUNCTION_ENTER_
  int ret;
  ret = featureMemory_setupElement( mem, level, FT_LLD_ENERGY, FT_LLD_ENERGY_nVal, (char **)&lld_energy_ftMem_names );
  _FUNCTION_RETURN_(ret);
}
#undef FUNCTION 
*/  

//int featureMemory_flushToFtMem( pFeatureMemory mem, int level, int el, int nVal )

// flushToMem: copy final data from ftex to feature memory element array
int LLDenergy_flushToFtMem( int level, pFeatureMemory mem, pLLDex lldex )
#define FUNCTION "LLDenergy_flushToFtMem"
{_FUNCTION_ENTER_
 
  if (lldex == NULL)  _FUNCTION_RETURN_(0);
  #ifdef COMPILE_CHECKS_LOOPS
  if (level >= lldex->nIDs) _FUNCTION_RETURN_(0);
  if (lldex->current[level] == NULL) _FUNCTION_RETURN_(0);
  #endif
  if (lldex->current[level]->energy == NULL) _FUNCTION_RETURN_(0);
  if (lldex->current[level]->energy->flush_status == LLDEX_FLUSHED) _FUNCTION_RETURN_(2);
  
  FLOAT_TYPE_FTMEM *values 
    = featureMemory_getValuesForWrite_seq( mem, level, ft_lld_energy, 
                                           FT_LLD_ENERGY_nVal, 0, 
                                           lldex->current[level]->timestamp );
   //(TODO: assign timestamps...??   should be done in featureMemory_getValuesWrite...)
   // -> ok (at least here...)

  if (values != NULL) {
   values[0] 
      = (FLOAT_TYPE_FTMEM)lldex->current[level]->energy->rmsEnergy; 
   values[1] 
      = (FLOAT_TYPE_FTMEM)lldex->current[level]->energy->logEnergy; 

   lldex->current[level]->energy->flush_status = LLDEX_FLUSHED;

    _FUNCTION_RETURN_(1);
  }
  _FUNCTION_RETURN_(0);
}
#undef FUNCTION


// extractor:  do the main extraction , this function is called once per frame
// if data from multiple past frames is required, it is accessible via the lldex object
int LLDenergy_extractor( pLLDenergy obj, pLLDex lldex, int level )
#define FUNCTION "LLDenergy_extractor"
{_FUNCTION_ENTER_
  if (lldex != NULL) {
    #ifdef COMPILE_CHECKS_LOOPS
    if (level >= lldex->nIDs) _FUNCTION_RETURN_(0);
    if (level < 0) _FUNCTION_RETURN_(0);
    if (lldex->current[level] == NULL) _FUNCTION_RETURN_(0);
    #endif
    if (lldex->current[level]->energy == NULL) {
       LLDenergy_createLLDex( lldex->current[level] );                               
    }
    lldex->current[level]->energy->rmsEnergy = pcmProcess_energy( lldex->current[level]->pcm );
    if (lldex->current[level]->energy->rmsEnergy < 0.00001) {
      lldex->current[level]->energy->logEnergy = 2.0*log(0.00001);
    } else {
      lldex->current[level]->energy->logEnergy = 2.0*log(lldex->current[level]->energy->rmsEnergy);
    }
    #ifdef DATASAVE_ENERGY
    // save cepstrum data for visualisation and debugging purposes:
    if (!datasave_appendvec_d("energy.dat",&(lldex->current[level]->energy->rmsEnergy),1)) { FEATUM_ERROR_FATAL(0,"error writing to cepstrum.dat"); }
    #endif
    
  }

  _FUNCTION_RETURN_(1);
}
#undef FUNCTION


// create LLDex object for this extractor
int LLDenergy_createLLDex( pLLDexElement obj )
#define FUNCTION "LLDenergy_createLLDex"
{_FUNCTION_ENTER_
  pLLDexEnergy p = NULL;
  int ret = 0;
  
  if (obj != NULL) {
    if (obj->energy != NULL) LLDenergy_freeLLDex(obj);          
    p = (pLLDexEnergy) calloc(1,sizeof(sLLDexEnergy));
    if (p != NULL) {
      p->freeLLDex = &LLDenergy_freeLLDex;
      ret = 1;
    }
    obj->energy = p;
  }
  _FUNCTION_RETURN_(ret);
}
#undef FUNCTION


// free the lldex object l and return NULL
int LLDenergy_freeLLDex( pLLDexElement obj )
#define FUNCTION "LLDenergy_freeLLDex"
{_FUNCTION_ENTER_

  if (obj != NULL) {
    if (obj->energy != NULL) {
      free(obj->energy);  obj->energy = NULL;
      _FUNCTION_RETURN_(1);
    }   
  }
  _FUNCTION_RETURN_(0);
}
#undef FUNCTION


// destroy the LLDenergy feature extractor object
pLLDenergy LLDenergy_destroy( pLLDenergy obj )
#define FUNCTION "LLDenergy_destroy"
{_FUNCTION_ENTER_
  _FUNCTION_RETURN_(NULL);
}
#undef FUNCTION


