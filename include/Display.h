/**
 * 表示処理を実行するクラスのヘッダー
 */

// マクロ定義
#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <string>
#include <iostream>

#include "Hand.h"

class Display {
  public:
    // コンソールにメッセージを出力する関数
    void ShowMessage(const std::string& message) const;

    // コンソールを更新する関数
    void ReloadConsole
    (
      const Hand& dealerHands,
      const Hand& playerHands
    );

    // コンソールにhitかstayかの選択肢を表示する関数
    void SelectHitOrStay
    (
      std::string &playerChoice,
      const Hand &playerHands
    ) const;

    // コンソールに結果を表示
    void DisplayResult
    (
      const int &result
    ) const;
  private:
    // 区切り線を表示
    void displayLine() const;

    // 手札の表示を更新
    void displayHands(
      const std::string& role,
      const Hand& hands
    ) const;
};

#endif