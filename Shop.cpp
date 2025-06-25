#include "Shop.h"
#include <vector>

Shop::Shop()
{
	cout << "상점에 어서오세요!" << endl;
}

void Shop::displayItems()
{
	cout << "1. Health Potion(체력 + 50) : 10 골드" << endl;
	cout << "2. Attack Boost(공격력 + 10) : 15 골드" << endl;
}

void Shop::buyItem(int index, Character* player)
{
	if (index == 1) // 체력 포션 10골드
	{
		const int health_Potion_Price = 10;
		int quantityToBuy;

		cout << "몇 개 구입하시겠습니까? (가격:10 Gold" << "보유 Gold:" << player->getGold() << endl;
		cin >> quantityToBuy;
		if (quantityToBuy <= 0)
		{
			cout << "유효하지 않은 수량입니다. 1개 이상을 입력해주세요" << endl;
			return;
		}
		int totalprice = health_Potion_Price * quantityToBuy;
		if (player->getGold() >= totalprice) // 총 금액과 보유 골드 비교
		{
			// N개만큼 아이템을 지급
			for (int i = 0; i < quantityToBuy; ++i)
			{
				HealthPotion* h = new HealthPotion(); // 각 포션은 새로운 객체로 생성
				player->getItem(h); // 플레이어 인벤토리에 추가

			}
			player->setGold(player->getGold() - totalprice);
			cout << "체력회복 포션 구매!" << endl;
			cout << "남은 골드 : " << player->getGold() << endl;
		}
		else
		{
			cout << "돈이 부족합니다." << endl;
		}
	}
	else if (index == 2) // 공격력 포션 15골드

	{
		const int Attack_Boost_prise = 15;
		int quantityToBuy;
		cout << "몇 개 구입하시겠습니까 ?" << endl;
		cout << "가격:15 Gold" << endl;
		cout << "보유 Gold : " << player->getGold() << endl;
		cin >> quantityToBuy;
		if (quantityToBuy <= 0)
		{
			cout << "유효하지 않은 수량입니다. 1개 이상을 입력해주세요" << endl;
			return;
		}
		int totalprice = Attack_Boost_prise * quantityToBuy;
		if (player->getGold() >= totalprice) // 총 금액과 보유 골드 비교
		{
			// N개만큼 아이템을 지급
			for (int i = 0; i < quantityToBuy; ++i)
			{
				AttackBoost* a = new AttackBoost(); // 각 포션은 새로운 객체로 생성
				player->getItem(a); // 플레이어 인벤토리에 추가

			}
			player->setGold(player->getGold() - totalprice);
			cout << "공격력 증가 포션 구매!" << endl;
			cout << "남은 골드 : " << player->getGold() << endl;
		}
		else
		{
			cout << "돈이 부족합니다." << endl;
		}
	}
}
void Shop::sellItem(int index, Character* player)
{
	if (index >= player->getInventory().size() || index < 0)
	{
		cout << "오류 발생" << endl;
		return;
	}

	if (player->getInventory()[index]->getName() == "HealthPotion")
	{
		player->eraseItem(index);
		player->setGold(player->getGold() + 10);
		cout << "포션 판매!" << endl;
		cout << "현재 골드 : " << player->getGold() << endl;
	}
	else if (player->getInventory()[index]->getName() == "AttackBoost")
	{
		player->eraseItem(index);
		player->setGold(player->getGold() + 15);
		cout << "포션 판매!" << endl;
		cout << "현재 골드 : " << player->getGold() << endl;
	}
}

Shop::~Shop()
{
	cout << "이용해 주셔서 감사합니다~" << endl;
}