#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Player.h"
#include "CPU.h"
#include "TapSprite.h"
#include "MainButton.h"
#include "cocos-ext.h"
using namespace cocos2d::extension;


class HelloWorld : public cocos2d::CCLayerColor
{
private:
    static const int CURSOR_LOCATION_X = 90;
    static const int CURSOR_LOCATION_Y = 70;
    static const int CURSOR_MARGIN = 45;
    static const int GROUND_LINE_HEIGHT = 60;
    static const int CHARACTER_X = 150;
    Player* player;
    CPU* enemy;
    
public:
    virtual bool init();
    virtual void update();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    void setButton(CCScrollView *aScrollView);
    void setBar();

    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
