#include "PlayScene.h"
#include "Engine\\Model.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"
#include "Engine/Camera.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene"),hModel_(-1)
{
}

void PlayScene::Initialize()
{
	
	 Instantiate<Player>(this);//Playerのインスタンス＝プレイヤーのオブジェクト
	 Instantiate<Enemy>(this);
	 //Instantiate<Bullet>(this);

	 Camera::SetPosition(XMFLOAT3(0.0f, 2.0f, -10.0f));
	 Camera::SetTarget(XMFLOAT3(0.0f, 0.0f, 10.0f));
}

void PlayScene::Update()
{
	if (FindObject("Enemy")==nullptr) {
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
	
}

void PlayScene::Draw()
{
	
	Model::SetTransform(hModel_, ot_);
	Model::Draw(hModel_);
}

void PlayScene::Release()
{
}
