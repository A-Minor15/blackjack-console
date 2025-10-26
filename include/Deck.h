/**
 * カードの処理を実行するクラスのヘッダー
 */

// マクロ定義
#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include <string>
#include <chrono>
#include <random>
#include <algorithm>

struct Card {
  std::string name;
  int value;
};

class Deck {
  public:
    // 山札
    std::vector<Card> m_deck;

    // コンストラクター
    Deck();

  private:
    // 山札を生成する関数
    void initializeDeck();

    // 山札をシャッフルする関数
    void shuffleDeck();
};

#endif