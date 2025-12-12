/**
 * ブラックジャックの大枠の処理を実行するクラスのヘッダー
 */

// マクロ定義
#ifndef BLACKJACK_H_
#define BLACKJACK_H_

// include
#include <string>
#include <vector>
#include <iostream>
#include <windows.h>
#include "Hand.h"
#include "Deck.h"
#include "Display.h"
#include "Defs.h"
#include "Messages.h"

class BlackJack {

  public:
    // コンストラクター
    BlackJack();

    // ゲーム処理関数
    void ProcessBlackJack();

  private:
    // ・ディーラーの行動終了フラグ
    bool dealerTurnIsOver;
    // ・プレイヤーの行動終了フラグ
    bool playerTurnIsOver;

    // オブジェクトの生成
    Deck deck;
    Display display;
    Hand playerHands;
    Hand dealerHands;

    // カード分配フェーズ
    void dealCards();

    // プレイヤー行動選択フェーズ
    void playerTurn();

    // ディーラー行動フェーズ
    void dealerTurn();

    // 勝敗判定フェーズ
    Results checkResults() const;

    // ブラックジャックオーバー判定
    bool judgeOverBlackJack
    (
      Hand hands
    );
};

#endif