#include"ScrollSpriteDrawerY.h"
#include"Actor.h"

ScrollSpriteDrawerY::ScrollSpriteDrawerY(float speed,const std::string& fileName, Actor* owner, int order):
	SpriteDrawer(fileName,owner,order),mScrollOffset(0),mScrollSpeed(speed)
{
    mOwner->SetPosition(Vector2(1024 / 2, 768 / 2));
}

void ScrollSpriteDrawerY::Update(float deltaTime)
{
    // �I�t�Z�b�g�l���X�V
    mScrollOffset += mScrollSpeed * deltaTime;
    if (mScrollOffset > 768)
    {
        mScrollOffset -= 768;
    }
}

void ScrollSpriteDrawerY::Draw(SDL_Renderer* renderer)
{
    // �X�N���[�������邽�߂Q�����ׂĕ`�悷��
// �ʏ�̃e�N�X�`���`��
    SDL_Rect r;
    r.w = static_cast<int>(mTexWidth * mOwner->GetScale().x);
    r.h = static_cast<int>(mTexHeight * mOwner->GetScale().y);
    r.x = static_cast<int>(mOwner->GetPosition().x - r.w / 2);
    r.y = static_cast<int>(mOwner->GetPosition().y - r.h / 2+mScrollOffset);
    SDL_RenderCopyEx(renderer, mTexture, nullptr, &r, -Math::ToDegrees(mOwner->GetRotate()), nullptr, SDL_FLIP_NONE);

    // �ʏ�e�N�X�`���̏㕔�ɂ����ꖇ�`��
    SDL_Rect r_top;
    r_top.w = static_cast<int>(mTexWidth * mOwner->GetScale().x);
    r_top.h = static_cast<int>(mTexHeight * mOwner->GetScale().y);
    r_top.x = static_cast<int>(mOwner->GetPosition().x - r_top.w / 2);
    r_top.y = static_cast<int>(mOwner->GetPosition().y - r_top.h / 2 - 768 + mScrollOffset); // �X�N���[���T�C�Y������
    SDL_RenderCopyEx(renderer, mTexture, nullptr, &r_top, -Math::ToDegrees(mOwner->GetRotate()), nullptr, SDL_FLIP_NONE);
}
