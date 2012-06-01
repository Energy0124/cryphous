#pragma once

#include "Kernels.h"

namespace Crystal{
	namespace Physics{

class Kernels3D : public Kernels
{
public:

	Kernels3D(const double effectLength);

	virtual ~Kernels3D(void);

protected:
	virtual void setPoly6Constant();

	virtual void setPoly6ConstantGradient();

	virtual void setPoly6ConstantLaplacian();

	virtual void setSpikyConstantGradient();

	virtual void setViscosityConstantLaplacian();
};

	}
}