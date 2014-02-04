#include "Simulation.h"

#include "../CryphousGeometry/Box.h"
#include "../CryphousGeometry/Vector3d.h"
#include "../CryphousGeometry/Vector3d.h"

#include "SPHSolver.h"
#include "PhysicsObject.h"

#include "PhysicsObjectFactory.h"
#include "Particle.h"
#include "SimulationSetting.h"
#include "Profiler.h"

#include <omp.h>

#include <cassert>
#include <cmath>

using namespace Cryphous::Geometry;
using namespace Cryphous::Physics;

void Simulation::simulate(PhysicsObjectFactory* factory, const SimulationSetting& setting)
{
	Profiler::get()->start("Simulation->");

	PhysicsObjectVector& physicsObjects = factory->getPhysicsObjects();

	Profiler::get()->start(" Sim->sorting");	
	SearchParticleFactory spFactory( factory->getParticles(), setting.getEffectLength() );
	const SearchParticleVector& sortedParticles = spFactory.getSearchParticles();
	Profiler::get()->end(" Sim->sorting");

	SPHSolver solver( factory, setting, sortedParticles);
	solver.calculateInteraction();

	const ParticleVector& particles = factory->getParticles();

	for(Particle* particle: particles ) { particle->force += setting.externalForce * particle->density; }

	for(PhysicsObject* object: physicsObjects ) { object->enforce( setting.timeStep ); }
	
	for(PhysicsObject* object: physicsObjects ) { object->integrateTime( setting.timeStep ); }

	++step;
	simulationTime += setting.timeStep;

	Profiler::get()->end("Simulation->");
}