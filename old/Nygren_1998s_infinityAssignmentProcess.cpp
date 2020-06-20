
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998s_infinityAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998s_infinityAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998s_infinityAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    s_infinity  = getVariableReference( "s_infinity" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    s_infinity->setValue( 1 * (1.00000/(1.00000+exp((V->getValue()+40.5000)/11.5000))) );

  }

 protected:

  Variable* s_infinity;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998s_infinityAssignmentProcess, Process );
