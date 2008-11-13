#ifndef _HPTS_SignalsInterface_H
#define _HPTS_SignalsInterface_H

#include <Presentation.h>

namespace HPTS
{
  /** \brief Interface de gestion des signaux

  Cette classe abstraite fourni une interface pour les objets pouvant recevoir et
  g�rer des signaux de type kill/suspend/resume
  \sa HPTS::StateMachineController
  \sa HPTS::StateMachine
  \sa HPTS::State
   */
  class SignalsInterface
  {
    /** \brief M�thode de r�action au signal kill */
    Public virtual void kill()=0 ;
    
    /** \brief M�thode de r�action au signal suspend */
    Public virtual void suspend()=0 ;

    /** \brief M�thode de r�action au signal resume */
    Public virtual void resume()=0 ;
  } ;

} ;

#endif
