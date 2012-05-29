#pragma once

namespace Crystal{
	namespace Physics{

class Particle;

/// ���̗��q�\���o.
class RigidSolver
{
public:
	/// �R���X�g���N�^.
	RigidSolver(Particle* particleX, Particle* particleY);

	/// �@�������̗͂��v�Z����.
	void calculateNormalForce();

	/// �ڐ������̗͂��v�Z����.
	void calculateTangentForce();

private:
	Particle* particleX;
	Particle* particleY;
};

	}	// namespace Physics
}	// namespace Crystal;
