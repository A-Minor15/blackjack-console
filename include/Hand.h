/**
 * 手札を管理するクラスのヘッダー
 */

// マクロ定義
#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <string>

#include "Deck.h"

class Hand {
  public:
    // 手札にカードを追加
    void DrowCard
    (
      Deck& deck
    );

    // 手札の合計を取得
    int SumHands() const;

    // 手札を取得
    const std::vector<Card>& GetHands() const;
  private:
    // 手札
    std::vector<Card> hands;
};

#endif