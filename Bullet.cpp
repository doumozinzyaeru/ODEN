#include "Bullet.h"
#include "Engine\\Model.h"
#include "Player.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent,"Bullet"),hModel_(-1),speed_(0.5f)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("tama.fbx");
	assert(hModel_ >= 0);
	transform_.scale_ = { 0.25f,0.25f,0.25f };
	//Player* player = static_cast<Player*>(FindObject("Player"));

	transform_.rotate_ = {
	XMConvertToRadians(90.0f),
	0.0f,
	0.0f
	};


	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 0.5f);
	AddCollider(collider);

}

void Bullet::Update()
{
	transform_.position_.z = tm_.position_.z += speed_;

	

	if (transform_.position_.z > 50.0f)
	{
		KillMe();//自分を削除する
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

}

void Bullet::Release()
{

}
