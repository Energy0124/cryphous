#pragma once

#include <vector>

namespace Crystal{
	namespace Geom{
		class Point3d;
		class Box;
	}

	namespace Physics{
		class Particle;
		class ParticleFactory;
		typedef std::vector<Particle*> ParticleVector;
		class PhysicsObject;
		class SimulationSetting;

class BoundarySolver
{
public:

	BoundarySolver(PhysicsObject* object, const SimulationSetting& setting );

	void calculateDensity(const Geom::Box& box);

	void calculateForce(const Geom::Box& box);

	~BoundarySolver(void);

private:

	inline void calculateDensity( Particle* particle, const Geom::Point3d boundaryPoint );

private:
	PhysicsObject* object;
	Particle* virtualParticle;
	const SimulationSetting& setting;
};

	}
}