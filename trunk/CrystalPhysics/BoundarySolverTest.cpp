#define BOOST_TEST_NO_LIB
#include <boost/test/unit_test.hpp>

#include "../CrystalPhysics/BoundarySolver.h"

#include "../CrystalPhysics/ParticleFactory.h"
#include "../CrystalPhysics/Particle.h"
#include "../CrystalPhysics/ParticleConditions.h"
#include "../CrystalPhysics/PhysicsObject.h"
#include "../CrystalPhysics/PhysicsObjectFactory.h"

#include "../CrystalGeom/Box.h"
#include "../CrystalGeom/Vector3d.h"

using namespace Crystal::Geom;
using namespace Crystal::Physics;

BOOST_AUTO_TEST_CASE(BOUNDARY_SOLVER_TEST)
{
	PhysicsObjectFactory factory;
	SimulationSetting setting;
	setting.particleDiameter = 1.0;
	std::vector<Vector3d> points;
	points.push_back( Vector3d( 0.0, 0.0, 0.0 ));
	points.push_back( Vector3d( 1.0, 0.0, 0.0 ));
	PhysicsObjectCondition condition( points, 1000.0, 1.0, 0.0, PhysicsObjectCondition::Fluid );
	PhysicsObject* object = factory.createPhysicsObject( condition, setting );
	Particle* virtualParticle = object->getParticleFactory()->getVirtualParticle();
	BoundarySolver solver( object, setting );
	solver.calculateDensity( Box() );
}