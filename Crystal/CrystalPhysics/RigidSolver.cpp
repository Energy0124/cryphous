
#include "RigidSolver.h"

#include "Particle.h"

#include "../CrystalGeom/Point3d.h"
#include "../CrystalGeom/Vector3d.h"

#include <algorithm>
#include <cmath>

using namespace Crystal::Geom;
using namespace Crystal::Physics;

/// �R���X�g���N�^.
RigidSolver::RigidSolver(Particle* particleX, Particle* particleY) :
particleX( particleX ),
particleY( particleY )
{
}

/// �@�������̗͂��v�Z����.
void RigidSolver::calculateNormalForce()
{
	// �I�[�o�[���b�v���Ă���x�N�g�������߂�.
	const double particleLength = particleX->getRadius() + particleY->getRadius();
	const Vector3d distanceVector( particleX->center, particleY->center );
	const double overlapLength = std::max( 0.0, particleLength - distanceVector.getLength() );

	// �������ʂ����߂�.
	const double massEffective = 1.0 / ( 1.0 / particleX->getMass() + 1.0 / particleY->getMass() );
	const double normalRestitution = 1.0;	// �@�����͌W��. TODO.
	const double timeStep = 1.0e-3;
	const double correspondingCoefficient = 2.0 * massEffective * log( normalRestitution ) / timeStep;

	// ���Α��x�����߂�.
	const Vector3d velocityVector( particleX->velocity, particleY->velocity );
	const double relativeVelosity = velocityVector.getInnerProduct( distanceVector );
}
