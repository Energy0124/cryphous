#ifndef __CRYPHOUS_DEPTH_SPRITE_RENDERER_H__
#define __CRYPHOUS_DEPTH_SPRITE_RENDERER_H__

#include "OffScreenRendererBase.h"
#include "VisualParticle.h"
#include <memory>

namespace Cryphous{
	namespace Shader{

class DepthRenderer : public OffScreenRendererBase
{
public:
	DepthRenderer(const int width, const int height, const float& size);

	~DepthRenderer(void);

	void setVisualParticles(VisualParticleCollection* visualParticles) { this->collection = visualParticles; }

protected:
	virtual void onRender();

	virtual void onInit();

	virtual void onIdle(){};

private:
	VisualParticleCollection* collection;

	const float& size;
};

	}
}
#endif