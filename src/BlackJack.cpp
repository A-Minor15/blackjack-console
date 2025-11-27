/**
 * ブラックジャックの大枠の処理を実行するクラス
 */

#include "BlackJack.h"

// ブラックジャックの定数
constexpr int DEALER_STAND = 17;
constexpr int BLACKJACK = 21;

// 勝敗
enum Results {
  DROW = 0,
  WIN = 1,
  LOSE = 2
};

// 選択肢
enum PlayerChoice {
  STAY = 0, // カードを引かない
  HIT = 1   // カードを引く
};

// コンストラクター
BlackJack::BlackJack()
  : dealerTurnIsOver(false),
    playerTurnIsOver(false),
    deck(),
    display(),
    playerHands(),
    dealerHands()
{}

/**
 * ゲーム処理関数
 */
void BlackJack::ProcessBlackJack() {
  // カード分配フェーズ
  dealCards();

  // プレイヤーのカードの合計がブラックジャック値未満
  if (playerHands.SumHands() < BLACKJACK)
  {
    // プレイヤー行動選択フェーズ
    playerTurn();
  }
  Sleep(2000);

  // ディーラー行動フェーズ
  dealerTurn();

  // 勝敗判定フェーズ
  int result = checkResults();

  // コンソールに結果を表示
  display.DisplayResult(result);
}

/**
 * カード分配フェーズ
 */
void BlackJack::dealCards() {
  // プレイヤーから交互にカードを2枚引く
  playerHands.DrowCard(deck);
  dealerHands.DrowCard(deck);
  playerHands.DrowCard(deck);
  dealerHands.DrowCard(deck);

  // 引いた結果をコンソールに表示
  display.ReloadConsole(dealerHands, playerHands);
};

/**
 * プレイヤー行動選択フェーズ
 */
void BlackJack::playerTurn() {
  // BLACKJACK以上となるまで回す
  while (playerHands.SumHands() < BLACKJACK)
  {
    // 入力値を格納する変数
    std::string playerChoice;
    // ・プレイヤーの選択を促す(hit, stay)
    display.SelectHitOrStay(playerChoice, playerHands);

    // hitを選択
    if (playerChoice == "hit")
    {
      // プレイヤーがカードを引く
      playerHands.DrowCard(deck);

      // コンソールの表示を更新
      display.ReloadConsole(dealerHands, playerHands);
    }
    // stayを選択
    else if (playerChoice == "stay")
    {
      break;
    }
    else
    {
      display.ShowMessage("Error: Type hit or stay.");
    }
  }

  // プレイヤーの手札の合計が21を超えている場合
  if (playerHands.SumHands() > BLACKJACK)
  {
    display.ShowMessage("Player: Over Score.");
  }

  display.ShowMessage("Player's turn is finished.");

  // プレイヤーの行動終了フラグtrue
  playerTurnIsOver = true;

  Sleep(2000);

  // 引いた結果をコンソールに表示
  display.ReloadConsole(dealerHands, playerHands);
};

/**
 * ディーラー行動フェーズ
 */
void BlackJack::dealerTurn() {
  // ディーラーのカードの合計がDEALER_STAND以上となるまで回す
  while (dealerHands.SumHands() < DEALER_STAND)
  {
    // カードを引く
    dealerHands.DrowCard(deck);

    Sleep(2000);

    // コンソールの表示を更新
    display.ReloadConsole(dealerHands, playerHands);
  }

  // ディーラーの行動終了フラグtrue
  dealerTurnIsOver = true;

  display.ShowMessage("Dealer's turn is finished.");

  Sleep(2000);

  // 引いた結果をコンソールに表示
  display.ReloadConsole(dealerHands, playerHands);
};

/**
 * 勝敗判定フェーズ
 */
int BlackJack::checkResults() const {
  int playerSumHands = playerHands.SumHands();
  int dealerSumHands = dealerHands.SumHands();

  // プレイヤーとディーラーのどちらも21を超える
  if (playerSumHands > BLACKJACK &&
      dealerSumHands > BLACKJACK)
  {
    // 引き分け
    return DROW;
  }
  // プレイヤーのみ21を超える
  if (playerSumHands > BLACKJACK)
  {
    return LOSE;
  }
  // ディーラーのみ21を超える
  if (dealerSumHands > BLACKJACK)
  {
    return WIN;
  }
  if (playerSumHands > dealerSumHands)
  {
    return WIN;
  }
  if (playerSumHands < dealerSumHands)
  {
    return LOSE;
  }

  // 同点
  return DROW;
};