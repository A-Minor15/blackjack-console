/**
 * 表示処理を実行するクラス
 */

#include "Display.h"
#include <conio.h>

// コンソールにメッセージを出力する関数
void Display::ShowMessage
(
  const std::string& message
) const
{
  std::cout << message << std::endl;
};

// コンソールを更新する関数
void Display::ReloadConsole
(
  const Hand& dealerHands,
  const Hand& playerHands
)
{
  system("cls");

  // 上区切り線を表示
  displayLine();

  // ディーラーの手札を表示
  displayHands("Dealer", dealerHands);

  // 中間線を表示
  displayLine();

  // プレイヤーの手札を表示
  displayHands("Player", playerHands);

  // 下区切り線を表示
  displayLine();
};

// コンソールにhitかstayかの選択肢を表示する関数
void Display::SelectHitOrStay
(
  std::string &playerChoice,
  const Hand &playerHands
) const
{
  // コンソールにhitかstayかを問う文言を出力する
  std::cout << "sum: " << playerHands.SumHands() << ", hit or stay ? /";

  // プレイヤーの入力をplayerChoiceに格納
  std::getline(std::cin, playerChoice);
}

// コンソールに結果を表示する関数
void Display::DisplayResult
(
  const Results &result
) const
{
  // 引数に応じて、結果をコンソールに結果を出力する
  if (result == Results::WIN)
  {
    std::cout << Message::ResultWin << std::endl;
  }
  else if (result == Results::LOSE)
  {
    std::cout << Message::ResultLose << std::endl;
  }
  else if (result == Results::DRAW)
  {
    std::cout << Message::ResultDraw << std::endl;
  }
}

// 区切り線を表示
void Display::displayLine() const
{
  // コンソールに区切り線を出力
  std::cout << Message::SeparatorLine << std::endl;
}

// 手札を表示
void Display::displayHands
(
  const std::string& role,
  const Hand& hands
) const
{
  std::cout << role << "(" << hands.SumHands() << ")" <<  ": ";

  // 手札を空白区切りで表示
  for (const Card& hand : hands.GetHands())
  {
    std::cout << hand.name << " ";
  }

  std::cout << std::endl;
}
