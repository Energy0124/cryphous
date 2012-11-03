#include "BoundaryPhotonSolver.h"

#include "LightSource.h"

using namespace Crystal::Geom;
using namespace Crystal::Physics;

#ifdef _OPENMP
#include <omp.h>
#endif

void BoundaryPhotonSolver::reflectPhoton(const Box& box)
{
	const PhotonVector& photons = lightSource->getPhotons();
	#pragma omp parallel for
	for( int i = 0; i < static_cast<int>(photons.size()); ++i ) {
		Photon* photon = photons[i];
		//int random = std::rand() % 10000;
		bool doStop = false;//random > 5000;
		if( photon->center.getX() > box.getMaxX() ) {
			doStop ? ++photon->absorbedTime : photon->velocity.setX( -::fabs(photon->velocity.getX()) );
			photon->center.setX( box.getMaxX() );
		}
		else if( photon->center.getX() < box.getMinX() ) {
			doStop ? ++photon->absorbedTime : photon->velocity.setX( ::fabs(photon->velocity.getX()) );
			photon->center.setX( box.getMinX() );
		}

		if( photon->center.getY() > box.getMaxY() ) {
			doStop ? ++photon->absorbedTime : photon->velocity.setY( -::fabs(photon->velocity.getY()) );
			photon->center.setY( box.getMaxY() );
		}
		else if( photon->center.getY() < box.getMinY() ) {
			doStop ? ++photon->absorbedTime : photon->velocity.setY( ::fabs(photon->velocity.getY()) );
			photon->center.setY( box.getMinY() );
		}

		if( photon->center.getZ() > box.getMaxZ() ) {
			doStop ? ++photon->absorbedTime : photon->velocity.setZ( -::fabs(photon->velocity.getZ()) );
			photon->center.setZ( box.getMaxZ() );
		}
		else if( photon->center.getZ() < box.getMinZ() ) {
			doStop ? ++photon->absorbedTime : photon->velocity.setZ( ::fabs(photon->velocity.getZ()) );
			photon->center.setZ( box.getMinZ() );
		}
	}
}