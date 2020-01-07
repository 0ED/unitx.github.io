//
//  TitleScene.h
//  LightKing
//
//  Created by TasukuTakahashi on 2013/09/09.
//
//

#ifndef __LightKing__TitleScene__
#define __LightKing__TitleScene__


#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "CharacterSelect.h"

class TitleScene : public cocos2d::CCLayerGradient
{
private:
    char characterName[3][15] = {"LightFox", "FireBird", "DarkPython"};
    cocos2d::CCSprite *character;
    cocos2d::CCLabelTTF *characterLabel;
    int nowCharacterNumber;
    
public:
    static cocos2d::CCScene* scene();
    virtual bool init();
    void menuChangeScene(CCObject* pSender);
    void changeCharacterRight();
    void changeCharacterLeft();
    void convertChild(char aCharacterName[]);
    void animate(char aCharacterName[]);
    
    CREATE_FUNC(TitleScene);
};

#endif /* defined(__LightKing__TitleScene__) */
