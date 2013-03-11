#ifndef __CRYPHOUS_SPHERE_BOUNDARY_SOLVER_H__
#define __CRYPHOUS_SPHERE__BOUNDARY_SOLVER_H__

#include "../CryphousGeometry/Vector3d.h"
#include "../CryphousGeometry/Sphere.h"
#include "PhysicsObject.h"
#include "ParticlePair.h"
#include "SPHPairSolver.h"
#include "SimulationSetting.h"

#include <vector>

namespace Cryphous{
	namespace Physics{

class SphereBoundarySolver
{
public:

	SphereBoundarySolver(PhysicsObject* object, const SimulationSetting& setting)
		: object( object),
		virtualParticle( object->getParticleFactory()->getVirtualParticle()),
		setting( setting)
	{}

	~SphereBoundarySolver(void){};

	//void calculateDensity(const Geometry::Sphere& box);

	void calculateForce(const Geometry::Sphere& box);

private:

	void calculateDensity(Particle* particle, const Geometry::Vector3d boundaryPoint);

private:
	PhysicsObject* object;
	Particle* virtualParticle;
	const SimulationSetting& setting;
};

	}
}

#endif