#pragma once

#include <list>

namespace Crystal {
	namespace Physics {
		class PhysicsObjectCondition;
		typedef std::list<PhysicsObjectCondition*> PhysicsObjectConditionList;
	}

	namespace Command {

/// �A�v���P�[�V�����ݒ�N���X.
public ref class ApplicationSettings
{
public:

	/// �R���X�g���N�^.
	ApplicationSettings(void);

	/// �f�X�g���N�^.
	~ApplicationSettings();

	/// XML�֏����o��.
	System::Xml::XmlDocument^ writeToXML();

	/// XML����ǂݍ���.
	bool readFromXML( System::Xml::XmlDocument^ doc );
};

	}	// namespace Command
}	// namespace Crystal