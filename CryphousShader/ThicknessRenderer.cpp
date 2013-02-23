#include "GLee.h"

#include "ThicknessRenderer.h"
#include "FrameBufferObject.h"

#include <cassert>
#include <ctime>

#include "GLSLUtility.h"

using namespace Cryphous::Geometry;
using namespace Cryphous::Shader;

ThicknessRenderer::ThicknessRenderer(const int width, const int height, float& size, float& alpha ) :
OffScreenRendererBase( width, height),
	size( size),
	alpha( alpha)
{
}

ThicknessRenderer::~ThicknessRenderer(void)
{
}

void ThicknessRenderer::setVisualParticles(const VisualParticleList& visualParticles)
{
	positions.clear();
	densities.clear();
	for( VisualParticleList::const_iterator iter = visualParticles.begin(); iter != visualParticles.end(); ++iter ) {
		const VisualParticle& vp = *iter;
		const Vector3d& center = vp.center;
		positions.push_back( center.x );
		positions.push_back( center.y );
		positions.push_back( center.z );
		densities.push_back( vp.density);
	}
}

void ThicknessRenderer::onRender()
{
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT );
	glEnable(GL_POINT_SPRITE);
	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE); 
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	glClear( GL_DEPTH_BUFFER_BIT);	

	if( !positions.empty() ) {
		shaderObject.apply();
		shaderObject.setUniform("pointSize", size);
		shaderObject.setVertexAttrib( "density", densities, 1 );
		shaderObject.setUniformMatrix("projectionMatrix", projectionMatrix);
		shaderObject.setUniformMatrix("modelviewMatrix", getModelviewMatrix());
		shaderObject.setVertex( "position", positions ); 
		shaderObject.bindFrag("fragColor");
		shaderObject.drawPoints( positions.size() / 3 );
		shaderObject.release();
	}


	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_POINT_SPRITE);
	glDisable(GL_VERTEX_PROGRAM_POINT_SIZE);
}

void ThicknessRenderer::onInit()
{
	assert( GLSLUtility::hasNoError() );

	frameBufferObject = new FrameBufferObject(getWidth(), getHeight(), false);

	projectionMatrix.setPerspectiveMatrix(-0.5f, 0.5f, 0.0f, 1.0f, 0.01f, 100.0f );
	
	shaderObject.createShader("Thickness");
}