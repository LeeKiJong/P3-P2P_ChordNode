# P2P_ChordNode
## Table of contents
* What's included
* Operation process
* Functional Introduction
* Error solution
## What's included
Within the download you'll find the following directories and files, logically grouping common assets and providing both complied and minified variations. You'll see something like this:

* HomePage_DB/
   * arweapon.php  
   * arweapon_register.php  
   * board.php  
   * change.php  
   * comment_update.php  
   * comment_view.php  
   * dbconfig.php  
   * delete.php   
   * delete_update.php    
   * index.php   
   * info_change.php    
   * keyboard.html  
   * leave_check.php   
   * login_check.php   
   * logout.php   
   * main.html   
   * map.html   
   * member_leave.php    
   * register.php    
   * register_update.php   
   * selectword.php   
   * srweapon.php    
   * srweapon_register.php  
   * view.php   
   * weapon.php    
   * weapon_register.php  
   * word.php  
   * write.php  
   * write_update.php   
   * assets.zip  
      * css/   
      * fonts/  
      * js/  
      * sass/  
   * images.zip  
      * ...   
   * 실행화면.mp4  
   * 테이블 생성.txt  

## Operation process
1. Clone the repo: `git clone https://github.com/LeeKiJong/Chatting_server.git` 
2. Open the 2+ CMD Prompt
3. server cmd: `location.../Server <Port>`
4. Client cmd: `location.../Client <IP> <Port> <ID>`

## Functional Introduction
1. Whisper Function: `/to <ID> <Msg>`
2. User List Function: `/list`
3. file Send Function: `/fileto <ID> <file name>`

## Error solution
80 Port Be in Use:
Start menu - All apps - Windows systems - Control Panel - Remove programs - Windows features on/off
![80 port](https://user-images.githubusercontent.com/52438368/65368091-eeabd100-dc76-11e9-8af6-8eb6cc8c3b99.png)
