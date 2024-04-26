# Fireboy and Watergirl - nhuhieu193
- Demo game: [https://www.youtube.com/watch?v=KdkXpCEkYC4](https://www.youtube.com/watch?v=KdkXpCEkYC4)

# Giới thiệu
Lửa và Nước là tựa game đem đến cho người chơi một cấu trúc gameplay độc đáo và thú vị, với một phong cách chơi đặc biệt. Trong trò chơi, người chơi sẽ có cơ hội điều khiển hai nhân vật chính thông qua việc tương tác với môi trường, họ sẽ phải giải quyết các câu đố và vượt qua màn chơi với nhiều độ khó khác nhau.

 - [0. Cách tải Game](#0-Cách-tải-game)
 - [1. Các thành phần trong game](#1-Các-thành-phần-trong-game)
 - [2. Bắt đầu chơi](#2-Bắt-đầu-chơi)
 - [3. Cách chơi](#3-Cách-chơi)
 - [4. Chiến thắng và thất bại](#4-Chiến-thắng-và-thất-bại)
 - [5. Về source code của Game](#5-Về-source-code-của-Game)

# 0. Cách tải game

**Bước 1:** Clone repo này về hoặc chọn Code -> Download Zip

**Bước 2:** Cài codeblocks-20.03mingw

**Bước 3:** Chạy file **Fireboy_and_Watergirl.exe** hoặc mở file **Fireboy_and_Watergirl.cbp** và chạy game bằng phím **F9**

# 1. Các thành phần trong game
- **Người chơi**:
    * Fireboy: nhân vật cậu bé lửa
      
      ![image](https://github.com/nhuhieu193/fireboy_and_watergirl/assets/158837114/692e859a-4738-48cc-aa30-c0ff7cff8a67)
      
    * Watergirl: nhân vật cô bé nước
      
      ![image](https://github.com/nhuhieu193/fireboy_and_watergirl/assets/158837114/ba4fe0d5-473c-458e-a8ad-f2fae7d0fee0)
- **Các chướng ngại vật khi chơi**:
    * **Nước** : Chỉ có cô bé nước mới có thể đi qua
      
      ![image](https://github.com/nhuhieu193/fireboy_and_watergirl/assets/158837114/e7d3fd99-4ce5-4c38-9f5d-33ca2e594cb1)

    * **Dung nham** : Chỉ có cậu bé lửa mới có thể đi qua
      
      ![image](https://github.com/nhuhieu193/fireboy_and_watergirl/assets/158837114/074fd28f-38d3-4083-99a9-f4ec19bf1f9b)

    * **Chất nhầy xanh** : Cả 2 đều sẽ bị tiêu diệt nếu không may rơi vào
      
      ![image](https://github.com/nhuhieu193/fireboy_and_watergirl/assets/158837114/de5627c3-31eb-4e91-8794-d80b7742a1e7)

- **Hệ thống các thanh trượt, sử dụng các nút cùng màu để điều khiển chúng**
   + **Lưu ý :** Các thanh trượt này có thể bị chặn nếu trên đường chúng dịch chuyển, có va chạm với bất kỳ nhân vật nào.
  
  ![image](https://github.com/nhuhieu193/fireboy_and_watergirl/assets/158837114/d188bc4b-94ad-40d6-a1fd-7f1976a3a40f)

      
# 2. Bắt đầu chơi
 - Click chuột vào nút **Play** để bắt đầu chơi
   
![Image](https://github.com/nhuhieu193/fireboy_and_watergirl/blob/master/Fireboy_and_Watergirl/media/IntroBackground.png)

# 3. Cách chơi
- Game Fireboy and Watergirl là **multiplayer game**:
     * **Fireboy**: Dùng các **phím mũi tên** để di chuyển
     * **Watergirl**: Dùng các **phím W,A,D** để di chuyển
- Đây là tựa game 2 người chơi, cần có sự phối hợp ăn ý và chiến thuật phù hợp để giúp cả 2 nhân vật đến được cảnh cửa để qua màn.

  ![image](https://github.com/nhuhieu193/fireboy_and_watergirl/assets/158837114/4d1b58e7-c4b1-437f-a522-21e5fa7fd2ea)


# 4. Chiến thắng và thất bại
- **Chiến thắng** : Bạn sẽ chiến thắng nếu điều khiển cả 2 nhân vật qua được tất cả các màn chơi của game.

  ![Image](https://github.com/nhuhieu193/fireboy_and_watergirl/blob/master/Fireboy_and_Watergirl/media/youwin.png)
- **Thất bại**: Bạn sẽ thất bại nếu 1 trong 2 nhân vật bị rơi vào nơi không phù hợp với thuộc tính của nhân vật
     * Cậu bé lửa rơi vào nước
     * Cô bé nước rơi vào dung nham
     * Hoặc một trong hai rơi vào chất nhầy xanh

<p align="center">
<strong>Các nhân vật không bị tiêu diệt trừ khi ở trong đúng nơi cùng thuộc tính</strong>
</p>
  
  ![image](https://github.com/nhuhieu193/fireboy_and_watergirl/assets/158837114/21e8097e-d6fd-44c1-a577-20ff0293f2de)

</div>
Khi thất bại, bạn cần phải chơi lại màn đó từ đầu.
 
# 5. Về source code của Game
- File main, Engine bao gồm logic game chính:
   + Init()
   + Events()
   + Update()
   + Render()
   + Clean()
  </div>
  Và bên trong gọi đến những đối tượng khác.
- Các File đối tượng:
   * Fireboy : Chứa các thuộc tính và các hàm cần thiết cho cậu bé lửa
   * Watergirl: Chứa các thuộc tính và các hàm cần thiết của cô bé nước
   * FireboyDoor / WatergirlDoor : Cửa qua màn của 2 nhân vật
   * Map : Chứa mọi thứ liên quan đến 1 màn chơi
      + Các tile gạch
      + Nước
      + Dung nham
      + Chất nhầy xanh
      + Các thanh trượt và hệ nút bấm
   * Menu : Quản lý những thứ liên quan đến các trạng thái của game
      + Pause Game
      + Level Passed
      + Game Over
   * Music : Quản lý âm thanh
- Các File chức năng của Game:
  * Timer : Điều khiển FPS của Game
  * EvenHandler : Nhận Input
  * RigidBody : Các trạng thái vật lý của nhân vật
      + Vị trí
      + Gia tốc
      + Vận tốc
      + ...
  * Texture : Quản lý toàn bộ texture của Game
  * Transform : Quản lý việc di chuyển trong nhân vật, bao gồm cả check collision
  * Các File riêng quản lý từng màn chơi:
      + BackgroundStage
      + GameStage1
      + GameStage2
      + GameStage3
      + GameStage4
      + GameStage5
- Ngoài ra các folder các lưu các assets của Game:
   + Media : Lưu tất cả ảnh hoặc sprite sheet cần dùng
   + Audio : Lưu các âm thanh
   + Maplevel : Lưu các tài nguyên cần load khi bước vào mỗi màn chơi
   + Fonts : Lưu các fonts cần thiết để viết các tutorial trong Game

