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

**Bước 3:** Thêm các file SDL2.dll, SDL2_image.dll, SDL2_mixer.dll, SDL2_ttf.dll vào thư mục gốc.

**Bước 4:** Chạy file **Fireboy_and_Watergirl.exe** hoặc mở file **Fireboy_and_Watergirl.cbp** và chạy game bằng phím **F9**

# 1. Các thành phần trong game
- Người chơi:
    * Fireboy: nhân vật cậu bé lửa
    * Watergirl: nhân vật cô bé nước
- Các thành phần khác:
    * Nước
    * Dung nham
    * Chất nhầy xanh
      
# 2. Bắt đầu chơi

![Image](https://github.com/nhuhieu193/fireboy_and_watergirl/blob/master/Fireboy_and_Watergirl/media/IntroBackground.png)

# 3. Cách chơi
- Game Fireboy and Watergirl là multiplayer game:
     * Fireboy: Dùng các phím mũi tên để di chuyển
     * Watergirl: Dùng các phím W,A,D để di chuyển
- Đây là tựa game 2 người chơi, cần có sự phối hợp ăn ý và chiến thuật phù hợp để giúp cả 2 nhân vật đến được cảnh cửa để qua màn. 

# 4. Chiến thắng và thất bại
- Chiến thắng: Bạn sẽ chiến thắng nếu điều khiển cả 2 nhân vật qua được tất cả các màn chơi của game.
- Thất bại: Bạn sẽ thất bại nếu 1 trong 2 nhân vật bị rơi vào nơi khác thuộc tính
     * Cậu bé lửa rơi vào nước
     * Cô bé nước rơi vào dung nham
     * Hoặc một trong hai rơi vào chất nhầy xanh
</div>
Khi thất bại, bạn cần phải chơi lại màn đó từ đầu.
 
# 5. Về source code của Game

