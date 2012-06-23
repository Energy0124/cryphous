#include "SimulationSettingCommand.h"
#include "ApplicationSettings.h"

#include "../CrystalPhysics/SimulationSetting.h"

using namespace Crystal::Physics;
using namespace Crystal::Command;

using namespace System;
using namespace System::Windows::Forms;

SimulationSettingCommand::SimulationSettingCommand(void)
{
}

void SimulationSettingCommand::setTextBox(System::Windows::Forms::TextBox ^textBoxTimeStep, System::Windows::Forms::TextBox ^textBoxEffectLength )
{
	SimulationSetting* setting = ApplicationSettings::get()->simulationSetting;

	itemAndVariables.Clear();
	itemAndVariables.Push( gcnew DoubleTextBox( &(setting->timeStep), textBoxTimeStep ) );
	itemAndVariables.Push( gcnew DoubleTextBox( &(setting->particleDiameter), textBoxEffectLength ) );
}