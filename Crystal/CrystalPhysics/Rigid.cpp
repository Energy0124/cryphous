
#include "Rigid.h"
#include "Particle.h"
#include "PhysicalTimeIntegratorBase.h"
#include "EnforcerBase.h"

using namespace Crystal::Physics;

Rigid::Rigid( const int id, const double density, const double gasConstant, const double viscosityCoefficient, 
			 ParticleFactory* particleFactory,
			 PhysicalTimeIntegratorBase* physicalTimeIntegratorBase,
			 EnforcerBase* enforcerBase ) :
PhysicsObject( id , density, gasConstant, viscosityCoefficient, particleFactory, physicalTimeIntegratorBase, enforcerBase)
{
}

Rigid::~Rigid()
{
}