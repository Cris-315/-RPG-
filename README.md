# 專題名稱：文字回合制 RPG 遊戲

## 一、組別資訊
- **組別：** 第 14 組
- **系級班級：** 資工 1B

## 二、組員資訊
- **謝國省 (B2233890)**
- **黃金竹 (B3235471)**
- **魏玉皇維 (B2325250)**  

## 三、小專題題目
- 文字回合制 RPG 遊戲

## 四、系統功能說明
本專題是用 C++ 語言做的文字回合制 RPG 遊戲，主要使用物件導向程式設計（OOP）來開發。

玩家會扮演主角 **Hero**，在一個有很多未知和危險的世界裡探索。透過回合制戰鬥，玩家要好好使用普通攻擊 (Attack)、喝藥水（Drink Potion）、治療（Heal）和各種技能，來打敗 **Monster**，並努力活下去。
## 遊戲規則與操作說明

---

**【基本玩法】**  
* 這個遊戲是回合制的文字戰鬥，由玩家（Hero）和怪物（Monster）輪流行動。  
* **勝利條件**：把怪物的 HP 減到 0 以下。  
* **失敗條件**：玩家的 HP 變成 0。

**【玩家回合（Hero Turn）】**  
在終端機輸入對應的數字來選擇要做的事：

1. **Attack（攻擊）**：如果 MP 有 10 或更多，就消耗 10 MP 發動強力攻擊（傷害 20）；如果 MP 不夠，就發動普通攻擊（傷害 6）。  
2. **Heal（回復）**：回復自己 15 點 HP 和 5 點 MP。  
3. **Potion（喝藥水）**：消耗 1 瓶藥水，大幅回復 25 點 HP。（一開始有 3 瓶藥水）

* **注意**：如果輸入錯誤的數字，就會失去這一回合的行動機會！  
* **懲罰**：如果玩家「連續兩回合」沒有攻擊怪物，怪物會生氣，觸發怪物的特殊回血能力！

**【怪物回合（Monster Turn）】**  
* 怪物有 **60%** 的機會發動普通攻擊（造成 18 點傷害）。  
* 怪物有 **40%** 的機會發動特殊技能（造成高達 25 點傷害）。

**【隱藏事件：Teacher Appears!（NPC 系統）】**  
* **觸發條件**：經過偶數回合，而且玩家 HP 低於 50% 時，有 30% 的機會出現。  
* **事件內容**：NPC（Teacher）會突然出現，並隨機出一題關於 C++ 或 OOP 的選擇題。  
* **事件結果**：  
  * **答對**：Teacher 會給獎勵，直接幫玩家回復 HP！  
  * **答錯**：Teacher 會給懲罰，讓怪物回復 HP！

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

## 六、程式如何安裝與執行
### 使用 Visual Studio
1. 先下載這個專案的 ZIP 檔案，然後解壓縮出來。

2. 打開 Visual Studio，選擇 **「建立新的專案」**。
   
   <img width="207" height="42" alt="one" src="https://github.com/user-attachments/assets/69ea307c-6541-49f6-afd3-d1ae93dceedc" />

3. 選擇 **「空專案」**，給它取一個名字，然後點擊建立。
   
   <img width="527" height="97" alt="two" src="https://github.com/user-attachments/assets/8a215ce0-a1f8-465a-8839-ecdc5c386b44" />

4. 在右邊的「方案總管」裡，右鍵點擊 **「原始程式檔」** → **「加入」** → **「現有項目」**。
   
   <img width="1147" height="396" alt="three" src="https://github.com/user-attachments/assets/e95bf487-1d8c-406a-b3d6-d12540f8abe8" />

5. 全選剛才解壓縮的所有 `.cpp` 和 `.h` 檔案，然後加入。

6. 點擊上方 **「本機 Windows 偵錯工具」** 按鈕（或直接按 F5 鍵），遊戲就可以開始玩了！
   
   <img width="232" height="37" alt="four" src="https://github.com/user-attachments/assets/840a9ed6-6ba9-4981-b92a-9ec7d4577b56" />

---

### 附錄：UML 類別圖與運作流程圖

<img width="752" height="784" alt="RPG_UML drawio" src="https://github.com/user-attachments/assets/3b819eec-29a1-4385-b018-725b5f19255b" />

<br>

<img width="754" height="2206" alt="Main Flowchart drawio (2)" src="https://github.com/user-attachments/assets/a7842677-4141-4076-a546-ecc7eebfd115" />
---

## 七、程式畫面截圖

### 1. 遊戲啟動與戰鬥
*(遊戲初始畫面與基礎回合操作)*

<img width="526" height="486" alt="start" src="https://github.com/user-attachments/assets/09f73839-ccf7-48f6-a8cb-53b7c49d6ed2" />
<img width="551" height="962" alt="1 2" src="https://github.com/user-attachments/assets/5950bc65-ce8c-4702-b18a-ae023de2b873" />
<img width="627" height="962" alt="3" src="https://github.com/user-attachments/assets/93271fce-ef0b-4231-a447-435d92a29ea6" />

### 2. 隱藏事件：Teacher Appears!
*(當玩家血量低於50%時觸發的 OOP 知識抽考)*

<img width="467" height="552" alt="teacher" src="https://github.com/user-attachments/assets/e8adb4ed-3ac6-40ae-9942-e421d897a2f1" />
<img width="467" height="575" alt="wrong" src="https://github.com/user-attachments/assets/b27c3450-5494-498e-95f6-d08015d45464" />

### 3. 特殊狀況與遊戲結局
*(包含行動喪失警告、勝利與失敗結算)*

<img width="537" height="482" alt="lose turn" src="https://github.com/user-attachments/assets/b322271a-07a5-4843-bc60-848d9a11870b" />
<img width="581" height="450" alt="end" src="https://github.com/user-attachments/assets/dfa4a0a2-b2d3-4240-8d85-631c01f88caa" />
<img width="515" height="592" alt="win" src="https://github.com/user-attachments/assets/5313539a-32d3-4122-bb4b-8c0b73803d8a" />


## 八、分工資訊
* **謝國省 (組長)：** 負責 main.cpp 遊戲主迴圈、Character 類別設計、NPC 類別設計、GitHub 專案管理。
* **黃金竹 (組員)：** 實負責 Hero 類別設計、技能與 MP 系統。
* **魏玉皇維 (組員)：** 負責 Monster 類別設計、戰鬥傷害計算。
