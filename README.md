# 專題名稱：文字回合制 RPG 遊戲

## 一、組別資訊
- **組別：** 第 14 組
- **系級班級：** 資工 1B

## 二、組員資訊
- **組長：** 謝國省 (B2233890)  
- **組員：** 黃金竹 (B3235471)  
- **組員：** 魏玉皇維 (B2325250)  

## 三、小專題題目
- 文字回合制 RPG 遊戲

## 四、系統功能說明
本專題是用 C++ 語言做的文字回合制 RPG 遊戲，主要使用物件導向程式設計（OOP）來開發。

玩家會扮演主角 **Hero**，在一個有很多未知和危險的世界裡探索。透過回合制戰鬥，玩家要好好使用普通攻擊 (Attack)、喝藥水（Drink Potion）、治療（Heal）和各種技能，來打敗 **Monster**，並努力活下去。

## 五、程式介紹與架構
這個系統分成很多獨立的檔案來開發，並好好使用了物件導向程式設計（OOP）的三個重要特性：

1. **主要類別說明：**
   - `Character`（基礎類別）：這是角色基礎類別，把 `name`、`hp`、`maxHP` 設為 `protected`，提供 `attack()`、`takeDamage()` 等大家都能用的功能。
   - `Hero`（繼承類別）：從 `Character` 繼承而來，是玩家主角。裡面有 `mp` 和 `potion`（private），還增加了 `heal()` 和 `drinkPotion()` 等玩家專用的功能。
   - `Monster`（繼承類別）：從 `Character` 繼承而來，是敵人。有自己的 `healMonster()` 回血功能，和 40% 機率會用的 `specialSkill()` 特殊攻擊。
   - `NPC`：獨立的類別，負責遊戲中的隨機事件（Teacher Appears）。用 `vector` 來存很多選擇題和答案，透過 `askQuestion(Hero, Monster)` 跟角色互動，並改變戰鬥情況。

2. **OOP 特性應用：**
   - **封裝（Encapsulation）：** 把角色的血量、魔力、藥水數量等重要資料設為 `private` 或 `protected`，只能透過 `public` 函式來使用，這樣可以保護資料安全。
   - **繼承（Inheritance）：** `Hero` 和 `Monster` 都從 `Character` 類別繼承，這樣可以共用基礎的屬性，減少重複寫程式碼。
   - **多型（Polymorphism）：** 在 `Character` 類別裡宣告純虛擬函式 `virtual int attack() = 0;`，然後在 `Hero` 和 `Monster` 裡分別實作自己的攻擊方式，這樣可以讓程式更靈活。

## 六、程式如何安裝執行 (圖文講解)
1. 於本專案 GitHub 頁面，點擊綠色的 `<> Code` 按鈕。
2. 點擊 **Download ZIP** 進行下載。
3. 將下載的檔案解壓縮至電腦中。
4. 開啟 **Visual Studio** (或 VS Code)，選擇「開啟本機資料夾」並選取剛剛解壓縮的資料夾。
5. 在畫面中找到並開啟 `main.cpp`。
6. 點擊上方的「執行 (Run)」按鈕即可開始遊玩！

*(hình ảnh)*

### 附錄：UML 類別圖與運作流程圖
<img width="752" height="784" alt="RPG_UML drawio" src="https://github.com/user-attachments/assets/3b819eec-29a1-4385-b018-725b5f19255b" />

<img width="754" height="2206" alt="Main Flowchart drawio (2)" src="https://github.com/user-attachments/assets/a7842677-4141-4076-a546-ecc7eebfd115" />

---

## 七、程式畫面截圖
<img width="526" height="486" alt="start" src="https://github.com/user-attachments/assets/09f73839-ccf7-48f6-a8cb-53b7c49d6ed2" />
<img width="537" height="482" alt="lose turn" src="https://github.com/user-attachments/assets/b322271a-07a5-4843-bc60-848d9a11870b" />
<img width="551" height="962" alt="1 2" src="https://github.com/user-attachments/assets/5950bc65-ce8c-4702-b18a-ae023de2b873" />
<img width="627" height="962" alt="3 " src="https://github.com/user-attachments/assets/93271fce-ef0b-4231-a447-435d92a29ea6" />
<img width="467" height="552" alt="teacher" src="https://github.com/user-attachments/assets/e8adb4ed-3ac6-40ae-9942-e421d897a2f1" />
<img width="467" height="575" alt="wrong" src="https://github.com/user-attachments/assets/b27c3450-5494-498e-95f6-d08015d45464" />
<img width="581" height="450" alt="end" src="https://github.com/user-attachments/assets/dfa4a0a2-b2d3-4240-8d85-631c01f88caa" />
<img width="515" height="592" alt="win" src="https://github.com/user-attachments/assets/5313539a-32d3-4122-bb4b-8c0b73803d8a" />

## 八、分工資訊
* **謝國省 (Harry - 組長)：** 撰寫 `main.cpp` 遊戲主迴圈、設計 `Character` 基礎類別、GitHub 專案管理與版本控制。
* **黃金竹 (組員)：** 實作 `Hero` 類別、設計主角技能與 MP 系統、玩家操作功能實作。
* **魏玉皇維 (組員)：** 實作 `Monster` 類別、設計怪物 AI 邏輯、戰鬥傷害計算系統。
