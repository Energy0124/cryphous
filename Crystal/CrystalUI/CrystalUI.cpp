// CrystalUI.cpp : ���C�� �v���W�F�N�g �t�@�C���ł��B

//#include "stdafx.h"
#include "MainForm.h"

using namespace Crystal::UI;

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// �R���g���[�����쐬�����O�ɁAWindows XP �r�W���A�����ʂ�L���ɂ��܂�
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// ���C�� �E�B���h�E���쐬���āA���s���܂�
	Application::Run(gcnew MainForm());
	return 0;
}