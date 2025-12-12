// マクロ定義
#ifndef MESSAGES_H_
#define MESSAGES_H_

namespace Message {
  // フォーマット出力
  constexpr const char* SeparatorLine = "======================================================================";

  // 通常出力
  constexpr const char* PlayerOverScore = "Player: Over Score.";
  constexpr const char* PlayerTurnFinished = "Player's turn is finished.";
  constexpr const char* DealerTurnFinished = "Dealer's turn is finished.";

  // 結果出力
  constexpr const char* ResultWin = "Player WIN!!";
  constexpr const char* ResultLose = "Player LOSE...";
  constexpr const char* ResultDraw = "DRAW";

  // エラー出力
  constexpr const char* ErrorInvalidInput = "Error: Type hit or stay.";
}

#endif // MESSAGES_H_