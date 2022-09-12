#pragma once
#include"Component.h"
#include"Collision2D.h"
#include<functional>
#include<vector>

class CollisionComponent : public Component {
public:
	CollisionComponent(class Actor* owner);
	virtual ~CollisionComponent();

	//TODO: Collision�̋@�\�͗v����
	//std::function�͒ʏ�̃|�C���^�T�C�Y�����K�v�ȃ������ʂ������A�֐��̌Ăяo���ɂ��኱�̃I�[�o�[�w�b�h�����݂��܂�[�Q�ƁFhttps://qiita.com/hmito/items/44925fca9fca74e78f61]
	virtual const CollisionShape2D& GetCollision()const = 0;
	void OnCollision(class Actor* other);
	/// <summary>
	/// Component�Ŏw�肵�����֐�������Ƃ��͂����Œ�`����
	/// </summary>
	virtual void OnComponentCollision(class Actor* other);
	/// <summary>
	/// �O������֐��𒍓��������Ƃ��͂��̊֐����g��
	/// </summary>
	void AddCollisionEvent(std::function<void(class Actor*)> f);

private:
	std::vector<std::function<void(class Actor*)>> mOnCollisions;
};