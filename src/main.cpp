#include <Geode/Geode.hpp>
#include <Geode/modify/MenuGameLayer.hpp>

using namespace geode::prelude;

class $modify(MenuGameLayer) {
	void resetPlayer() {
		auto achievementManager = AchievementManager::sharedState();
		auto playerObject = MenuGameLayer::m_playerObject;
		MenuGameLayer::resetPlayer();

		if (!playerObject->m_isShip && !playerObject->m_isBall && !playerObject->m_isBird && !playerObject->m_isDart && !playerObject->m_isRobot && !playerObject->m_isSpider && !playerObject->m_isSwing)
		{
			if (GameStatsManager::sharedState()->getStat("9") >= 1000)
			{
				if (!achievementManager->isAchievementEarned("geometry.ach.secret11"))
					playerObject->updatePlayerFrame(55);
				else if (!achievementManager->isAchievementEarned("geometry.ach.secret12"))
					playerObject->updatePlayerFrame(50);
			}
		}
	}
};