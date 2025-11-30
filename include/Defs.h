#ifndef BLACKJACK_DEFS_H
#define BLACKJACK_DEFS_H

/**
 * 定数
 */
// ブラックジャックの定数
constexpr int DEALER_STAND = 17;
constexpr int BLACKJACK = 21;

/**
 * Enum
 */
// 勝敗
enum class Results {
  DRAW,
  WIN,
  LOSE
};

#endif // BLACKJACK_DEFS_H