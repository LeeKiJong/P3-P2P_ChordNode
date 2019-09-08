#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment( lib, "ws2_32.lib")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <process.h> 

#define FNameMax 32       /* Max length of File Name */
#define FileMax  32 /* Max number of Files */
#define baseM 6 /* base number */ 
#define ringSize 64 /* ringSize = 2^baseM */
#define fBufSize 20000 /* file buffer size */
#define LENGTH 512
typedef struct {
	/* Node Info Type Structure */
	int ID;                 /* ID */
	struct sockaddr_in addrInfo;  /* Socket address */
} nodeInfoType;

typedef struct {
	/* File Type Structure */
	char Name[FNameMax]; /* File Name */
	int  Key; /* File Key */
	nodeInfoType owner; /* Owner's Node */
	nodeInfoType refOwner; /* Ref Owner's Node */
} fileRefType;

typedef struct {
	/* Global Information of Current Files */
	unsigned int fileNum;  /* Number of files */
	fileRefType  fileRef[FileMax]; /* The Number of Current Files */
} fileInfoType;

typedef struct {
	/* Finger Table Structure */
	nodeInfoType Pre;   /* Predecessor pointer */
	nodeInfoType finger[baseM]; /* Fingers (array of pointers) */
} fingerInfoType;

typedef struct {
	/* Chord Information Structure */
	fileInfoType   FRefInfo; /* File Ref Own Information */
	fingerInfoType fingerInfo;  /* Finger Table Information */
} chordInfoType;

typedef struct {
	/* Node Structure */
	nodeInfoType  nodeInfo;   /* Node's IPv4 Address */
	fileInfoType  fileInfo;   /* File Own Information */
	chordInfoType chordInfo;  /* Chord Data Information */
} nodeType;

typedef struct {
	unsigned short msgID;   // message ID 
	unsigned short msgType; // message type (0: request, 1: response) 
	nodeInfoType   nodeInfo;// node address info 
	short       moreInfo; // more info 
	fileRefType    fileInfo; // file (reference) info
	unsigned int   bodySize; // body size in Bytes
} chordHeaderType;           // CHORD message header type



unsigned int str_hash(const char*);
void printmenu();
int modIn(int modN, int targNum, int range1, int range2, int leftmode, int rightmode);
int twoPow(int power);

int modMinus(int modN, int minuend, int subtrand);

int modPlus(int modN, int addend1, int addend2);
void fileSender(void*);
void fileReceiver(void*);
void procRecvMsg(void*);
void procPP(void*);
void procFF(void*);


nodeType myNode = { 0 };  // node information -> global variable 
SOCKET rqSock, rpSock, flSock, frSock, fsSock, ffSock, ppSock;       // when multiplexing is used HANDLE hMutex;

int exitFlag = 0;
HANDLE hMutex;
HANDLE hThread[3];

int mute = 0;

