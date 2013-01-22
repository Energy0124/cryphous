#include "GLee.h"

#include "DepthRenderer.h"

#include <cassert>
#include <ctime>

#include "GLSLUtility.h"

#include "FrameBufferObject.h"

using namespace Crystal::Geom;
using namespace Crystal::Shader;

DepthRenderer::DepthRenderer(const int width, const int height, const float& size) :
OffScreenRendererBase( width, height),
	size( size)
{
}

DepthRenderer::~DepthRenderer(void)
{
}

void DepthRenderer::setVisualParticles(const VisualParticleList& visualParticles)
{
	positions.clear();
	colors.clear();
	for( VisualParticleList::const_iterator iter = visualParticles.begin(); iter != visualParticles.end(); ++iter ) {
		const VisualParticle& vp = *iter;
		const Vector3d& center = vp.center;
		positions.push_back( center.x );
		positions.push_back( center.y );
		positions.push_back( center.z );
		colors.push_back( 1.0f);
		colors.push_back( 0.0f);
		colors.push_back( 0.0f);
	}
}

void DepthRenderer::onRender()
{
	glClearColor( 0.0, 0.0, 0.0, 0.0 );
	glClear( GL_COLOR_BUFFER_BIT );
	glEnable(GL_POINT_SPRITE);
	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE); 
	glEnable(GL_DEPTH_TEST);

	glClear( GL_DEPTH_BUFFER_BIT);	

	if( !positions.empty() ) {
		shaderObject.apply();
		shaderObject.setUniform("pointSize", size);
		shaderObject.setUniformMatrix("projectionMatrix", projectionMatrix);
		shaderObject.setUniformMatrix("modelviewMatrix", getModelviewMatrix());
		shaderObject.setVertex( "position", positions ); 
		shaderObject.bindFrag("fragColor");
		shaderObject.drawPoints( positions.size() / 3 );
		shaderObject.release();
	}

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_POINT_SPRITE);
	glDisable(GL_VERTEX_PROGRAM_POINT_SIZE);
}

void DepthRenderer::onInit()
{
	assert( GLSLUtility::hasNoError() );

	frameBufferObject = new FrameBufferObject(getWidth(), getHeight(), false);

	projectionMatrix.setPerspectiveMatrix(-0.5f, 0.5f, 0.0f, 1.0f, 0.01f, 100.0f );
	
	shaderObject.createShader("Depth");
}