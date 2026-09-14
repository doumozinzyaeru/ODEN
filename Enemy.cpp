#include "Enemy.h"
#include "Engine\\Model.h"
#include "Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel_(-1)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hp_ = 10;

	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0.0f,-3.0f,10.0f };
	transform_.scale_ = { 0.7f,0.7f,0.7f };
	transform_.rotate_= { 0.0f,0.0f,0.0f };

	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 2.0f);
	AddCollider(collider);

}

void Enemy::Update()
{
	static float time = 0.0f;
	time += 0.025f;
	float posx = 3.0f * sin(0.5f * time);
	//float posy = cos(3.0f * time);
	transform_.position_.x = posx;
	//transform_.position_.y =posy;
	// コライダー位置更新
	


}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

	
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet")
	{
		pTarget->KillMe();//バレット消して

		hp_--;

		if(hp_<=0)
		KillMe();//自分も消す
	}
}

void Enemy::SetPosition(const XMFLOAT3& pos)
{
	transform_.position_ = pos;
}