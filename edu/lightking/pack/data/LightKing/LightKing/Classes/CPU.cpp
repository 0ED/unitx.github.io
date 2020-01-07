//
//  Model.cpp
//  MyApp
//
//  Created by TasukuTakahashi on 2013/08/31.
//
//

#include "CPU.h"
USING_NS_CC;

bool CPU::init()
{
    this->setTag(2);
    isJump = false;
    isRightHand = false;
    isRightDirection = true;
    aRect = CCRectMake(this->getPositionX(), this->getPositionY(), this->getContentSize().width, this->getContentSize().height);
    
    return true;
}

CPU* CPU::create(const char *aFileName, CCLayerColor* aBigLayer, Player* aPlayer)
{
    CPU *aCPU = new CPU();
    if (aCPU && aCPU->initWithFile(aFileName))
    {
        aCPU->autorelease();
        aCPU->init();
        aCPU->parentLayer = aBigLayer;
        aCPU->player = aPlayer;
        return aCPU;
    }
    CC_SAFE_DELETE(aCPU);
    return NULL;
}

CCRect CPU::getRect(){ return aRect; }

void CPU::moveTo()
{
    isRightDirection = true;
    if(isJump)
    {
        //ジャンプしてたら
    }
    else
    {
        this->stopAllActions();
        
        CCAnimate* actionAnimation;
        if ( (this->getPositionX() - player->getPositionX()) > 0) {
            char aName[] = "LightFoxRunToLeft";
            actionAnimation = getActionAnimation(aName, 1, 12, -1, 0.05);

        }
        else {
            char aName[] = "LightFoxRunToRight";
            actionAnimation = getActionAnimation(aName, 1, 12, -1, 0.05);
        }
        CCMoveTo* actionMove = CCMoveTo::create(1.0, ccp(player->getPositionX(), player->getPositionY()) );
        this->runAction(CCSpawn::createWithTwoActions(actionAnimation,actionMove));
    }
}


CCAnimate* CPU::getActionAnimation(char aFileName[], int firstFrame, int lastFrame, int loops, float speed)
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


void CPU::jump()
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

void CPU::selectTool()
{
    
}



void CPU::attack()
{
    if(isJump)
    {
        //ジャンプしてたら
    }
    else
    {
        char aRight[] = "LightFoxAttackToRight";
        char aLeft[] = "LightFoxAttackToLeft";
        
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