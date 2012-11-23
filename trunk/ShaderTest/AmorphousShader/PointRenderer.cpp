#include "StdAfx.h"

#include "PointRenderer.h"

#include <cassert>
#include <boost/foreach.hpp>
#include <ctime>
#include <boost/random.hpp>

#include "ColorRGBA.h"

using namespace Amorphous::Geom;
using namespace Amorphous::Shader;
using namespace Amorphous::Color;

PointRenderer::PointRenderer(const int width, const int height, const PBFRSetting& setting) :
OffScreenRendererBase( width, height),
	setting( setting),
	repetitionLevel ( 0)
{
}

PointRenderer::~PointRenderer(void)
{
}

void PointRenderer::setVisualParticles(const VisualParticleList& visualParticles)
{
	positions.clear();
	colors.clear();
	float maxTemperature = 3000.0f;
	float minTemperature = 1000.0f;
	BOOST_FOREACH( const VisualParticle& vp, visualParticles ) {
		if( vp.temperature < minTemperature ) {
			continue;
		}
		const Vector3d<>& center = vp.center;
		const Vector3d<>& velocity = vp.velocity;
		const ColorRGBA<> color( 1.0f, 0.0f, 0.0f);
		positions.push_back( center.getX() );
		positions.push_back( center.getY() );
		positions.push_back( center.getZ() );
		colors.push_back( 1.0f);
		colors.push_back( 0.0f);
		colors.push_back( color.getBlue());
		colors.push_back( (vp.temperature - minTemperature) / ( maxTemperature - minTemperature ) * setting.pointAlpha );
	}
}

void PointRenderer::onRender()
{
	assert( repetitionLevel < setting.repeatLevel );
	glClearColor( 0.0, 0.0, 0.0, 0.0 );
	glClear( GL_COLOR_BUFFER_BIT );
	glEnable(GL_POINT_SPRITE);
	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE); 
	glEnable(GL_DEPTH_TEST);
	noiseTexture->apply( 0 );
	alphaTexture->apply( 1 );

	glClear( GL_DEPTH_BUFFER_BIT);	

	if( !positions.empty() ) {
		shaderObject.apply();
		shaderObject.setUniform("maxLevel", setting.repeatLevel);
		shaderObject.setUniform("repetitionLevel", repetitionLevel);
		shaderObject.setUniform("pointSize", setting.pointSize);
		shaderObject.setUniform("particleDiameter", setting.distribute);
		shaderObject.setUniform("alphaThreshold", setting.alphaThreshold );
		shaderObject.setUniformMatrix("projectionMatrix", projectionMatrix);
		shaderObject.setUniformMatrix("modelviewMatrix", getModelviewMatrix());
		shaderObject.setUniformTexture("noiseTexture", *noiseTexture);
		shaderObject.setUniformTexture("alphaTexture", *alphaTexture);
		shaderObject.setVertex( "position", positions ); 
		shaderObject.setVertexAttrib("color", colors, 4);
		shaderObject.bindFrag("fragColor");
		shaderObject.drawPoints( positions.size() / 3 );
		shaderObject.release();
	}

	alphaTexture->release();
	noiseTexture->release();

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_POINT_SPRITE);
	glDisable(GL_VERTEX_PROGRAM_POINT_SIZE);

	++repetitionLevel;
}

void PointRenderer::initNoiseTexture()
{
	boost::variate_generator< boost::mt19937, boost::normal_distribution<float> >
		random( boost::mt19937(static_cast<boost::uint32_t>(time(0) ) ),
		boost::normal_distribution<float>( 0.5f, 0.25f ) );
	std::vector<float> noise;
	const int maxLevel = 100;
	for( int i = 0; i < 1000 * maxLevel; ++i ) {
		noise.push_back( random() );
		noise.push_back( random() );
		noise.push_back( random() );
		noise.push_back( (rand()%100) / 100.0f );
	}
	noiseTexture.reset( new TextureObject( noise, 1000, maxLevel) );
}

void PointRenderer::onInit()
{
	glClearColor( 0.0, 0.0, 0.0, 1.0 );
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	repetitionLevel = 0;

	initNoiseTexture();

	projectionMatrix.setPerspectiveMatrix(-0.5f, 0.5f, 0.0f, 1.0f, 0.01f, 100.0f );

	shaderObject.createShader("PointGenerator");

	TextureCreator creator;
	creator.createTexture( 64 );
	alphaTexture.reset( new TextureObject( 64, 64 ) );
	alphaTexture->initAlphaTexture( creator.getTexture(), 64, 64 );
}