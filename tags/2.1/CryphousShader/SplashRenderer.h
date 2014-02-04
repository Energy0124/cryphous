#ifndef __CRYPHOUS_SPLASH_RENDERER_H__
#define __CRYPHOUS_SPLASH_RENDERER_H__

#include "OffScreenRendererBase.h"
#include "VisualParticle.h"

namespace Cryphous{
	namespace Shader{

class SplashRenderer : public OffScreenRendererBase
{
public:
	SplashRenderer(const int width, const int height, float& size, float& alpha);

	~SplashRenderer(void);

	void setVisualParticles(VisualParticleCollection* visualParticles) { this->collection = visualParticles; }

protected:
	virtual void onRender();

	virtual void onInit();

	virtual void onIdle(){};

private:
	VisualParticleCollection* collection;

	float& size;
	float& alpha;
};

	}
}
#endif