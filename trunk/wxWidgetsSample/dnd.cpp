// �h���b�O�A���h�h���b�v�T���v���D
// �����L�D
// MIT���C�Z���X�D

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/dnd.h"

// �h���b�v���̃C�x���g���L�q���邽�߂̃N���X�D
class DragDropFile : public wxFileDropTarget
{
public:
	DragDropFile(wxListBox *listBox) :
	m_listBox( listBox )
	{
	}

	// �h���b�v���ꂽ�ۂ̏����D���ꂪ�d�v�D
	virtual bool OnDropFiles(wxCoord, wxCoord, const wxArrayString& filenames);

private:
	// ���̃��X�g�{�b�N�X�ɃC�x���g��ǉ����Ă����D
	wxListBox* m_listBox;
};

// �ďo���ƂƂȂ郁�C���A�v���P�[�V�����D
class DragDropApp : public wxApp
{
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(DragDropApp)

class DragDropFrame : public wxFrame
{
public:
	DragDropFrame();

	void OnQuit(wxCommandEvent&) { Close(true); };
	
private:
	void createMenu();

	wxListBox *m_listBox;
	
	DECLARE_EVENT_TABLE()
};

enum
{
	Menu_Quit = 1,
};

// �I�����j���[�݂̂��Ă����D
BEGIN_EVENT_TABLE(DragDropFrame, wxFrame)
	EVT_MENU(Menu_Quit, DragDropFrame::OnQuit)
END_EVENT_TABLE()

// ����DragDropFrame�N���X�̃C���X�^���X�𐶐����邾���D
bool DragDropApp::OnInit()
{
	if ( !wxApp::OnInit() ) {
		return false;
	}

	new DragDropFrame();

	return true;
}

DragDropFrame::DragDropFrame() :
wxFrame(
	NULL,
	wxID_ANY,
	wxT("DragDrop Sample"),
	wxPoint(10, 100)
	)
{
	// �R���X�g���N�^�������Ȃ肷���Ȃ��悤�ɕʊ֐��ɂ܂Ƃ߂Ă��܂��D
	createMenu();
}

void DragDropFrame::createMenu()
{
	SetIcon( wxICON(sample) );

	CreateStatusBar();

	wxMenu *fileMenu = new wxMenu;
	fileMenu->Append(Menu_Quit, wxT("E&xit\tCtrl-Q"));

	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(fileMenu, wxT("&File"));

	SetMenuBar(menuBar);

	const wxString str( wxT("�����Ƀt�@�C�����h���b�v���Ă��������D") );

	m_listBox  = new wxListBox(
		this,
		wxID_ANY,
		wxDefaultPosition,
		wxDefaultSize,
		1,
		&str,
		wxLB_HSCROLL | wxLB_ALWAYS_SB
	);

	m_listBox->SetDropTarget( new DragDropFile(m_listBox) );

	Show();
}

bool DragDropFile::OnDropFiles(wxCoord, wxCoord, const wxArrayString& filenames)
{
	const size_t howMany = filenames.GetCount();
	const wxString str = wxString::Format("�h���b�v���ꂽ�t�@�C���� = %d\n", static_cast<int>(howMany) );

	m_listBox->Append(str);
	for ( size_t i = 0; i < howMany; i++ ) {
		m_listBox->Append( filenames[i] );
	}

	return true;
}
