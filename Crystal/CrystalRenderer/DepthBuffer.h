#ifndef __DEPTH_BUFFER_H__
#define __DEPTH_BUFFER_H__

#include "Point2d.h"

#include <vector>

namespace Crystal{
	namespace Renderer{

class DepthBuffer
{
public:
	DepthBuffer(const int xWidth, const int yWidth)
	{
		depths.resize( xWidth );
		for( int x = 0; x < xWidth; ++x ) {
			depths[x].resize( yWidth );
			for( int y = 0; y < yWidth; ++y ) {
				depths[x][y] = 1.0e+9f;
			}
		}
	}

	int getWidth() const { return depths.size(); }

	int getHeight() const { return depths[0].size(); }

	void setDepth(const Point2d& point, const float depth)
	{
		depths[point.x][point.y] = depth;
	}

	float getDepth(const Point2d& point) const
	{
		return depths[point.x][point.y];
	}

	void clear(const float depth)
	{
		for( size_t x = 0; x < depths.size(); ++x ) {
			for( size_t y = 0; y < depths[x].size(); ++y ) {
				depths[x][y] = depth;
			}
		}
	}

private:
	std::vector< std::vector<float> > depths;
};

	}
}

#endif