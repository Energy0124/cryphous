#pragma once

#include <vector>

#include "../CrystalGeom/Vector3d.h"
#include "Particle.h"

#include <boost/noncopyable.hpp>

namespace Crystal{
	namespace Physics{
		class Particle;
		class SpaceHash;
		class BoundarySolver;

/// ���q�y�A�N���X.
class ParticlePair : private boost::noncopyable
{
public:

	ParticlePair();

	/// �R���X�g���N�^.
	ParticlePair(Particle* particleX, Particle* particleY) :
	  particleX( particleX),
		  particleY( particleY),
		  distanceVector( particleY->center, particleX->center )
	{
		distance = distanceVector.getLength();
	}

	 /// �f�X�g���N�^.
	 ~ParticlePair() { };

public:
	/// ���ڗ��q���擾����.
	Particle* getParticleX() const { return particleX; }

	/// �Ώ̗��q���擾����.
	Particle* getParticleY() const { return particleY; }

	/// ���q�ԋ����x�N�g�����擾����.
	Geom::Vector3d getDistanceVector() const { return distanceVector; }

	/// ���q�ԋ������擾����.
	double getDistance() const { return distance; }

private:
	Particle* particleX;	///< ���ڗ��q.
	Particle* particleY;	///< �Ώ̗��q.
	Geom::Vector3d distanceVector;	///< �����x�N�g��.
	double distance;	///< ���q�ԋ���. �L���b�V��.

};

typedef std::vector<ParticlePair*> ParticlePairVector; 
	}	// namespace Physics
}	// namespace Crystal