char filename[FNameMax];
int main(int argc, char* argv[])
{
	WSADATA wsaData;
	int i;
	int addrlen = sizeof(struct sockaddr);
	int createOK = 0;	//create 확인
	int joinOK = 0;		//join 확인
	char select;		//입력한 메뉴를 저장할 변수
	int optVal = 5000;  // 5 seconds
	char Sock_addr[21] = { 0 };//자신 소켓의 정보를 저장할 문자열 배열
	char helpIP[16] = { 0 };	//헬프노드의 IP를 저장할 문자열 배열
	int helpPort;				//헬프노드의 포트번호
	int fkey;					//파일의 키값을 저장할 변수
	int retVal; //오류 검출 변수

	chordHeaderType helpMsg, resMsg;
	nodeInfoType succ, pred, helper, refOwner;

	helpMsg.nodeInfo.addrInfo.sin_family = AF_INET;
	resMsg.nodeInfo.addrInfo.sin_family = AF_INET;


	printf("*****************************************************************\n");
	printf("*         DHT-Based P2P Protocol (CHORD) Node Controller        *\n");
	printf("*                   Ver. 0.1     Sep. 8, 2019                   *\n");
	printf("*                       (c) Lee Ki jong                         *\n");
	printf("*****************************************************************\n");

	myNode.nodeInfo.addrInfo.sin_family = AF_INET;

	if (argc != 3) {
		printf("[ERROR] Usage : %s <IP> <port>\n", argv[0]);
		printf("프로그램을 종료합니다.");
		exit(1);
	}

	if (inet_addr(argv[1]) != INADDR_NONE)
		myNode.nodeInfo.addrInfo.sin_addr.s_addr = inet_addr(argv[1]);
	else {
		printf("[ERROR] IP 주소를 잘못 입력하였습니다.");
		printf("프로그램을 종료합니다.");
		exit(1);
	}



	if (atoi(argv[2]) > 65535 || atoi(argv[2]) < 49152) {
		printf("[ERROR] 포트 번호는 49152 <= port <= 65535 로 적어주세요.\n");
		printf("프로그램을 종료합니다.");
		exit(1);
	}
	else
		myNode.nodeInfo.addrInfo.sin_port = htons(atoi(argv[2]));

	strcpy(Sock_addr, argv[2]);
	strcat(Sock_addr, argv[1]);
	myNode.nodeInfo.ID = str_hash(Sock_addr);

	printf(">>> Welcome to ChordNode Program!\n");

	printf(">>> Your IP address: %s, Port No: %s, ID: %d\n", argv[1], argv[2], myNode.nodeInfo.ID);

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		printf("\nCHORD> 초기화를 실패하였습니다.\n\n");


	while (1) {
		do {
			printmenu();

			scanf("%s", &select);
			switch (select) {

			case 'c':
				break;
			case 'j':
				break;
			case 'l':
				break;
			case 'a':
				break;
			case 'd':
				break;
			case 's':
				break;
			case 'f':
				break;
			case 'i':
				break;
			case 'm':
				break;
			case 'h':
				break;
			}

		} while (select != 'q');
		if (select == 'q') {
			printf("\nCHORD> Chord Program Exit!!\n");
			exit(1);
		}
	}
	return 0;
}


static const unsigned char sTable[256] =
{
	0xa3,0xd7,0x09,0x83,0xf8,0x48,0xf6,0xf4,0xb3,0x21,0x15,0x78,0x99,0xb1,0xaf,0xf9,
	0xe7,0x2d,0x4d,0x8a,0xce,0x4c,0xca,0x2e,0x52,0x95,0xd9,0x1e,0x4e,0x38,0x44,0x28,
	0x0a,0xdf,0x02,0xa0,0x17,0xf1,0x60,0x68,0x12,0xb7,0x7a,0xc3,0xe9,0xfa,0x3d,0x53,
	0x96,0x84,0x6b,0xba,0xf2,0x63,0x9a,0x19,0x7c,0xae,0xe5,0xf5,0xf7,0x16,0x6a,0xa2,
	0x39,0xb6,0x7b,0x0f,0xc1,0x93,0x81,0x1b,0xee,0xb4,0x1a,0xea,0xd0,0x91,0x2f,0xb8,
	0x55,0xb9,0xda,0x85,0x3f,0x41,0xbf,0xe0,0x5a,0x58,0x80,0x5f,0x66,0x0b,0xd8,0x90,
	0x35,0xd5,0xc0,0xa7,0x33,0x06,0x65,0x69,0x45,0x00,0x94,0x56,0x6d,0x98,0x9b,0x76,
	0x97,0xfc,0xb2,0xc2,0xb0,0xfe,0xdb,0x20,0xe1,0xeb,0xd6,0xe4,0xdd,0x47,0x4a,0x1d,
	0x42,0xed,0x9e,0x6e,0x49,0x3c,0xcd,0x43,0x27,0xd2,0x07,0xd4,0xde,0xc7,0x67,0x18,
	0x89,0xcb,0x30,0x1f,0x8d,0xc6,0x8f,0xaa,0xc8,0x74,0xdc,0xc9,0x5d,0x5c,0x31,0xa4,
	0x70,0x88,0x61,0x2c,0x9f,0x0d,0x2b,0x87,0x50,0x82,0x54,0x64,0x26,0x7d,0x03,0x40,
	0x34,0x4b,0x1c,0x73,0xd1,0xc4,0xfd,0x3b,0xcc,0xfb,0x7f,0xab,0xe6,0x3e,0x5b,0xa5,
	0xad,0x04,0x23,0x9c,0x14,0x51,0x22,0xf0,0x29,0x79,0x71,0x7e,0xff,0x8c,0x0e,0xe2,
	0x0c,0xef,0xbc,0x72,0x75,0x6f,0x37,0xa1,0xec,0xd3,0x8e,0x62,0x8b,0x86,0x10,0xe8,
	0x08,0x77,0x11,0xbe,0x92,0x4f,0x24,0xc5,0x32,0x36,0x9d,0xcf,0xf3,0xa6,0xbb,0xac,
	0x5e,0x6c,0xa9,0x13,0x57,0x25,0xb5,0xe3,0xbd,0xa8,0x3a,0x01,0x05,0x59,0x2a,0x46
};


