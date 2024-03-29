#include "BoundaryCoordinator.h"

#include "../Math/Box.h"

using namespace Crystal::Math;
using namespace Crystal::Physics;

#ifdef _OPENMP
#include <omp.h>
#endif

float getForce(const float over, const float timeStep)
{
	return -over / timeStep / timeStep; 
}

Vector3d getForceX(const float x, const Box& box, const float timeStep)
{
	float over = 0.0f;
	if( x > box.getMaxX() ) {
		over = x - box.getMaxX();
	}
	else if( x < box.getMinX() ) {
		over = x - box.getMinX();
	}

	const float force = getForce( over, timeStep ); 
	return Vector3d::UnitX() * force;
}

Vector3d getForceY(const float y, const Box& box, const float timeStep)
{
	float over = 0.0f;
	if( y > box.getMaxY() ) {
		over = y - box.getMaxY();
	}
	else if( y < box.getMinY() ) {
		over = y - box.getMinY();
	}
	const float force = getForce( over, timeStep );
	return Vector3d::UnitY() * force;
}

Vector3d getForceZ(const float z, const Box& box, const float timeStep)
{
	float over = 0.0f;
	if( z > box.getMaxZ() ) {
		over = z - box.getMaxZ();
	}
	else if( z < box.getMinZ() ) {
		over = z - box.getMinZ();
	}
	const float force = getForce( over, timeStep );
	return Vector3d::UnitZ() * force;
}

Vector3d getForce( const Vector3d& center, const float timeStep, const Box& box)
{
	Vector3d force = Vector3d::Zero();

	force += getForceX( center.getX(), box, timeStep );
	force += getForceY( center.getY(), box, timeStep );
	force += getForceZ( center.getZ(), box, timeStep );

	return force;
}

void BoundaryCoordinator::coordinate(const ParticleVector& particles, const float timeStep)
{
	#pragma omp parallel for
	for( int i = 0; i < static_cast<int>( particles.size() ); ++i ) {
		particles[i]->addForce( ::getForce( particles[i]->getCenter(), timeStep, box ) * particles[i]->getDensity() );
	}
};

Vector3d getForce( const Vector3d& pos, const float timeStep, const float radius, const Vector3d& center )
{
	if( pos.getDistanceSquared( center ) > radius * radius ) {
		Vector3d normal = pos - center;
		const float over = pos.getDistance( center ) - radius;
		normal.normalize();
		return normal * ::getForce( over, timeStep );
	}
	return Vector3d::Zero();
}

Vector3d getPosition( const Vector3d& pos, const float radius, const Vector3d& center)
{
	if( pos.getDistanceSquared( center ) > radius * radius ) {
		Vector3d normal = pos - center;
		normal.normalize();
		return normal * radius;
	}
	return pos;
}

void SphereBoundaryCoordinator::coordinate( const ParticleVector& particles, const float timeStep )
{
	#pragma omp parallel for
	for( int i = 0; i < static_cast<int>( particles.size() ); ++i ) {
		particles[i]->addForce( ::getForce( particles[i]->getCenter(), timeStep, radius, center ) );
		//particles[i]->setCenter( ::getPosition( particles[i]->getCenter(), radius, center ) );
	}
}