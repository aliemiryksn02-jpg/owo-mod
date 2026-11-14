#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
using namespace geode::prelude;
class $modify(OwoMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;
        auto winSize = CCDirector::sharedDirector()->getWinSize();
        auto label = CCLabelBMFont::create("OwO", "bigFont.fnt");
        label->setPosition(winSize / 2);
        label->setScale(1.5f);
        label->setOpacity(0);
        this->addChild(label, 1000);
        label->runAction(CCSequence::create(CCDelayTime::create(0.5f), CCFadeIn::create(0.3f), CCDelayTime::create(2.0f), CCFadeOut::create(0.3f), nullptr));
        return true;
    }
};
