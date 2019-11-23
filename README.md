# P2P_ChordNode
## 목차
* 프로그램 설명
* 포함 목록
* 동작 과정
* 기능 소개
* 예
* 오류 해결법
* System Sequence Diagram
* 프로그램 테스트
## 프로그램 설명
위 프로그램은 ChordNode를 이용한 P2P 네트워크 입니다. 사용 기능은 아래에서 설명하겠습니다.
## 포함 목록
다운로드 목록에는 다음과 같은 디렉토리와 파일이 있으며 공통 에셋을 논리적으로 그룹화하고 유사 및 축소 변형을 모두 제공합니다.  
볼 수 있는 목록:

* P2P_ChordNode
   * P2P_ChordNode
      * ChordNode.c
      * P2P_ChordNode.vcsproj
      * P2P_ChordNode.vcxproj.filters
   * P2P_ChordNode.sln

## 동작 과정
1. Clone the repo: `git clone https://github.com/LeeKiJong/P2P_ChordNode.git` 
2. Open the 2+ CMD Prompt
3. Node cmd: `location.../ChordNode 192.168.0.1 <Port>`
4. Function Use
* Node Join: `j` - `Helper Node IP`
* Node Leave: `l`
* File Add: `a` - `File Name`
* File Delete: `d` - `File Name`
* File Download: `s` - `File Name`
* View Finger: `f`
* View Info: `i`
* Toggle Mute Mode: `m`
* View Help Msg: `h`
* Program Quit: `q`

## 기능 소개
1.  (c)reate: Create the chord network
2.  (j)oin  : Join the chord network
3.  (l)eave : Leave the chord network
4.  (a)dd   : Add a file to the network
5.  (d)elete: Delete a file to the network
6.  (s)earch: File search and download
7.  (f)inger: Show the finger table
8.  (i)nfo  : Show the node information
9.  (m)ute  : Toggle the silent mode
10. (h)elp  : Show the help message
11. (q)uit  : Quit the program

## 예
1.  Node A: Network Create
2.  Node B: Network Join
3.  Node C: Network Join
4.  Node A: File1 Add
5.  Node A: File2 Add
6.  Node B: File3 Add
7.  Node C: File1 Download
8.  Node B: File2 Download
9.  Node A: File3 Download
10. Node C: File4 Add
11. Node D: Network Join
12. Node D: File5 Add
13. Node D: File4 Download
14. Node A: File1 Delete
15. Node C: Network Leave  
**`위의 실행 프로세스가 오류없이 진행되면 정상 작동으로 볼 수 있습니다.`**

## 오류 해결법
* 강제 종료: 네트워크 지연으로 인한 메시지 핑퐁 오류  `재시작 또는 재부팅`
* 음소거 모드 오류: 메시지 출력으로 인해 Ping-pong 메시지 전송 오류가 발생. 코드 문제이거나 메시지 전달 문제인 경우 해결할 수 없습니다.
* 파일 다운로드 오류: txt 파일은 다운로드 가능하나 hwp 파일은 아직 구현되지않음

## System Sequence Diagram
![image](https://user-images.githubusercontent.com/52438368/67140706-32a2ed80-f298-11e9-8a65-e8d2bc4be1e6.png)
![image](https://user-images.githubusercontent.com/52438368/67140708-39c9fb80-f298-11e9-8308-d13588047c4f.png)
![image](https://user-images.githubusercontent.com/52438368/67140718-523a1600-f298-11e9-9206-df40a8f1a4ba.png)

## 프로그램 테스트
![image](https://user-images.githubusercontent.com/52438368/67140773-f7ed8500-f298-11e9-904d-ffcde4eda4f5.png)
![image](https://user-images.githubusercontent.com/52438368/67140781-08056480-f299-11e9-9507-2d36153ebc84.png)
![image](https://user-images.githubusercontent.com/52438368/67140785-0f2c7280-f299-11e9-8302-ef4dc5a7ecb2.png)
![image](https://user-images.githubusercontent.com/52438368/67140791-1f445200-f299-11e9-9c19-f0b91e2c9fd6.png)
![image](https://user-images.githubusercontent.com/52438368/67140796-29fee700-f299-11e9-88d7-4d97090099a9.png)
