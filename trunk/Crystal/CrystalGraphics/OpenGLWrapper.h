#pragma once

#include <windows.h>
#include <GL/gl.h>

namespace Crystal{
	namespace Graphics {

class OpenGLWrapper
{
public:
	OpenGLWrapper() {};

	OpenGLWrapper(HWND hWnd) { setHandle( hWnd ); }

	~OpenGLWrapper(void)
	{
		wglMakeCurrent(0, 0); 
		wglDeleteContext(hGLRC);
		ReleaseDC( hWnd, hDC );
	}

	void setHandle( HWND hWnd )
	{
		this->hWnd = hWnd;
		hDC = GetDC( this->hWnd );
		if( 0 != SetupPixelFormat( hDC ) ) return;
	
		hGLRC = wglCreateContext(hDC); 
	}

private:
	int OpenGLWrapper::SetupPixelFormat(HDC hDC)
	{
		static PIXELFORMATDESCRIPTOR pfd = {
			sizeof (PIXELFORMATDESCRIPTOR),		// �\���̂̃T�C�Y
			1,									// OpenGL �o�[�W����
			PFD_DRAW_TO_WINDOW |				// �E�B���h�E�X�^�C��
			PFD_SUPPORT_OPENGL |				// OpenGL ���g��
			PFD_DOUBLEBUFFER,					// �_�u���o�b�t�@
			PFD_TYPE_RGBA,						// �s�N�Z���̃J���[�f�[�^
			32,									// �F�̃r�b�g��
			0, 0, 0, 0, 0, 0, 0, 0,				// RGBA�J���[�o�b�t�@�̃r�b�g
			0, 0, 0, 0, 0,						// �A�L�������[�V�����o�b�t�@�̃s�N�Z������̃r�b�g��
			32,									// �f�v�X�o�b�t�@    �̃s�N�Z������̃r�b�g��
			0,									// �X�e���V���o�b�t�@�̃s�N�Z������̃r�b�g��
			0,									// �⏕�o�b�t�@      �̃s�N�Z������̃r�b�g��
			PFD_MAIN_PLANE,						// ���C���[�^�C�v
			0,									// 
			0,									// 
			0,									// 
			0									// 
		};

		const int pixelformat = ChoosePixelFormat( hDC, &pfd);
    
		if ( 0 == pixelformat ) {
			return 1;
		}
		else if ( FALSE == SetPixelFormat(hDC, pixelformat, &pfd) ) {
			return 2;
		}

		return 0;
	}

private:
	HWND hWnd;
	HDC hDC;
	HGLRC hGLRC;

public:
	void SetCurrentRenderingContext() {
		wglMakeCurrent( hDC, hGLRC );
	}

	void BeginRendering() {
		wglMakeCurrent( hDC, hGLRC );
	}

	void EndRendering() {
		SwapBuffers( hDC );
		wglMakeCurrent( hDC, 0);
	}

};
	}
}