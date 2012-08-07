#pragma once

#include "DialogCommand.h"

namespace Crystal{
	namespace Command{

public ref class GraphicsSettingCommand : public DialogCommand
{
public:
	GraphicsSettingCommand();

	~GraphicsSettingCommand();

	void setTrackBar( 
		System::Windows::Forms::TrackBar^ trackBarPointSize,
		System::Windows::Forms::TrackBar^ trackBarAlphaPower,
		System::Windows::Forms::CheckBox^ checkBoxBoundingBox
		);
};

	}
}