#define PRIME_MULT 1717

unsigned int str_hash(const char* str)  /* Hash: String to Key */
{
	unsigned int len = sizeof(str);
	unsigned int hash = len, i;


	for (i = 0; i != len; i++, str++) {
		hash ^= sTable[(*str + i) & 255];
		hash = hash * PRIME_MULT;
	}

	return hash % ringSize;
}

void printmenu()
{
	printf("CHORD> Enter a command - (c)reate: Create the chord network\n");
	printf("CHORD> Enter a command - (j)oin  : Join the chord network\n");
	printf("CHORD> Enter a command - (l)eave : Leave the chord network\n");
	printf("CHORD> Enter a command - (a)dd   : Add a file to the network\n");
	printf("CHORD> Enter a command - (d)elete: Delete a file to the network\n");
	printf("CHORD> Enter a command - (s)earch: File search and download\n");
	printf("CHORD> Enter a command - (f)inger: Show the finger table\n");
	printf("CHORD> Enter a command - (i)nfo  : Show the node information\n");
	printf("CHORD> Enter a command - (m)ute  : Toggle the silent mode\n");
	printf("CHORD> Enter a command - (h)elp  : Show the help message\n");
	printf("CHORD> Enter a command - (q)uit  : Quit the program\n");
	printf("CHORD> Enter your command ('help' for help message).\n");

	printf("CHORD> 메뉴를 선택하세요 : ");
}




int modIn(int modN, int targNum, int range1, int range2, int leftmode, int rightmode)
// leftmode, rightmode: 0 => range boundary not included, 1 => range boundary included   
{
	int result = 0;

	if (range1 == range2) {
		if ((leftmode == 0) || (rightmode == 0))
			return 0;
	}

	if (modPlus(ringSize, range1, 1) == range2) {
		if ((leftmode == 0) && (rightmode == 0))
			return 0;
	}

	if (leftmode == 0)
		range1 = modPlus(ringSize, range1, 1);
	if (rightmode == 0)
		range2 = modMinus(ringSize, range2, 1);

	if (range1 < range2) {
		if ((targNum >= range1) && (targNum <= range2))
			result = 1;
	}
	else if (range1 > range2) {
		if (((targNum >= range1) && (targNum < modN))
			|| ((targNum >= 0) && (targNum <= range2)))
			result = 1;
	}
	else if ((targNum == range1) && (targNum == range2))
		result = 1;

	return result;


}

int twoPow(int power)
{
	int i;
	int result = 1;

	if (power >= 0)
		for (i = 0; i < power; i++)
			result *= 2;
	else
		result = -1;

	return result;
}

int modMinus(int modN, int minuend, int subtrand)
{
	if (minuend - subtrand >= 0)
		return minuend - subtrand;
	else
		return (modN - subtrand) + minuend;
}

int modPlus(int modN, int addend1, int addend2)
{
	if (addend1 + addend2 < modN)
		return addend1 + addend2;
	else
		return (addend1 + addend2) - modN;
}

