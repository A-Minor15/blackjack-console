# ----------------------------------------
# 1. 変数の定義
# ----------------------------------------
# C++コンパイラとして g++ を指定
CXX = g++
# 最終的な実行ファイル名
TARGET = main
# ソースファイルの場所
SOURCE = src/main.cpp src/BlackJack.cpp src/Deck.cpp src/Display.cpp src/Hand.cpp
# ヘッダファイルのディレクトリ
INCLUDE_DIR = include

# -I を使ってインクルードパスを指定
CXXFLAGS = -I$(INCLUDE_DIR)

# ----------------------------------------
# 2. ターゲットの定義 (make と実行される部分)
# ----------------------------------------
# 最終的なターゲット（実行ファイル）の作成
$(TARGET): $(SOURCE)
	$(CXX) $(SOURCE) -o $(TARGET) $(CXXFLAGS)

# ----------------------------------------
# 3. クリーンアップ (make clean で実行)
# ----------------------------------------
# 生成された実行ファイルや中間ファイルを削除
clean:
	rm -f $(TARGET)

# --- 静的解析ターゲット ---
check:
	cppcheck --enable=all --std=c++11 --inconclusive --quiet . $(CXXFLAGS)