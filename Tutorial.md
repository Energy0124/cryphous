# Introduction #

流体演算エンジンのチュートリアル．

エンジンはヘッダファイルのみの構成のため，
ビルド不要です．

Cryphous 1.7 Sources（Downloads より入手可能）に対応．
CrystalGeom と CrystalPhysics フォルダを任意の場所にコピーすればインストール完了です。

# Details #

```
#include "../CrystalPhysics/Simulation.h"

#include <iostream>

using namespace Crystal::Geom;
using namespace Crystal::Physics;

void main(void)
{
	//　粒子中心座標を作成する．今回は1つのみ．
	std::vector<Vector3d> points;
	points.push_back( Vector3d(0.5f, 0.5f, 0.5f) );
	
	//　物理オブジェクト生成条件を設定する．圧力と粘性は適当．
	PhysicsObjectCondition condition( points, 1000.0, 20000.0, 100.0, PhysicsObjectCondition::Fluid ); 
	
	//　シミュレーション条件（壁やタイムステップなど）を設定する．今回はデフォルト値．
	SimulationSetting setting;

	// 物理オブジェクトを生成する．粒子も自動的に生成される．
	PhysicsObjectFactory factory;
	factory.createPhysicsObject( condition, setting);
	
	// 物理オブジェクトを構成する粒子を取得する．
	ParticleVector particles = factory.getParticles();
	Particle* particle = particles.front();
	
	// シミュレーションを行う．
	// 粒子が0.5から落下し，0.25あたりで跳ね返る（デフォルトの粒子半径は0.25）ことが確認できる．
	// その後，再び0.5まで戻り，運動量が保存されていることも確認できる．
	Simulation simulation;
	for( int i = 0; i < 100; ++i ) {
		simulation.simulate( &factory, setting );
		std::cout << particle->center.getY() << std::endl;
	}
}

```