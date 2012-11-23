#include "StdAfx.h"

#include "OnScreenRendererBase.h"

using namespace Amorphous::Shader;

OnScreenRendererBase::OnScreenRendererBase(const int width, const int height) :
ScreenRendererBase(width, height)
{
}

void OnScreenRendererBase::render()
{
	assert( GL_NO_ERROR == glGetError() );
	glViewport( 0, 0, getWidth() , getHeight() );
	assert( GL_NO_ERROR == glGetError() );
	onRender();
}

void OnScreenRendererBase::idle()
{
	onIdle();
}