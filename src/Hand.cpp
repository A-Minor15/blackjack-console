/**
 * 手札を管理するクラス
 */

#include "Hand.h"

// 手札にカードを追加
void Hand::DrawCard() {
  if (!deck.m_deck.empty())
  {
    // 山札からカードを一枚引き、手札に追加する
    hands.push_back(deck.m_deck.front());

    // 引いたカードを山札から削除
    deck.m_deck.erase(deck.m_deck.begin());
  }
};

// 手札の合計を取得
int Hand::SumHands() const {
  int totalValue = 0;
  int aceCount = 0;

  // 手札の合計を算出
  for (const Card& hand : hands)
  {
    // エースを引いた場合
    if (hand.name == "HA" ||
        hand.name == "DA" ||
        hand.name == "CA" ||
        hand.name == "SA")
    {
      totalValue += 11;
      aceCount++;
    }
    else
    {
      totalValue += hand.value;
    }
  }

  // 合計が21を超えている場合は、Aを1とする
  while (totalValue > 21 &&
         aceCount > 0)
  {
    totalValue -= 10;
    aceCount--;
  }

  // 算出した値を返す
  return totalValue;
};

// 手札を取得
const std::vector<Card>& Hand::GetHands() const
{
  return hands;
};
