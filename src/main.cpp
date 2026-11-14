#include <Geode/Geode.hpp>
using namespace geode::prelude;

#include <Geode/modify/PlayLayer.hpp>

class $modify(MyPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) return false;
        
        // OWO modu aktif
        Notification::create("OwO Gameplay Generator aktif! >.<", NotificationIcon::Success, 2.f)->show();
        
        // Oyuncuyu biraz rastgele zıplat - basit owo gameplay
        this->schedule(0.5f, [this](float) {
            if (m_player1) {
                m_player1->pushButton(PlayerButton::Jump);
                this->runAction(CCSequence::create(
                    CCDelayTime::create(0.05f),
                    CCCallFunc::create(this, callfunc_selector(MyPlayLayer::releaseJump)),
                    nullptr
                ));
            }
        }, "owo-jump"_spr);

        return true;
    }
    
    void releaseJump() {
        if (m_player1) m_player1->releaseButton(PlayerButton::Jump);
    }
};
