#pragma once

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

namespace Crystal{
	namespace Graphics {

class OpenGLWrapper
{
public:
	OpenGLWrapper() {};

	OpenGLWrapper( HWND hWnd );

	void setHandle( HWND hWnd );

	~OpenGLWrapper(void);

private:
	int SetupPixelFormat( HDC hdc );

private:
	HWND hWnd;	///< �E�B���h�E�n���h��.
	HDC hDC;	///< �f�o�C�X�R���e�L�X�g�n���h��.
	HGLRC hGLRC;	///< OpenGL�n���h��.

public:
	/// �����_�����O�R���e�L�X�g���J�����g�ɐݒ肷��.
	void SetCurrentRenderingContext() {
		wglMakeCurrent( hDC, hGLRC );
	}

	/// �`����J�n����.
	void BeginRendering() {
		wglMakeCurrent( hDC, hGLRC );
	}

	/// �`����I������.
	void EndRendering() {
		SwapBuffers( hDC );
		wglMakeCurrent( hDC, 0);
	}

};

	}	// namespace UI
}	// namespace Crystal