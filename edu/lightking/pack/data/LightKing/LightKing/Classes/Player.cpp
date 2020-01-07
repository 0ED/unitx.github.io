//
//  Model.cpp
//  MyApp
//
//  Created by TasukuTakahashi on 2013/08/31.
//
//

#include "Player.h"
USING_NS_CC;

bool Player::init()
{
    this->setTag(1);
    isJump = false;
    isRightHand = false;
    isRightDirection = true;
    aRect = CCRectMake(this->getPositionX(), this->getPositionY(), this->getContentSize().width, this->getContentSize().height);
    
    return true;
}

Player* Player::create(const char *aFileName, CCLayerColor* aBigLayer)
{
    Player *aPlayer = new Player();
    if (aPlayer && aPlayer->initWithFile(aFileName))
    {
        aPlayer->autorelease();
        aPlayer->init();
        aPlayer->parentLayer = aBigLayer;
        return aPlayer;
    }
    CC_SAFE_DELETE(aPlayer);
    return NULL;
}

CCRect Player::getRect(){ return aRect; }


void Player::moveToRight()
{
    isRightDirection = true;
    if(isJump)
    {
        //ジャンプしてたら
    }
    else
    {
        char aName[] = "LightFoxRunToRight";
        CCAnimate* actionAnimation = getActionAnimation(aName, 1, 12, -1, 0.05);
        CCMoveTo* actionMove = CCMoveTo::create(2.2, ccp(parentLayer->getContentSize().width + 55, this->getPositionY()));
        this->runAction(CCSpawn::createWithTwoActions(actionAnimation,actionMove));
    }
}

void Player::moveToLeft()
{
    isRightDirection = false;
    if(isJump)
    {
        //ジャンプしてたら
    }
    else
    {
        char aName[] = "LightFoxRunToLeft";
        CCAnimate* actionAnimation = getActionAnimation(aName, 1, 12, -1, 0.05);
        CCMoveTo* actionMove = CCMoveTo::create(2.2,ccp(-55, this->getPositionY()));
        this->runAction(CCSpawn::createWithTwoActions(actionAnimation,actionMove));
    }
}


CCAnimate* Player::getActionAnimation(char aFileName[], int firstFrame, int lastFrame, int loops, float speed)
{
    CCAnimation* animation = CCAnimation::create();
    for (int index = firstFrame; index <= lastFrame; index++)
    {
        char names[100] = {0};
        sprintf(names, "%s%04d.png", aFileName, index);
        animation->addSpriteFrameWithFileName(names);

    }
    animation->setDelayPerUnit(speed);
    animation->setRestoreOriginalFrame(true);
    animation->setLoops(loops);
    CCAnimate* actionAnimation = CCAnimate::create(animation);
    
    return actionAnimation;
}


void Player::jump()
{
    if (isRightDirection) {
        this->setTexture(CCTextureCache::sharedTextureCache()->addImage("LightFoxJumpToRight.png") );
    }
    else {
        this->setTexture(CCTextureCache::sharedTextureCache()->addImage("LightFoxJumpToLeft.png") );
    }
    CCActionInterval* action = CCJumpBy::create(1.0f, ccp(20, 0), 100, 1);
    this->runAction(action);
}

void Player::selectTool()
{
    
}



void Player::attack()
{
    if(isJump)
    {
        //ジャンプしてたら
    }
    else
    {
        char aRight[] = "LightFoxAttackToRight";
        char aLeft[] = "LightFoxAttackToLeft";
        
        this->stopAllActions();
        CCAnimate* actionAnimation;
        if (isRightHand) {
            isRightHand = false;
            if (isRightDirection) {
                actionAnimation = getActionAnimation(aRight, 1, 6, 1, 0.03);
            }
            else {
                actionAnimation = getActionAnimation(aLeft, 1, 6, 1, 0.03);
            }
        }
        else {
            isRightHand = true;
            if (isRightDirection) {
                actionAnimation = getActionAnimation(aRight, 7, 11, 1, 0.03);
            }
            else {
                actionAnimation = getActionAnimation(aLeft, 7, 11, 1, 0.03);
            }
        }
        this->runAction(actionAnimation);
        
    }
}