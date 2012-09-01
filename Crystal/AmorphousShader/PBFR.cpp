#include "StdAfx.h"

#include "PBFR.h"
#include "PointRenderer.h"
#include "CompositeRenderer.h"
#include "FrameBufferObject.h"
#include "GLSLUtility.h"

#include <boost/foreach.hpp>

#include <cassert>
#include <cmath>
#include <cstdlib>

using namespace Crystal::Geom;
using namespace Crystal::Shader;

PBFR::PBFR(const int width, const int height, const PBFRSetting& setting) :
ScreenRendererBase( width, height ),
setting( setting)
{
	pointRenderer = new PointRenderer( getWidth(), getHeight(), setting);
	compositeRenderer = new CompositeRenderer( getWidth(), getHeight() );
}

PBFR::~PBFR()
{
	delete compositeRenderer;
	delete pointRenderer;
}

void PBFR::onInit()
{
	//openGLWrapper.SetCurrentRenderingContext();

	pointRenderer->init();
	compositeRenderer->init();
	shaderObject.createShader("IntensityOffsetter");

	projectionMatrix.setOrthogonalMatrix( 0.0, 1.0, 0.0, 1.0, -1.0, 1.0 );
	
	points.resize(12);
	points[0] = 0.0; points[1] = 1.0; points[2] = 0.0;
	points[3] = 0.0; points[4] = 0.0; points[5] = 0.0;
	points[6] = 1.0; points[7] = 0.0; points[8] = 0.0;
	points[9] = 1.0; points[10] = 1.0; points[11] = 0.0;

	assert( GL_NO_ERROR == glGetError() );
}

void PBFR::onRender()
{
	assert( GL_NO_ERROR == glGetError() );

	//FrameBufferObject fbo( getWidth(), getHeight(), false );
	//TextureObject& backgroundTexture = fbo.getTextureObject();

	pointRenderer->setVisualParticles( visualParticles );
	
	pointRenderer->initRepetitionLevel();

	std::auto_ptr<FrameBufferObject> sourceBuffer( new FrameBufferObject( getWidth(), getHeight(), false) );
	std::auto_ptr<FrameBufferObject> targetBuffer( new FrameBufferObject( getWidth(), getHeight(), false) );
	std::auto_ptr<FrameBufferObject> temporaryBuffer( new FrameBufferObject( getWidth(), getHeight(), false) );	

	glClearColor( 0.5, 0.0, 0.0, 0.0 );
	glClear( GL_COLOR_BUFFER_BIT );

	pointRenderer->render();
	/*for( int i = 0; i < setting.repeatLevel; ++i ) {
		pointRenderer->render( *temporaryBuffer );
		compositeRenderer->setTextureObject( &(sourceBuffer->getTextureObject()), &(temporaryBuffer->getTextureObject()) );
		compositeRenderer->render( *targetBuffer );
		std::swap( sourceBuffer, targetBuffer );
	}*/

	/*compositeRenderer->setTextureObject( &(sourceBuffer->getTextureObject()), &backgroundTexture);
	compositeRenderer->render( *targetBuffer );
	std::swap( sourceBuffer, targetBuffer );
	
	sourceBuffer->getTextureObject().apply(0);
	
	assert( GLSLUtility::hasNoError() );

	shaderObject.apply();
	shaderObject.setUniformMatrix("projectionMatrix", projectionMatrix);
	shaderObject.setUniformMatrix("modelviewMatrix", GLSLMatrix());
	shaderObject.setUniformTexture("offScreenTexture", sourceBuffer->getTextureObject());
	shaderObject.setUniform("intensityScale", 1.0f);
	shaderObject.setVertex("position", points );
	shaderObject.drawQuads( 4);
	shaderObject.release();*/

	sourceBuffer->getTextureObject().release(); 

	assert( GLSLUtility::hasNoError() );

	//glFlush();
}