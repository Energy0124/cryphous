#pragma once

#include "Point3d.h"
#include "Vector3d.h"
#include "Quaternion.h"

namespace Crystal{
	namespace Geom{

/// �􉽃v���~�e�B�u.
class Primitive
{
public:

	enum Type{
		Box,
		Sphere,
		Cylinder
	};

	/// �f�X�g���N�^.
	virtual ~Primitive() {};

	/// �R���X�g���N�^.
	Primitive(const Point3d& pointX, const Point3d& pointY, const Type type);

	/// �R���X�g���N�^.
	//Primitive(const Point3d& center, const double radius);

	/// �̐ς��擾����.
	//virtual double getVolume() const;

	Primitive* createClone() const { return new Primitive(*this);  }

	/// �ő咸�_���擾����.
	Point3d getMax() const { return Point3d( getMaxX(), getMaxY(), getMaxZ() ); }

	/// �ŏ����_���擾����.
	Point3d getMin() const { return Point3d( getMinX(), getMinY(), getMinZ() ); }

	/// �ő�X���擾����.
	double getMaxX() const { return maxX + center.getX(); }

	/// �ŏ�X���擾����.
	double getMinX() const { return minX + center.getX(); }

	/// �ő�Y���擾����.
	double getMaxY() const { return maxY + center.getY(); }

	/// �ŏ�Y���擾����.
	double getMinY() const { return minY + center.getY(); }

	/// �ő�Z���擾����.
	double getMaxZ() const { return maxZ + center.getZ(); }

	/// �ŏ�Z���擾����.
	double getMinZ() const { return minZ + center.getZ(); }

	/// �_���v���~�e�B�u������.
	bool isInterior(const Point3d& point) const;

	/// �_���v���~�e�B�u�O����.
	bool isExterior(const Point3d& point) const;

	Point3d getCenter() const { return center; }

	Type getType() const { return type; }

	void move( const Vector3d& moveVector ) { center += moveVector; }

private:
	double maxX;	///< �ő�X.
	double minX;	///< �ŏ�X.
	double maxY;	///< �ő�Y.
	double minY;	///< �ŏ�Y.
	double maxZ;	///< �ő�Z.
	double minZ;	///< �ő�Z.

	Point3d center;
	Type type;
	//Quaternion quaternion;
};

	}	// namespace Geom
}	// namespace Crystal